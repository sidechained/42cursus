// simplified parser, parses from tokens initialised in main
// https://github.com/twagger/minishell/tree/master/srcs/parser/parser
// cc -Wall -Werror -Wextra parser_only.c -o parser_only && ./parser_only

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

/*
** parser
*/
typedef struct s_trans
{
	int	state;
	int	event;
	int	action;
	int	next;
	int	nb_reduce;
}		t_trans;

typedef struct s_stack
{
	int				type;
	int				state;
	int				qt_rm;
	void			*data;
	struct s_stack	*next;
}	t_stack;

/*
** ast
*/
typedef struct s_node
{
	int				type;
	int				reduc;
	int				qt_rm;
	void			*data;
	struct s_node	*left;
	struct s_node	*right;
	struct s_node	*next;
}					t_node;


// tokens

typedef struct s_token
{
	int				type;		// identified token type
	void			*value;		// the content
	int				qt_rm;		// indicates requirement to remove quotes (1) or not (0)
	struct s_token	*next;		// pointer to next token (linked list)
}	t_token;

/*
** PARSER PARAMS
*/
#define NB_TRANS 100
#define AUTOMATON "./srcs/parser/parser/parsing_table"
#define NO_ACTION -1
#define DEFAULT -1
#define TO_PROMOTE 0
#define TO_CHILD 1
#define ROOT -2

/*
** PARAMS
*/
#define ERROR -1
#define RET_OK 0
// # define ST_EXIT -2
// # define ERROR_BIN_NOT_FOUND 127

typedef enum e_actions
{
	ACT_SHIFT,
	ACT_REDUCE,
	ACT_ACCEPT,
	ACT_REJECT
}	t_actions;

typedef enum e_rules
{
	R_PIPE_SEQUENCE = 100,
	R_SIMPLE_COMMAND,
	R_CMD_NAME,
	R_CMD_WORD,
	R_CMD_PREFIX,
	R_CMD_SUFFIX,
	R_IO_REDIRECT,
	R_IO_FILE,
	R_FILENAME,
	R_IO_HERE,
	R_HERE_END
}	t_rules;

/*
** AST PARAMS
*/
# define AST 0
# define BUFFER 1
# define ALL 2
# define NO_REDUC -1
# define KEEP 0
# define POP 1
# define PRE_ORDER 0
# define IN_ORDER 1
# define POST_ORDER 2
# define LEFT 0
# define RIGHT 1

/*
** ENUMS
*/

typedef enum e_token_types
{
	T_END = -2, 	// when NULL end of input
	T_WORD = 0, 	// if not any of others then it's a word
	T_RED_TO, 		// >
	T_RED_FROM, 	// <
	T_DLESS, 		// <<
	T_DGREAT, 		// >>
	T_PIPE			// it's a pipe
}	t_token_types;

typedef enum e_ast_types
{
	A_CMD = 0,
	A_RED_TO,
	A_RED_FROM,
	A_DLESS,
	A_DGREAT,
	A_PIPE,
	A_PARAM,
	A_FILE,
	A_LIMITER
}	t_ast_types;

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
	re->value = content;
	re->type = type;
	re->next = 0;
	return (re);
}

// parsing table
t_trans	**ms_init_parsing_table(void)
{
	int		fd;
	t_trans	**trans;

	trans = (t_trans **)malloc(sizeof(*trans) * (NB_TRANS + 1));
	if (!trans)
		return (NULL);
	trans[0] = NULL;
	trans[NB_TRANS] = NULL;
	fd = open(AUTOMATON, O_RDONLY);
	if (fd == ERROR)
	{
		ms_free_table(trans);
		return (NULL);
	}
	if (ms_create_all_transitions(fd, trans) == ERROR)
	{
		ms_free_table(trans);
		close(fd);
		return (NULL);
	}
	close(fd);
	return (trans);
}

int	ms_create_all_transitions(int fd, t_trans **trans)
{
	int		i;
	int		ret;
	char	*line;
	char	**args;

	line = NULL;
	ret = ft_get_next_line(fd, &line, 0);
	i = -1;
	while (ret >= 0)
	{
		args = ft_split(line, 9);
		trans[++i] = ms_new_transition(args);
		ms_free_line_args(line, args, 0);
		line = NULL;
		if (!trans[i])
			return (ERROR);
		if (ret == 0)
			break ;
		ret = ft_get_next_line(fd, &line, 0);
	}
	if (ret == ERROR)
		return (ERROR);
	return (0);
}

