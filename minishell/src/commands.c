// gcc -Wall -Werror -Wextra commands.c builtins.c ../libft/ft_substr.c ../libft/str_split.c && ./a.out

#include "commands.h"
#include "builtins.h"

char	*ft_substr(char const *s, unsigned int start, unsigned int len);
char 	**str_split(char *a_str, const char a_delim);

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

void run_executable(char *command, int num_args, char *args[], char **envp)
{
	// printf("run_executable:\n%s ", command);
	// int k = 0;
	// while(k < num_args)
	// {
	// 	printf("%s", args[k]);
	// 	k++;
	// }	
	// printf("\n");
	// char **paths = get_paths_from_env(envp);
	// // combine command + args, because execve 2nd argument needs it that way!
	// char *command_plus_args[num_args + 1];
	// int j = 0;
	// while(j < num_args + 1)
	// {
	// 	if (j == 0)
	// 	{
	// 		command_plus_args[j] = command;
	// 	}
	// 	else
	// 	{
	// 		command_plus_args[j] = args[j-1];
	// 	}
	// 	j++;
	// }
	// j = 0;
	// while(j < num_args + 1)
	// {
	// 	printf("j: %i, cpa: %s\n", j, command_plus_args[j]);
	// 	j++;
	// }	
	// int i = 0;
	// while (paths[i])
	// {
	// 	char new_path[strlen(paths[i]) + 1 + strlen(command)];
	// 	strcpy(new_path, paths[i]);
	// 	strcat(new_path, "/");
	// 	strcat(new_path, command);
	// 	printf("trying:%s\n", new_path);
	// 	execve(new_path, command_plus_args, envp);
	// 	// break when successful?
	// 	i++;
	// }
	(void)num_args;
	(void)args;
	(void)command;
	char *command2 = "/bin/ls";
	char *command_plus_args[2] = {"/bin/ls", "-l"};
	int status = execve(command2, command_plus_args, envp);
	printf("%i\n", status);
}

int is_builtin(char *command)
{
	if (strcmp(command, "echo") == 0
		|| strcmp(command, "cd") == 0
		|| strcmp(command, "pwd") == 0
		|| strcmp(command, "export") == 0
		|| strcmp(command, "unset") == 0
		|| strcmp(command, "env") == 0
		|| strcmp(command, "exit") == 0)
		return 1;
	else
		return 0;
}

int main(int argc, char **argv, char**envp)
{
	(void)argc;
	(void)argv;
	//(void)envp;

	struct element elements[NUM_ELEMENTS];
	elements[0].type = COMMAND;
	elements[0].str = "echo";

	elements[1].type = ARGUMENT;
	elements[1].str = "one";

	elements[2].type = ARGUMENT;	
	elements[2].str = "two";

	elements[3].type = COMMAND;
	elements[3].str = "ls";
	
	elements[4].type = ARGUMENT;
	elements[4].str = "-l";
	
	elements[5].type = COMMAND;
	elements[5].str = "mkdir";
	
	elements[6].type = ARGUMENT;
	elements[6].str = "fuckwarbler";

	int i = 0;
	while(i < NUM_ELEMENTS)
	{
		if (elements[i].type == COMMAND)
		{
			char *command = elements[i].str;
			int num_args = 0;
			while(elements[i + num_args + 1].type == ARGUMENT)
				num_args++;
			char *args[num_args + 1];
			int j = 0;
			while(j < num_args)
			{
				args[j] = elements[i + j + 1].str;
				j++;
			}
			args[j] = NULL;
			j = 0;
			// printf("command: %s\n", command);
			while(args[j])
			{
				// printf("args: %s\n", args[j]);
				j++;
			}
			// execute the command
			if(is_builtin(command))
			{
				printf("run_builtin:\n");
				run_builtin(command, num_args, args, envp);				
			}
			else
			{
				run_executable(command, num_args, args, envp);
			}
		}
		i++;
	}
}