
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

// cc -Wall -Werror -Wextra -Ilibft pipex.c -o pipex && ./pipex infile "ls -l" "wc -l" outfile

#define STDIN_FD 0
#define STDOUT_FD 1

void execute_cmd1(int *p)
{
	int in_fd;

	close(p[0]); // close input end of pipe (that we don't use)
	in_fd = open("infile", O_RDONLY);
	dup2(in_fd, STDIN_FD); // swap default STD_IN for our infile descriptor
	close(in_fd); // can we close this here?
	dup2(p[1], STDOUT_FD); // swap out the end of the pipe for STDOUT
	printf("here1!");
}

void execute_cmd2(int *p)
{
	int	status;
	int out_fd;

	waitpid(-1, &status, 0); // wait for child process to finish
	close(p[1]); // close output end of the pipe (that we don't use)
	dup2(p[0], STDIN_FD); // swap default STD_IN for our pipe output from other process
	out_fd = open("outfile", O_CREAT | O_RDWR | O_TRUNC, 0644);
	close(out_fd); // can we close this here?
	dup2(out_fd, STDOUT_FD); // swap default STD_OUT for our outfile descriptor
	printf("here2!");
}

void pipex()
{
	int		p[2];
	int		pipe_result;
	pid_t	pid;

	pipe_result = pipe(p);
	pipe_result = pipe(p);
	if (pipe_result == -1)
	{
		printf("pipe error\n");
		return;
	}	
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