void	ms_free_table(t_trans **trans)
{
	t_trans	**begin;

	if (trans)
	{
		begin = trans;
		while (*trans)
		{
			free(*trans);
			++trans;
		}
		free(begin);
	}
}

/*
** GET ENTRY
** Used by the parser to find the right entry in the parsing table according
** to the input and the current state.
*/

t_trans	*ms_get_entry(t_token *input, t_trans **parsing_table, t_stack *stack)
{
	int		i;
	int		input_type;
	t_trans	*table_entry;

	if (!stack)
		return (NULL);
	table_entry = NULL;
	input_type = -1;
	if (input)
		input_type = input->type;
	i = -1;
	while (parsing_table[++i])
	{
		if (parsing_table[i]->state == stack->state)
		{
			if (parsing_table[i]->event == input_type)
				return (parsing_table[i]);
			else if (parsing_table[i]->event == DEFAULT)
				table_entry = parsing_table[i];
		}
	}
	return (table_entry);
}

int	ms_push_input(t_stack **stack, t_token *input)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(*new));
	if (!new)
		return (ERROR);
	new->type = input->type;
	new->qt_rm = input->qt_rm;
	new->state = -1;
	new->data = input->value;
	input->value = NULL;
	new->next = *stack;
	*stack = new;
	return (RET_OK);
}

int	ms_push_reduction(t_stack **stack, int reduction)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(*new));
	if (!new)
		return (ERROR);
	new->type = reduction;
	new->state = -1;
	new->data = NULL;
	new->next = *stack;
	*stack = new;
	return (RET_OK);
}

int	ms_push_state(t_stack **stack, int state)
{
	t_stack	*new;

	if (state == ERROR)
		return (ERROR);
	new = (t_stack *)malloc(sizeof(*new));
	if (!new)
		return (ERROR);
	new->type = -1;
	new->state = state;
	new->data = NULL;
	new->next = *stack;
	*stack = new;
	return (RET_OK);
}

/*
** GET NEXT STATE
** Used by the reduce operation to find the next state after a reduction
*/

int	ms_get_next_state(t_stack *stack, t_trans **parsing_table)
{
	int	i;
	int	state;
	int	next_state;

	state = stack->next->state;
	i = -1;
	while (parsing_table[++i])
	{
		if (parsing_table[i]->state == state)
		{
			if (parsing_table[i]->event == stack->type)
				return (parsing_table[i]->next);
			else if (parsing_table[i]->event == DEFAULT)
				next_state = parsing_table[i]->next;
		}
	}
	return (next_state);
}


/*
** SHIFT
** Shift the current input into the stack and add the next state on top.
*/

static int	ms_shift(t_stack **stack, t_token **input, int next_state)
{
	if (ms_push_input(stack, *input) == ERROR)
		return (ERROR);
	if (ms_push_state(stack, next_state) == ERROR)
		return (ERROR);
	*input = (*input)->next;
	return (RET_OK);
}
/*
** BASIC STACK MANIPULATION
*/

void	ms_add_popped(t_stack **popped, t_stack *stack)
{
	t_stack	*begin;

	if (!(*popped))
		*popped = stack;
	else
	{
		begin = *popped;
		while ((*popped)->next)
			*popped = (*popped)->next;
		(*popped)->next = stack;
		*popped = begin;
	}
	stack->next = NULL;
}

t_stack	*ms_pop_stack(t_stack **stack, int nb)
{
	int		i;
	t_stack	*next;
	t_stack	*popped;

	popped = NULL;
	if (stack)
	{
		i = -1;
		while (++i < nb)
		{
			next = (*stack)->next;
			free(*stack);
			*stack = next;
			next = (*stack)->next;
			ms_add_popped(&popped, *stack);
			*stack = next;
		}
	}
	return (popped);
}

t_stack	*ms_init_stack(void)
{
	t_stack	*state_0;

	state_0 = (t_stack *)malloc(sizeof(*state_0));
	if (!state_0)
		return (NULL);
	state_0->data = NULL;
	state_0->state = 0;
	state_0->type = -1;
	state_0->next = NULL;
	return (state_0);
}

