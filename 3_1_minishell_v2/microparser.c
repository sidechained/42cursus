// microparser v1
// - take in a linked list of tokens, implement simple grammar for a simple command and pipe, return an ast
// cc -Wall -Werror -Wextra -Ilibft microparser.c libft/ft_strncmp.c -o microparser && ./microparser "ls -l"

// pipe_sequence	: cmd_word 
// 				| pipe_sequence PIPE cmd_word

// cmd_word		: WORD

#include "microlexer.c"

typedef enum e_rules
{
	R_PIPE_SEQUENCE = 100,
	R_SIMPLE_COMMAND,
}	t_rules;

typedef enum e_ast_types
{
	A_CMD = 0,
	A_PIPE,
}	t_ast_types;

typedef struct s_node
{
	int				type;
	struct s_list	*content;
	struct s_node	*left;
	struct s_node	*right;
}					t_node;

t_node	*ft_newnode(int type, void *content)
{
	t_node		*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (0);
	node->type = type;
	node->content = content;
	node->left = NULL;
	node->right = NULL;	
	return (node);
}

t_node *ms_parser(t_token *tokens)
{
	int prev_word;
	t_list *simple_command;
	t_node *ast;

	prev_word = 0;
	while (tokens->type != T_END)
	{
		if (tokens->type == T_WORD)
		{
			if (prev_word == 0)
			{
				// make a new linked list representing a simple_command, where the content is the T_WORD's content i.e. "ls"
				simple_command = ft_lstnew(tokens->content);
				// create a new node in the ast, using the new node simple_command as it's content
				ast = ft_newnode(R_SIMPLE_COMMAND, simple_command);
				prev_word = 1;
			}
			else
			{
				// if the token continues a previous command i.e. "-l", just add content as another element in the linked list
				ft_lstadd_back(&simple_command, ft_lstnew(tokens->content));
			}
		}
		else
		{
			// null terminate the simple_command lst? don't need to as new lsts nexts are initialised as NULL
			prev_word = 0;
		}
		tokens=tokens->next;
	}
	return(ast);
}

void print_simple_command(t_list *content) // rename content to something else to avoid confusion!?
{
	if (content == NULL)
		return ;
	printf("%s ", (char *)(content->content));
	print_simple_command(content->next);
}

void print_ast(t_node *node)
{
	if (node == NULL)
		return ;
	print_ast(node->left);
	print_ast(node->right);
	if (node->type == R_SIMPLE_COMMAND)
	{
		print_simple_command(node->content);
	}
}

// line = first argument of main (in quotes) e.g. "he >> ho || ha"
int main(int argc, char **argv)
{
	t_token	*tokens;
	t_node *ast;

	argc--;
	argv++;
	tokens = ms_tokenizer(*argv);
	// while(all)
	// {
	// 	printf("content: '%s'\n", all->value);
	// 	printf("type: %s\n", tokentype_lookup(all->type));
	// 	all=all->next;
	// }

	// should be a single node in the tree containing a command
	ast = ms_parser(tokens);
	print_ast(ast);
}

