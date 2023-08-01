#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
    int pipefd[2];
    char *cmd1[] = {"/bin/ls", "-l", NULL};
    char *cmd2[] = {"/usr/bin/wc", "-l", NULL};

    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    pid_t pid1, pid2;

    pid1 = fork();

    if (pid1 == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid1 == 0) {
        // First child process
        close(pipefd[0]); // Close the read end of the pipe in the child

        // Redirect stdout to write to the write end of the pipe
        if (dup2(pipefd[1], STDOUT_FILENO) == -1) {
            perror("dup2");
            exit(EXIT_FAILURE);
        }

        // Close the write end of the pipe in the child (since it's now duplicated as stdout)
        close(pipefd[1]);

        // Execute the first command
        execve(cmd1[0], cmd1, NULL);

        // execve() will only return if there was an error
        perror("execve");
        exit(EXIT_FAILURE);
    } else {
        pid2 = fork();

        if (pid2 == -1) {
            perror("fork");
            exit(EXIT_FAILURE);
        } else if (pid2 == 0) {
            // Second child process
            close(pipefd[1]); // Close the write end of the pipe in the child

            // Redirect stdin to read from the read end of the pipe
            if (dup2(pipefd[0], STDIN_FILENO) == -1) {
                perror("dup2");
                exit(EXIT_FAILURE);
            }

            // Close the read end of the pipe in the child (since it's now duplicated as stdin)
            close(pipefd[0]);

            // Execute the second command
            execve(cmd2[0], cmd2, NULL);

            // execve() will only return if there was an error
            perror("execve");
            exit(EXIT_FAILURE);
        } else {
            // Parent process
            close(pipefd[0]); // Close the read end of the pipe in the parent
            close(pipefd[1]); // Close the write end of the pipe in the parent

            // Wait for both child processes to finish
            int status;
            waitpid(pid1, &status, 0);
            waitpid(pid2, &status, 0);
        }
    }

    return 0;
}