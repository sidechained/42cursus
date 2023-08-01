// malloc, free, write, close, fork, waitpid, signal, kill, exit, chdir, execve, dup, dup2, pipe, strcmp, strncmp
// ./microshell /bin/ls "|" /usr/bin/grep microshell ";" /bin/echo i love my microshell
// | - pipe output of one command to another
// | will always fall between two commands
// ; - execute the commands sequentially from left to right, regardless of the success or failure of any preceding command

// first arg is command
// second arg if not "|" or ";" is an argument to the command
// when | or ; or end encounter, stop building the command array

// need to handle case where input AND output are from a pipe

// TODO: cd
// TODO: how to

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/wait.h>

void	print_cmd_array(char *cmd_array[10])
{
	int i;
	i = 0;
	printf("\"");
	while(cmd_array[i])
	{
		printf("%s", cmd_array[i]);
		if (cmd_array[i+1] != NULL)
			printf(" ");
		i++;
	}
	printf("\"\n");	
}
	
void	builtin_cd()
{
	printf("CD\n");
}

void	exec_in_subprocess(char *cmd_array[10], char **envp, bool op_to_p, bool ip_from_p, int *io)
{
	printf("%i %i\n", op_to_p, ip_from_p);
	if (strcmp(cmd_array[0], "cd") == 0)
	{
		builtin_cd();
		return;
	}
	pid_t p;
	int orig_stdin = dup(STDIN_FILENO);
	int orig_stdout = dup(STDOUT_FILENO);
	p = fork();
	if (p < 0)
	{
		printf("ERROR\n");
		return;
	}
	if (p == 0) // child
	{
		if (op_to_p == true)
		{
			write(2, "op\n", 3);
			// close(io[0]);
			dup2(io[1], STDOUT_FILENO);
			// close(io[1]);
		}
		if (ip_from_p == true)
		{
			write(2, "ip\n", 3);
			// close(io[1]);
			dup2(io[0], STDIN_FILENO);
			// close(io[0]);
		}		
		execve(cmd_array[0], cmd_array, envp);
		printf("COMMAND NOT FOUND!\n");
		exit(0);
	}
	else
	{
		int status;
		waitpid(p, &status, 0);
		if (op_to_p == true)
		{
			close(io[1]);
			dup2(orig_stdout, 1);
		}
		if (ip_from_p == true)
		{
			close(io[0]);
			dup2(orig_stdin, 0);
		}
	}
}

int main(int argc, char **argv, char **envp)
{
	char *cmd_array[10];
	int i;
	bool ip_from_p;
	int io[2];

	ip_from_p = false;
	argv++;
	i = 0;
	while(*argv)
	{
		if (strcmp(*argv, "|") == 0)
		{
			cmd_array[i] = NULL;
			i = 0;
			pipe(io);
			printf("PIPE\n");
			// at pipe output will always be to pipe, input may or may not be from pipe
			exec_in_subprocess(cmd_array, envp, true, ip_from_p, io);
			ip_from_p = true; // set for NEXT pipe, not this one
		}
		// else if (strcmp(*argv, ";") == 0)
		// {
		// 	cmd_array[i] = NULL;
		// 	i = 0;
		// 	printf("COMMA\n");
		// 	// at comma output will never be to pipe, but input can be from pipe
		// 	exec_in_subprocess(cmd_array, envp, false, ip_from_p, NULL);
		// 	ip_from_p = false;
		// }
		else
		{
			cmd_array[i] = *argv;
			i++;
		}
		argv++;
	}
	cmd_array[i] = NULL;
	// at end output will never be to pipe, but input can be from pipe
	exec_in_subprocess(cmd_array, envp, false, ip_from_p, io);
}