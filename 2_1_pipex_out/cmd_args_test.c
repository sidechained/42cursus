#include <stdio.h>
#include "libft.h"

int	main()
{
	char *cmd;
	char **cmd_args;

	cmd = ft_strdup("ls   -l -a");
	cmd_args = ft_split(cmd, ' ');
	cmd = cmd_args[0];
	cmd_args++;

	printf("cmd: \"%s\"\n", cmd);

	printf("cmd_args: \"%s\" \"%s\"\n", cmd_args[0], cmd_args[1]);
}