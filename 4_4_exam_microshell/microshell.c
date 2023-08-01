#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <stdio.h>

// cc -Wall -Werror -Wextra microshell.c -o microshell

// how does ; work in bash? commands execute sequentially from left to right

// do we need to check if forks error and issue fatal warning?

// TESTS

// ./microshell
// (no args should exit cleanly)

// single commands:
// ./microshell /bin/ls
// ./microshell ls
// (should fail - though in some cases it has worked!)
// ./microshell test
// (error: cannot execute test)

// single commands (cd):
// ./microshell cd
// (error: cd: bad arguments) 
// ./microshell cd .. ..
// (error: cd: bad arguments)
// ./microshell cd ..
// (exit cleanly, can't check without semicolon)
// ./microshell cd /tmp

// single commands (cd) with semicolon:
// ./microshell cd .. ; /bin/ls
// ./microshell cd /tmp ; /bin/ls
// FAIL: (dir does not change for both of these)

// semicolons:
// ./microshell /bin/ls ; /bin/echo 1 2 3 ; /bin/ls ; /bin/echo 4 5 6

// pipes:
// ./microshell /bin/ls | /bin/wc
// ./microshell /bin/ls | grep micro | /bin/wc -l
// ./microshell /bin/ls | wc | grep 0

// pipes and semicolons:
// ./microshell /bin/ls "|" /usr/bin/grep microshell ";" /bin/echo i love my microshell

// long:
// ./microshell /bin/ls | wc | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0 | grep 0

// edge cases
// ./microshell ls | ls
// FAIL: why does last one of these actually print output?
// ./microshell ls ; ls ; ls
// FAIL: why do last two of these actually print output?
// ./microshell /bin/ls | /bin/ls
// (works as it should, just printing one of the ls's)
// ./microshell /bin/ls | cd .. | /bin/ls
// (cd has not effect here, but I don't think this is tested)

// print str char by char, then arg char by char if exists
void ft_putstr(char *str, char *arg)
{
	while (*str)
		write(STDERR_FILENO, str++, 1);
	if (arg)
		while(*arg)
			write(STDERR_FILENO, arg++, 1);
	write(STDERR_FILENO, "\n", 1);
}

// we pass in tmp_fd, which can be stdin OR input from pipe
void ft_execute(char *argv[], int i, int tmp_fd, char **env)
{
	argv[i] = NULL;
	// redirect stdin to use tmp_fd
	dup2(tmp_fd, STDIN_FILENO);
	// stdin is now tmp_fd, so we can close tmp_fd
	close(tmp_fd);
	execve(argv[0], argv, env);
	ft_putstr("error: cannot execute ", argv[0]);
}

int	main(int argc, char **argv, char **env)
{
	int fd[2];
	int tmp_fd;
	int i;

	i = 0;
	(void)argc;
	argv++;
	// duplicates stdin fd and assign to variable tmp_fd
	tmp_fd = dup(STDIN_FILENO);
	while(argv[i])
	{
		// if not ; or |, advance index
		while (argv[i] && strcmp(argv[i], ";") && strcmp(argv[i], "|"))
			i++;
		if (strcmp(argv[0], "cd") == 0)
		{
			if (i != 2)
				ft_putstr("error: cd: bad arguments", NULL);
			else if (chdir(argv[1]) != 0)
				ft_putstr("error: cd: cannot change directory to ", argv[1]);
		}
		// if we are at end or encounter ;, exec command from 0 to i
		else if (argv[i] == NULL || strcmp(argv[i], ";") == 0)
		{
			if (fork() == 0)
			{
				ft_execute(argv, i, tmp_fd, env);
			//	break ;
			}
			else
			{
				close(tmp_fd);
				waitpid(-1, NULL, WUNTRACED);
				// duplicates stdin fd and assign to variable tmp_fd
				// i.e. make sure next command takes from stdin
				tmp_fd = dup(STDIN_FILENO);
			}
		}
		// if we encounter '|', setup pipe and exec command from 0 to i
		else if(strcmp(argv[i], "|") == 0)
		{
			if (pipe(fd))
			{
				ft_putstr("error: fatal", argv[1]);
				break ;
			}
			if (fork() == 0)
			{
				dup2(fd[1], STDOUT_FILENO);
				close(fd[0]);
				close(fd[1]);
				ft_execute(argv, i, tmp_fd, env);
			//	break ;
			}
			else
			{
				close(fd[1]);
				close(tmp_fd);
				waitpid(-1, NULL, WUNTRACED);
				tmp_fd = fd[0];
			}
		}
		// when should this occur?
		if (argv[i] != NULL)
		{
			printf("back\n");
			// point start to current position + 1 and set index to 0
			argv = &argv[i + 1];
			i = 0;
		}
	}
	close(tmp_fd);
	return (0);
}
