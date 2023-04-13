// interpreter only
// cc -Wall -Werror -Wextra -Ilibft interpreter_only.c libft/ft_strjoin.c libft/ft_split.c libft/ft_substr.c libft/ft_strlen.c libft/ft_strncmp.c -o interpreter_only && ./interpreter_only

// MAIN Q: why don't we see a result?

// - manually build an AST, using t_node struct
// - then traverse the AST, forking and executing the commands in subshells
// - integrate pipex bonus
// 	-- everytime we encounter a pipe (or the root node) in the tree, we
//		-- fork off a child process, setup read end of the pipe
//		-- in parent process, setup write end of the pipe
// the root node is treated like a pipe, so that there is a watchover process to exit to
// this way things should work nicely even when there is no pipe in the ast
// we can test this by returning different nodes from the manually_make_tree function e.g.
// -- node[4]: if marked as root, should execute

// clues
// if (node->reduc == R_FILENAME)
//		node->right->type = A_FILE;
// if (node->left exists && node->left->type == A_CMD)
// 		node->left->type = A_PARAM;
// if (node->right exists && node->right->type == A_CMD)
// 		node->right->type = A_PARAM;

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <string.h>
#include "libft.h"

#define STDIN_FD 0
#define STDOUT_FD 1
#define STDERR_FD 2

#define ERR_CMD "Command not found!"
#define ERR_READ "Read error!"
#define ERR_WRITE "Write error!"
#define ERR_PIPE "Pipe error!"
#define ERR_FORK "Fork error!"
#define ERR_HEREDOC "Heredoc error!"

#define ROOT -2

// ast types begin from 0 and represent the types of the orange nodes in the diagram
typedef enum e_ast_types
{
	A_CMD = 0,		// 
	A_RED_TO,		// >
	A_RED_FROM,		// <
	A_DLESS,		// <<
	A_DGREAT,		// >>
	A_PIPE,			// |
	A_PARAM,		// ? argument of a command?
	A_FILE,			// ? fd or filename?
	A_LIMITER		// ? for heredoc, the limiter that wil make it end
}	t_ast_types;

// rules types begin from 100 and represent the types of the black nodes in the diagram
typedef enum e_rules
{
	R_PIPE_SEQUENCE = 100,
	R_CMD_WORD,
	R_IO_FILE,
	R_FILENAME,
	R_IO_HERE,
	R_HERE_END
}	t_rules;

typedef struct s_node
{
	int				type;	// list of types defined in t_ast_types
	char			*data;	// the content i.e. for command the command name i.e. echo
	struct s_node	*left;	// the node to the left
	struct s_node	*right;	// the node to the right
	struct s_node	*next;	// next is the way we traverse the tree?!? unused so far
}					t_node;

void	execute_cmd2(char **paths, char **cmd_args, char **env)
{
	int		j;
	char	*path_cmd;

	j = 0;
	while (paths[j])
	{
		path_cmd = ft_strjoin(ft_strjoin(paths[j++], "/"), cmd_args[0]);
		if (access(path_cmd, 0) == 0)
		{
			free(paths);
			// fprintf(stderr, "%s\n", path_cmd);
			if (execve(path_cmd, cmd_args, env) == -1)
			{
				perror("Execution error");
				exit(127);
			}
		}
		free(path_cmd);
	}
}

void	execute_cmd(char *cmd_args_str, char **env)
{
	char	**paths;
	char	**cmd_args;

	while (ft_strncmp("PATH=", *env, 5))
		env++;
	paths = ft_split(*env + 5, ':');
	if (!paths)
	{
		perror(ERR_CMD);
		exit(1);
	}
	cmd_args = ft_split(cmd_args_str, ' ');
	execute_cmd2(paths, cmd_args, env);
}

// pid == 0 is child, pid > 0 is parent, ip pipe goes child [out] -> parent [in]
void	pipe_to_parent(char *cmd, char **env)
{
	pid_t	pid;
	int		io_fd[2];

	printf("%s\n", cmd);
	pipe(io_fd);
	pid = fork();
	if (pid == -1)
		perror(ERR_FORK);
	if (pid == 0)
	{
		close(io_fd[0]);
		dup2(io_fd[1], STDOUT_FD);
		execute_cmd(cmd, env);
		perror(ERR_CMD);
		exit(127);
	}
	else
	{
		close(io_fd[1]);
		dup2(io_fd[0], STDIN_FD);
		waitpid(pid, NULL, 0);
	}
}

