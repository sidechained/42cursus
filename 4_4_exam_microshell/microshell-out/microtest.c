#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int	main(int argc, char **argv, char **envp)
{
	char *cmd_array[4];

	(void)argc;
	(void)argv;
	cmd_array[0] = "/bin/echo";
	cmd_array[1] = "123";
	cmd_array[2] = "456";
	cmd_array[3] = NULL;

	pid_t p;
	p = fork();
	if (p == 0) // child
	{
		execve("/bin/echo", cmd_array, envp);
		exit(0);
	}
	else if (p > 0)
	{
		int status;
		wait(&status);
	}
}