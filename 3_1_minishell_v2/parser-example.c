// https://unix.stackexchange.com/questions/270275/what-is-the-difference-between-token-identifier-word-and-name

// building the AST, example

// Q: left hand side of pipe may be either A_CMD_WORD or A_PIPE_SEQUENCE and these will be different struct types, how do we handle that?
// Q: how do we know what to link on left and right, programatically?

// implementing this grammar

// pipe_sequence	: cmd_word 
// 				| pipe_sequence PIPE cmd_word
// 				;
// cmd_word		: WORD
// 				;

// using this command

// ls | wc | wc

// step by step

// 1. ls
// type: T_WORD
// content: "ls"

// 	a. create ast node:
// 	type: A_CMD_WORD
// 	content: "ls"

// 2. |
// type: T_PIPE
// left: 1.
// right: NULL

// 	a. create ast node:
// 	type: A_PIPE_SEQUENCE
// 	left: node 1
// 	right: NULL

// 3. wc
// type: T_WORD
// content: "wc"

// 	a. create ast node:
// 	type: A_CMD_WORD
// 	content: "wc"

// 	b. link right side of node 2 to this node i.e.
// 	right: node 3

// 4. |
// type: T_PIPE
// content: ""

// 	a. create ast node:
// 	type: A_PIPE_SEQUENCE
// 	left: node 2
// 	right: NULL

// 5. wc
// type: T_WORD
// content: "wc"

// 	a. create ast node:
// 	type: A_CMD_WORD
// 	content: "wc"

// 	b. link right side of node 4 to this node i.e.
// 	right: node 5

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
	struct s_token	*next;
}					t_token;

typedef struct s_pipe_sequence
{
	int				type;
	struct s_node	*left;
	struct s_node	*right;
}					t_pipe_sequence;

typedef struct s_cmd_word
{
	int				type;
	struct s_list	*content;
}					t_cmd_word;

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

void	create_cmd_word(char *content)
{
	t_cmd_word *cmd_word;

	cmd_word = (t_cmd_word *)malloc(sizeof(t_cmd_word));
	cmd_word->type = A_CMD_WORD;
	cmd_word->content = content;
}

void	create_pipe_sequence(void *left_node)
{
	t_pipe_sequence *pipe_sequence;

	pipe_sequence = (t_pipe_sequence *)malloc(sizeof(t_pipe_sequence));
	cmd_word->type = A_PIPE_SEQUENCE;
	cmd_word->left = left_node;
}

int main()
{
	t_token *tokens;

	tokens = NULL;
	ft_tokenadd_back(&tokens, ft_newtoken("ls", T_WORD));
	ft_tokenadd_back(&tokens, ft_newtoken("|", T_PIPE));
	ft_tokenadd_back(&tokens, ft_newtoken("wc", T_WORD));
	ft_tokenadd_back(&tokens, ft_newtoken("|", T_PIPE));
	ft_tokenadd_back(&tokens, ft_newtoken("wc", T_WORD));
	ft_tokenadd_back(&tokens, ft_newtoken(NULL, T_END));
	while(tokens->type != T_END)
	{
		switch(tokens->type)
		{
			case T_WORD:
				create_cmd_word(tokens->content);
				break;
			case T_PIPE:
				create_pipe_sequence(left_node);
				break;
		}

		printf("%s\n", tokens->content);
		tokens = tokens->next;
	}
}