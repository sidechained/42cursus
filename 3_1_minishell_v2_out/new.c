#include <stdio.h>
#include <stdlib.h>
// #include "libft.h"

typedef enum e_token_types
{
	T_END = -2,
	T_WORD = 0,
	T_PIPE	
}	t_token_types;

typedef enum e_ast_types
{
	A_CMD_WORD = 0,
	A_PIPE_SEQUENCE,
}	t_ast_types;

typedef struct s_token
{
	int				type;
	char			*content;
	struct s_token	*prev;
	struct s_token	*next;
}					t_token;

typedef struct s_node
{
	int				type; // A_CMD_WORD or A_PIPE_SEQUENCE
	struct s_node	*left; // only relevant for A_PIPE_SEQUENCE
	struct s_node	*right; // only relevant for A_PIPE_SEQUENCE
	char			*content; // only relevant for A_CMD
}					t_node;

void	ft_tokenadd_back(t_token **lst, t_token *new)
{
	t_token	*current;

	if (!(*lst))
	{
		(*lst) = new;
		return ;
	}
	current = (*lst);
	while (current->next != 0)
	{
		current = current->next;
	}
	current->next = new;
	current->next->prev = current; // enable ability to look back
}

t_token	*ft_newtoken(void *content, int type)
{
	t_token		*re;

	re = (t_token *)malloc(sizeof(t_token));
	if (!re)
		return (0);
	re->content = content;
	re->type = type;
	re->next = NULL;
	return (re);
}

t_node *create_cmd_node(char *content)
{
	t_node *cmd_node;

	cmd_node = (t_node *)malloc(sizeof(t_node));
	cmd_node->type = A_CMD_WORD;
	cmd_node->content = content;
	// left and right are null
	return (cmd_node);
}

t_node *create_pipe_node(t_token *tokens, t_node *root_node)
{
	t_node *pipe_node;

	if (root_node->type != A_CMD_WORD && root_node->type != A_PIPE_SEQUENCE)
		return(NULL);
	if (tokens->next->type != T_WORD)
		return(NULL);
	pipe_node = (t_node *)malloc(sizeof(t_node));
	pipe_node->type = A_PIPE_SEQUENCE;
	// content is null
	pipe_node->left = root_node;
	// 3.
	tokens->tokens->next;
	pipe_node->right = create_cmd_node(tokens->content);
	tokens->tokens->next;
	return (pipe_node);	
}

t_node *parse();
{
	t_node *root_node;

	while(tokens->type != T_END)
	{
		// switch case here?
		if (token->type == T_WORD)
		{
			root_node = create_cmd_node(tokens->content);
			tokens->tokens->next; // can be done in function?
		}
		if (token->type == T_PIPE)
		{
			root_node = create_pipe_node(tokens, root_node);
			tokens->tokens->next; // can be done in function?
		}
	}
	return (root_node);
}

t_token *manually_tokenise(t_token *tokens)
{
	t_token *tokens;
	tokens = NULL;
	ft_tokenadd_back(&tokens, ft_newtoken("ls", T_WORD));
	ft_tokenadd_back(&tokens, ft_newtoken("|", T_PIPE));
	ft_tokenadd_back(&tokens, ft_newtoken("wc", T_WORD));
	ft_tokenadd_back(&tokens, ft_newtoken("|", T_PIPE));
	ft_tokenadd_back(&tokens, ft_newtoken("wc", T_WORD));
	ft_tokenadd_back(&tokens, ft_newtoken(NULL, T_END));
	return (tokens);
}

void print_ast(t_node *ast)
{
	if (ast == NULL)
		return ;
	print_ast(ast->left);
	print_ast(ast->right);
	if (ast->type == A_CMD_WORD)
	{
		printf("%s\n", ast->content);
	}
}

int main()
{
	t_token *tokens;
	t_node *ast;

	tokens = manually_tokenise();
	ast = parse(tokens);
	if (!ast)
	{
		printf("syntax error\n");
		return (-1);
	}
	print_ast(ast);
	printf("done!");
}