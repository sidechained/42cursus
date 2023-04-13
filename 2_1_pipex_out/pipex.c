// PROBLEM: 2nd dup2 statement in execute_cmd1 + execute_cmd2 fails! WHY?!
// cmd1 is child process, cmd2 is parent process
// good ref: https://github.com/andrei-sergeich/pipex/tree/main/srcs_man

// cc -Wall -Werror -Wextra -Ilibft pipex.c libft/ft_strncmp.c libft/ft_split.c libft/ft_strjoin.c libft/ft_substr.c libft/ft_strlen.c -o pipex && ./pipex infile "ls -l" "wc -l" outfile

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
#define ERR_CMD "Command not found!"

// void	free_child(t_pipex *pipex)
// {
// 	int	i;

// 	i = 0;
// 	while (pipex->cmd_args[i])
// 	{
// 		free(pipex->cmd_args[i]);
// 		i++;
// 	}
// 	free(pipex->cmd_args);
// 	free(pipex->cmd);
// }

void	execute_cmd(char *cmd, char **env)
{
	char **split_cmd;
	char **paths;
	char *path;
	int i = 0;


	split_cmd = ft_split(cmd, ' ');
	while (ft_strncmp("PATH=", *env, 5))
		env++;
	paths = ft_split(*env + 5, ':');

	paths = NULL;
	// exit cleanly if command not found in path
	if (!paths)
	{
		// free_child();
		perror(ERR_CMD);
		exit(1);
	}

	while (paths[i])
	{
		path = ft_strjoin(paths[i], "/");
		path = ft_strjoin(path, split_cmd[0]);
		execve(path, &split_cmd[1], env);
		i++;
	}

	// how to free these paths when execution is successful?
}

void	execute_cmd1(int in_fd, char *cmd1, int *p, char **env)
{
	close(p[0]);
	dup2(in_fd, STDIN_FD);
	dup2(p[1], STDOUT_FD); // any print command executed here will output to pipe, NOT standard input!
	execute_cmd(cmd1, env);
}

void	execute_cmd2(char *outfile, char *cmd2, int *p, char **env)
{
	int out_fd;

	close(p[1]);
	dup2(p[0], STDIN_FD);
	out_fd = open(outfile, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (out_fd == -1)
	{
		printf("write error/n");
		return ;
	}
	dup2(out_fd, STDOUT_FD);  // any print command executed here will output to outfile, NOT standard input!
	execute_cmd(cmd2, env);
}

// void	free_parent()
// {
// 	int	i;
// 	close(infile);
// 	close(outfile);
// 	i = 0;
// 	while (pipex->cmd_paths[i])
// 	{
// 		free(pipex->cmd_paths[i]);
// 		i++;
// 	}
// 	free(pipex->cmd_paths);
// }

void	pipex(char *infile, char *cmd1, char *cmd2, char *outfile, char **env)
{
	int		p[2];
	int		pipe_result;
	pid_t	cmd1_pid;
	pid_t	cmd2_pid;
	int 	in_fd;

	pipe_result = pipe(p); // will make a pipe using the next two file descriptors (3, 4)
	if (pipe_result == -1)
	{
		printf("pipe error\n");
		return;
	}
	cmd1_pid = fork();
	if (cmd1_pid == 0)
	{
		printf("cmd1\n");
		in_fd = open(infile, O_RDONLY);
		if (in_fd == -1)
		{
			printf("read error/n");
			return ;
		}		
		execute_cmd1(in_fd, cmd1, p, env);
	}
	if (cmd1_pid == -1)
		printf("cmd1 fork error\n");
	cmd2_pid = fork();
	if (cmd2_pid == 0)
	{
		printf("cmd2\n");
		execute_cmd2(outfile, cmd2, p, env);
	}
	if (cmd2_pid == -1)
		printf("cmd2 fork error\n");
	// back in the parent process:
	close(p[0]);
	close(p[1]);
	waitpid(cmd1_pid, NULL, 0);
	waitpid(cmd2_pid, NULL, 0);
	printf("THEEND!\n");
	// free_parent();
}

int	main(int argc, char **argv, char **envp)
{
	if (argc == 5)
		pipex(argv[1], argv[2], argv[3], argv[4], envp);
	else
		printf("ERROR: wrong number of arguments!");
	return 0;
}