/*
** REMOVE NODE FROM LIST
** Remove a node from the node list that will be attached under a reduction
** node
*/

void	ms_remove_node_from_list(t_node **tree, t_node *node)
{
	t_node	*previous;
	t_node	*tmp;

	if (*tree == node)
	{
		*tree = node->next;
		return ;
	}
	else
	{
		previous = NULL;
		tmp = *tree;
		while (tmp)
		{
			if (tmp == node)
			{
				previous->next = tmp->next;
				return ;
			}
			previous = tmp;
			tmp = tmp->next;
		}
	}
}

t_node	*ms_stack_to_node(t_stack *popped)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(*node));
	if (node)
	{
		node->type = popped->type;
		node->reduc = -1;
		if (popped->type >= R_PIPE_SEQUENCE)
		{
			node->type = -1;
			node->reduc = popped->type;
		}
		node->data = popped->data;
		node->qt_rm = popped->qt_rm;
		popped->data = NULL;
		node->left = NULL;
		node->right = NULL;
		node->next = NULL;
		return (node);
	}
	return (NULL);
}

/*
** CLEAR TREE
** At the end of the parser or if an error occurs during the parsing.
*/

void	ms_clear_tree(t_node **node)
{
	if (*node)
	{
		ms_clear_tree(&(*node)->left);
		ms_clear_tree(&(*node)->right);
		if (!(*node)->left && !(*node)->right)
		{
			free((*node)->data);
			free(*node);
			*node = NULL;
		}
	}
}

void	ms_clear_stack(t_stack *stack)
{
	t_stack	*next;

	while (stack)
	{
		next = stack->next;
		free(stack->data);
		free(stack);
		stack = next;
	}
}

/*
** CLEAR INPUT
** At the end of the parser or if an error occurs during the parsing.
*/

void	ms_clear_input(t_token *input)
{
	t_token	*next;

	while (input)
	{
		next = input->next;
		free(input->value);
		free(input);
		input = next;
	}
}

/*
** PARSER CLEANING
*/

void	ms_parser_cleaning(\
	t_node **tree, t_stack *stack, t_token *input, int ret)
{
	if (ret == ERROR)
		ms_clear_tree(tree);
	ms_clear_stack(stack);
	ms_clear_input(input);
}

/*
** TREE TYPE FIXING
*/

static void	ms_visit_fix_types(t_node *node)
{
	if (!node)
		return ;
	if (node->reduc == R_FILENAME)
		node->right->type = A_FILE;
	if (node->reduc == R_HERE_END)
		node->right->type = A_LIMITER;
	if (node->reduc > R_CMD_WORD)
	{
		if (node->left && node->left->type == A_CMD)
			node->left->type = A_PARAM;
		if (node->right && node->right->type == A_CMD)
			node->right->type = A_PARAM;
	}
	ms_visit_fix_types(node->left);
	ms_visit_fix_types(node->right);
}

t_node	*ms_fix_param_types(t_node *tree)
{
	if (tree && tree->type == -1)
		tree->type = ROOT;
	ms_visit_fix_types(tree);
	return (tree);
}

/*
** SEARCH REDUCTION
** Search for a reduction node in the node list to attach it
** under the current reduction node.
*/

t_node	*ms_search_reduction(t_node **tree, int reduction)
{
	t_node	*begin;
	t_node	*result;

	result = NULL;
	begin = *tree;
	*tree = (*tree)->next;
	while (*tree)
	{
		if ((*tree)->reduc == reduction)
		{
			result = *tree;
			ms_remove_node_from_list(&begin, *tree);
			break ;
		}
		*tree = (*tree)->next;
	}
	*tree = begin;
	return (result);
}

/*
** ADD REDUCTION FRONT
** Creates a node for the current reduction and adds it in front
** of the node list;
*/

t_node	*ms_add_reduction_front(t_node **tree, int reduction)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(*node));
	if (node)
	{
		node->type = -1;
		node->reduc = reduction;
		node->data = NULL;
		node->left = NULL;
		node->right = NULL;
		node->next = *tree;
		*tree = node;
		return (node);
	}
	return (NULL);
}

/*
** BUILD TREE
** Attach the right nodes under the reduction node.
*/

