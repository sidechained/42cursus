// implement LR SHIFT REDUCE parser
// - scans and parses the input text in one forward pass over the text
// - builds up the parse tree incrementally, bottom up, and left to right, without guessing or backtracking
// Uses SHIFT REDUCE approach:
// -- A SHIFT step advances in the input stream by one symbol. That shifted symbol becomes a new single-node parse tree.
// -- A REDUCE step applies a completed grammar rule to some of the recent parse trees, joining them together as one tree with a new root symbol.

// in this grammar there are only two correct forms
// 1. a single command or 2. commands joined by pipes

// grammar:
// pipe_sequence	: cmd_word 
// 				| pipe_sequence PIPE cmd_word
// 				;
// cmd_word		: WORD
// 				;

// Q: https://unix.stackexchange.com/questions/270275/what-is-the-difference-between-token-identifier-word-and-name

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

t_node *create_cmd_word_node(char *content)
{
	t_node *cmd_word_node;

	cmd_word_node = (t_node *)malloc(sizeof(t_node));
	cmd_word_node->type = A_CMD_WORD;
	cmd_word_node->content = content;
	// left and right are null
	return (cmd_word_node);
}

t_node *create_pipe_sequence_node(void)
{
	t_node *pipe_sequence_node;

	pipe_sequence_node = (t_node *)malloc(sizeof(t_node));
	pipe_sequence_node->type = A_PIPE_SEQUENCE;
	// content is null
	return (pipe_sequence_node);
}

t_node *parse_lr_shift_reduce(t_token *tokens)
{
	t_node *root_node;
	t_node *pipe_node;

	while(tokens->type != T_END)
	{
		if (tokens->type == T_WORD) // SHIFT
		{
			root_node = create_cmd_word_node(tokens->content);
			tokens = tokens->next;
		}
		if (tokens->type == T_PIPE) // REDUCE
		{
			pipe_node = create_pipe_sequence_node();
			if (root_node->type == A_CMD_WORD)
			// check prev created node is type A_CMD_WORD, if so link to left branch of pipe
			{
				pipe_node->left = root_node;
				tokens = tokens->next;
				if (tokens->type == T_WORD)
				// check next token is type T_WORD, if so create next node and link to right branch of pipe
				{
					pipe_node->right = create_cmd_word_node(tokens->content);
					tokens = tokens->next;
					root_node = pipe_node; // pipe is complete, so set pipe node to root
				}
				else
				{
					return (NULL);
				}
			}
			else
			{
				printf("hhh\n");
				return (NULL);
			}
		}
	}
	return (root_node);
}

t_token *manually_tokenise()
{
	t_token *tokens;
	tokens = NULL;
	ft_tokenadd_back(&tokens, ft_newtoken("ls", T_WORD));
	ft_tokenadd_back(&tokens, ft_newtoken("|", T_PIPE));
	ft_tokenadd_back(&tokens, ft_newtoken("wc", T_WORD));
	// ft_tokenadd_back(&tokens, ft_newtoken("|", T_PIPE));
	// ft_tokenadd_back(&tokens, ft_newtoken("wc", T_WORD));
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
	ast = parse_lr_shift_reduce(tokens);
	if (!ast)
	{
		printf("syntax error\n");
		return (-1);
	}
	print_ast(ast);
	printf("done!");
}