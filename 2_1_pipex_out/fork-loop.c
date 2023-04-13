#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

void	redir ()
{
	pid_t	pid;

	pid = fork();
	if (pid)
	{
		printf("child\n");
		waitpid(pid, NULL, 0);
	}
	else
	{
		printf("parent\n");
		exit(1);
	}
}

int	main ()
{
	int ac;
	int i;

	ac = 3;

	redir();
	i = 0;
	while (i++ < ac)
		redir();
	return (1);
}