
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h> // open
#include <fcntl.h>	  // open
#include <stdlib.h>	  // malloc
#include <string.h>	  // ft_strstr
#include <assert.h>	  // str_split
#include <sys/types.h>	// waitpid
#include <sys/wait.h>	// waitpid
#include "libft.h"

#define STDIN_FD 0
#define STDOUT_FD 1

void execute_cmd1(int *p)
{
	// stdin -> pipe_out

	int in_fd;

	printf("execute_cmd1\n");

	close(p[0]); // close input end of pipe (that we don't use)

	in_fd = open("infile", O_RDONLY);
	dup2(in_fd, STDIN_FD); // swap default STD_IN for our infile descriptor
	close(in_fd); // can we close this here?
	printf("ex1here1\n");
	dup2(p[1], STDOUT_FD); // swap out the end of the pipe for STDOUT
	printf("ex1here2\n");
	printf("end of execute_cmd1\n");
}

void execute_cmd2(int *p)
{
	// pipe in -> stdout
	int	status;
	int out_fd;

	printf("execute_cmd2 waiting...\n");
	waitpid(-1, &status, 0); // wait for child process to finish
	printf("execute_cmd2 continues...\n");

	close(p[1]); // close output end of the pipe (that we don't use)

	dup2(p[0], STDIN_FD); // swap default STD_IN for our pipe output from other process
	printf("ex2here1\n");

	out_fd = open("outfile", O_CREAT | O_RDWR | O_TRUNC, 0644);
	close(out_fd); // can we close this here?

	dup2(out_fd, STDOUT_FD); // swap default STD_OUT for our outfile descriptor

	printf("ex2here2\n");
	printf("end of execute_cmd2\n");
}

void pipex()
{
	int		p[2];
	// int		pipe_result;
	pid_t	pid;

	// pipe_result = pipe(p);
	pid = fork();
	if (pid == 0)
		execute_cmd1(p);
	if (pid > 0)
		execute_cmd2(p);
}

int main()
{
	pipex();
	return (0);
}