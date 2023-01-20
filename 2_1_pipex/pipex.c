// PROBLEM: 2nd dup2 statement in execute_cmd1 + execute_cmd2 fails! WHY?!
// cmd1 is child process, cmd2 is parent process
// good ref: https://github.com/andrei-sergeich/pipex/tree/main/srcs_man

// ./pipex infile ``ls -l'' ``wc -l'' outfile
// ./pipex infile ``grep a1'' ``wc -w'' outfile

#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h> // open
#include <fcntl.h>	  // open
#include <stdlib.h>	  // malloc
#include <string.h>	  // strstr
#include <assert.h>	  // str_split
#include <sys/types.h>	// waitpid
#include <sys/wait.h>	// waitpid
#include "str_split.c"
#include "ft_substr.c"

#define STDIN_FD 0
#define STDOUT_FD 1

char **get_paths_from_env(char **env)
{
	char *path_key = "PATH";
	int path_key_len;
	char *path_str = NULL;
	char **paths;
	int i = 0;
	while (!path_str) // i.e. == NULL
	{
		path_str = strstr(env[i], path_key);
		i++;
	}
	path_key_len = strlen(path_key) + 1; // + 1 to omit '='
	path_str = ft_substr(path_str, path_key_len, strlen(path_str) - path_key_len);
	// adding extra colon delimiter to end of path_str
	// this prevents weird extra chars appearing on end of last path
	char path_str_colon[strlen(path_str) + 1];
	strcpy(path_str_colon, path_str);
	strcat(path_str_colon, ":");
	paths = str_split(path_str_colon, ':');
	return(paths);
}

void execute_cmd(char *cmd, char **env)
{
	printf("execute_cmd\n");
	char **split_cmd;
	char *cmd_progname;
	char *cmd_args;
	char **paths;
	int i = 0;
	split_cmd = str_split(cmd, ' ');
	cmd_progname = split_cmd[0];
	cmd_args = split_cmd[1];
	paths = get_paths_from_env(env);
	while (paths[i])
	{
		char new_path[strlen(paths[i]) + 1 + strlen(cmd_progname)];
		strcpy(new_path, paths[i]);
		strcat(new_path, "/");
		strcat(new_path, cmd_progname);		
		execve(cmd, &cmd_args, env);
		i++;
	}
}

void execute_cmd1(char *infile, char *cmd1, int *p, char **env)
{
	printf("execute_cmd1\n");
	int in_fd;
	in_fd = open(infile, O_RDONLY);
	if (in_fd == -1)
	{
		printf("read error/n");
		return;
	}
	// setup infile to pipe:
	dup2(in_fd, STDIN_FD);
	printf("ex1here1\n");	
	dup2(p[1], STDOUT_FD); // this is the problem!
	printf("ex1here2\n");
	close(p[0]); // close end of pipe we don't use
	close(in_fd);
	execute_cmd(cmd1, env);
}

void execute_cmd2(char *outfile, char *cmd2, int *p, char **env)
{
	printf("execute_cmd2 waiting...\n");
	int status;
	waitpid(-1, &status, 0); // wait for child process to finish
	printf("execute_cmd2 continues...\n");
	int out_fd = open(outfile, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (out_fd == -1)
	{
		printf("write error/n");
		return;
	}
	// setup pipe to outfile:
	dup2(p[0], STDIN_FD);
	printf("ex2here1\n");		
	dup2(out_fd, STDOUT_FD);
	printf("ex2here2\n");		
	close(p[1]);
	close(out_fd);
	execute_cmd(cmd2, env);
}

void pipex(char *infile, char *cmd1, char *cmd2, char *outfile, char **env)
{
	int p[2];
	int pipe_result;
	pid_t pid;
	pipe_result = pipe(p);
	if (pipe_result == -1)
	{
		printf("pipe error\n");
		return;
	}
	pid = fork();
	switch(pid) // 0 for child process, non-zero for parent process, -1 in case of error
	{
		case -1:
			printf("fork error\n");
			break;
		case 0:
			execute_cmd1(infile, cmd1, p, env);
			break;
		default:
			execute_cmd2(outfile, cmd2, p, env);
			break;
	}
}

int main(int argc, char **argv, char **envp)
{
	if (argc == 5)
		pipex(argv[1], argv[2], argv[3], argv[4], envp);
	else
		printf("ERROR: wrong number of arguments!");
	return 0;
}