void visit_and_execute(t_node *node, char **env)
{
	static char *cmd = NULL; // represents command and arguments separated by single spaces

	if (!node)
		return ;
	visit_and_execute(node->left, env);
	visit_and_execute(node->right, env);

	if (node->type == A_PIPE || node->type == ROOT)
	{
		// printf("PIPE!\n");
		pipe_to_parent(cmd, env);
		free(node); // cut off this branch so that it isn't executed again i.e. stop browsing the left branch if we encounter another pipe
		cmd = NULL;
	}
	if (node->type == A_CMD)
	{
		if (!cmd)
		{
			cmd = node->data;
		}
		else
		{
			cmd = ft_strjoin(cmd, " ");
			cmd = ft_strjoin(cmd, node->data);
		}	
	}
}

t_node *manually_make_tree()
{
	// manually make a tree for this image https://github.com/twagger/minishell/raw/master/doc/img/post_order-real.png
	// travese the nodes from the root downwards, following the left branch, numbering as we go, to achieve the following:
	// (where B are the black nodes, O the orange nodes)
	// 00 B pipe sequence
	// 01 O pipe
	// 02 B pipe sequence
	// 03 O pipe
	// 04 B cmd
	// 05 O ls
	// 06 O -l
	// 07 B cmd
	// 08 O grep
	// 09 O ..
	// 10 B cmd
	// 11 B cmd
	// 12 O wc
	// 13 O -l
	// 14 B redir
	// 15 O >
	// 16 O File
	
	t_node *nodes[17];
	int i;

	i = 0;
	while(i < 18)
	{
		nodes[i] = malloc(sizeof(t_node));
		i++;
	}

	nodes[0]->type = R_PIPE_SEQUENCE; // formerly R_PIPE_SEQUENCE
	nodes[1]->type = A_PIPE;
	nodes[1]->data = "|";	
	nodes[2]->type = R_PIPE_SEQUENCE;
	nodes[3]->type = A_PIPE;
	nodes[3]->data = "|";	
	nodes[4]->type = R_CMD_WORD;	
	nodes[5]->type = A_CMD;
	nodes[5]->data = "ls";	
	nodes[6]->type = A_CMD;
	nodes[6]->data = "-l";	
	nodes[7]->type = R_CMD_WORD;	
	nodes[8]->type = A_CMD;	
	nodes[8]->data = "grep";	
	nodes[9]->type = A_CMD;
	nodes[9]->data = "..";		
	nodes[10]->type = R_CMD_WORD;	
	nodes[11]->type = R_CMD_WORD;	
	nodes[12]->type = A_CMD;
	nodes[12]->data = "wc";		
	nodes[13]->type = A_CMD;
	nodes[13]->data = "-l";	
	nodes[14]->type = R_IO_FILE;	
	nodes[15]->type = A_RED_TO;
	nodes[15]->data = ">";			
	nodes[16]->type = A_FILE;
	nodes[16]->data = "File";	

	// define left and right nodes
	nodes[0]->left = nodes[1];
	nodes[0]->right = nodes[10];
	nodes[1]->left = nodes[2];
	nodes[2]->left = nodes[3];
	nodes[2]->right = nodes[7];
	nodes[3]->left = nodes[4];
	nodes[4]->left = nodes[5];
	nodes[4]->right = nodes[6];
	nodes[7]->left = nodes[8];
	nodes[7]->right = nodes[9];
	nodes[10]->left = nodes[11];
	nodes[10]->right = nodes[14];
	nodes[11]->left = nodes[12];
	nodes[11]->right = nodes[13];
	nodes[14]->left = nodes[15];
	nodes[14]->right = nodes[16];

	// explicitly set the type of the root node as ROOT so that executing happens in subshell, not main process
	// traversal shall begin from the node that is returned (treated as root)
	// nodes[0]->type = ROOT; 
	// return (nodes[0]);

	// nodes[2]->type = ROOT;
	// return (nodes[2]);	

	nodes[4]->type = ROOT;
	return (nodes[4]);	

	// this hangs, why?!? it's normal, shell does it too if it's the only command
	// nodes[10]->type = ROOT;
	// return (nodes[10]);	

}

int main(int argc, char **argv, char **envp)
{
	t_node *root_node;

	(void)argc;
	(void)argv;

	root_node = manually_make_tree();
	visit_and_execute(root_node, envp);

	return (0);
}

