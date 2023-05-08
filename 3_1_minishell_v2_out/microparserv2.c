// microparser v1a
// - take in a linked list of tokens, implement simple grammar for a simple command and pipe, return an ast
// cc -Wall -Werror -Wextra -Ilibft microparserv1a.c libft/ft_strncmp.c libft/ft_lstnew.c libft/ft_lstadd_back.c libft/ft_lstlast.c -o microparserv1a && ./microparserv1a "ls -l"

// pipe_sequence	: cmd_word 
// 				| pipe_sequence PIPE cmd_word

// cmd_word		: WORD

// understanding pipe_sequence
// can EITHER be
// a single command word
// OR
// another pipe sequence, followed by | followed by another command word
// "ls -l | wc -l"

// does this mean a cmd_word is a full command, not just its first word

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
	t_token *prev_token;
	t_node *ast;

	prev_token = NULL;
	while (tokens->type != T_END)
	{
		if (tokens->type == T_WORD)
		{
			if (!prev_token || prev_token->type != T_WORD)
			{
				ast = ft_newnode(R_SIMPLE_COMMAND, ft_lstnew(tokens->content));
			}
			else
			{
				ft_lstadd_back(&ast->content, ft_lstnew(tokens->content));
			}
		}
		prev_token = tokens;
		tokens = tokens->next;
	}
	return (ast);
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

int main(int argc, char **argv)
{
	t_token	*tokens;
	t_node *ast;

	argc--;
	argv++;
	tokens = ms_tokenizer(*argv);
	ast = ms_parser(tokens);
	print_ast(ast);
}