int	ms_build_tree(t_node **tree, t_node *reduc_node, t_stack **popped)
{
	int		i;
	t_node	*child;
	t_stack	*begin;

	i = -1;
	begin = *popped;
	while (*popped)
	{
		if ((*popped)->type >= 100)
			child = ms_search_reduction(tree, (*popped)->type);
		else
			child = ms_stack_to_node(*popped);
		if (!child)
			return (ERROR);
		if (++i == 0)
			reduc_node->right = child;
		else
			reduc_node->left = child;
		if (i == 1 && (*popped)->next)
			reduc_node = reduc_node->left;
		(*popped) = (*popped)->next;
	}
	*popped = begin;
	return (RET_OK);
}

/*
** ADD TREE
** Add the popped elements from the stack to the output tree, under
** the reduction node.
*/

int	ms_add_tree(t_node **tree, t_stack **popped, int reduction)
{
	t_node	*reduc_node;

	reduc_node = ms_add_reduction_front(tree, reduction);
	if (reduc_node)
	{
		if (!ms_build_tree(tree, reduc_node, popped))
			return (RET_OK);
	}
	return (ERROR);
}

/*
** REDUCE
** Pop the stack and replace the popped elements with a reduction. Add the
** next step on top and complete the output (tree) with the popped elements.
*/

int	ms_reduce(\
	t_stack **stack, t_trans **parsing_table, t_trans *pt_entry, t_node **tree)
{
	int		next_state;
	t_stack	*popped;

	popped = ms_pop_stack(stack, pt_entry->nb_reduce);
	if (popped)
	{
		if (!ms_push_reduction(stack, pt_entry->next))
		{
			next_state = ms_get_next_state(*stack, parsing_table);
			if (!ms_push_state(stack, next_state))
			{
				if (!ms_add_tree(tree, &popped, pt_entry->next))
				{
					ms_clear_stack(popped);
					return (RET_OK);
				}
			}
		}
		ms_clear_stack(popped);
	}
	return (ERROR);
}

/*
** ACCEPT
** Accept the command line. This will trigger the return of the output to
** the main function.
*/

int	ms_accept(void)
{
	return (1);
}

/*
** REJECT
** Reject the command line. This will trigger the cleaningof the allocated
** resources and a NULL return. 
*/

int	ms_reject(void)
{
	return (ERROR);
}

/*
** PARSER
** The parser will browse the input and shift or reduce the tokens
** until the command is accepted or rejected. The parser also produces
** and returns an output (synthax tree).
*/

t_node	*ms_parser(t_token *input, t_trans **parsing_table)
{
	int		ret;
	t_node	*tree;
	t_trans	*pt_entry;
	t_stack	*stack;
	t_token	*input_begin;

	ret = RET_OK;
	tree = NULL;
	input_begin = input;
	stack = ms_init_stack();
	while (ret == RET_OK)
	{
		pt_entry = ms_get_entry(input, parsing_table, stack);
		if (pt_entry && pt_entry->action == ACT_SHIFT)
			ret = ms_shift(&stack, &input, pt_entry->next);
		else if (pt_entry && pt_entry->action == ACT_REDUCE)
			ret = ms_reduce(&stack, parsing_table, pt_entry, &tree);
		else if (pt_entry && pt_entry->action == ACT_ACCEPT)
			ret = ms_accept();
		else
			ret = ms_reject();
	}
	ms_parser_cleaning(&tree, stack, input_begin, ret);
	return (ms_fix_param_types(tree));
}

char* token_type_to_string(int type)
{
	switch (type)
	{
		case -2:
			return("T_END");
		case 0:
			return("T_WORD");
		case 1:
			return("T_RED_TO");
		case 2:
			return("T_RED_FROM");
		case 3:
			return("T_DLESS");
		case 4:
			return("T_DGREAT");
		case 5:
			return("T_PIPE");
	}
	return ("");
}

int main()
{
	t_token	*all;
	all = 0;
	ft_tokenadd_back(&all, ft_newtoken("test", T_WORD));
	ft_tokenadd_back(&all, ft_newtoken("|", T_PIPE));
	ft_tokenadd_back(&all, ft_newtoken(">>", T_DGREAT));
	ft_tokenadd_back(&all, ft_newtoken(NULL, T_END));

	while(all->next)
	{
		printf("%s", (char *)all->value);
		printf(" (%s)\n", token_type_to_string(all->type));
		all = all->next;
	}
	ast = ms_parser(input, parsing_table);
}