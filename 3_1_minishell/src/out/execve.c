// simple execve test
#include <unistd.h>

int main(int argc, char **argv, char**envp)
{
	(void)argc;
	(void)argv;
	char *command = "/usr/bin/man";
	char *args[3] = {command, "echo", NULL};
	execve(command, args, envp);
	return 0;
}
