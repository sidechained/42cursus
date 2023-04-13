// simplified lexer, without quote handling
// modified from: https://github.com/twagger/minishell/tree/master/srcs/parser/lexer
// cc -Wall -Werror -Wextra lexer_only.c -o lexer_only && ./lexer_only

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

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

typedef struct s_token
{
	int				type;		// identified token type
	void			*value;		// the content
	int				qt_rm;		// indicates requirement to remove quotes (1) or not (0)
	struct s_token	*next;		// pointer to next token (linked list)
}	t_token;

t_token_types	catego_toketype(char *content)
{
	if (!content)
		return (T_END);
	if (!strcmp(content, "|"))
		return (T_PIPE);
	else if (!strcmp(content, "<<"))
		return (T_DLESS);
	else if (!strcmp(content, ">>"))
		return (T_DGREAT);
	else if (!strcmp(content, ">"))
		return (T_RED_TO);
	else if (!strcmp(content, "<"))
		return (T_RED_FROM);
	else
		return (T_WORD);
}

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

t_token	*ft_newtoken(void *content)
{
	t_token		*re;

	re = (t_token *)malloc(sizeof(t_token));
	if (!re)
		return (0);
	re->value = content;
	re->type = (int)catego_toketype(content);
	re->next = 0;
	return (re);
}

t_token	*check_quote(char *arr)
{
	int	i;	
	char	new[1000];
	int		i_arr;
	int		i_new;
	char	*try;
	t_token	*token;

	i_arr = 0;
	i_new = 0;
	i = 0;
	while (++i < 1000)
	{
		new[i] = '\0';
		i++;
	}
	while (arr[i_arr])
	{
		new[i_new++] = arr[i_arr++];
		new[i_new] = '\0';
	}
	free(arr);
	if (!strcmp(new, "\0"))
		return (NULL);
	try = strdup(new);
	token = ft_newtoken(try);
	return (token);
}

t_token	*check_each(int len, char *s)
{
	int		i;
	char	*arr;
	t_token	*current;

	i = 0;
	arr = (char *)malloc((len + 1) * sizeof(char));
	if (!arr)
		return (0);
	while (i < len)
	{		
		arr[i++] = *s;
		s++;
	}
	arr[i] = '\0';
	current = check_quote(arr);
	return (current);
}

int	sep(char s)
{
	if (s == ' ' || s == '>' || s == '<' || s == '|')
		return (1);
	return (0);
}

int	count_len(char *s)
{
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (s[i])
	{
		if (sep(s[i]))
			break ;
		len++;
		i++;
	}
	if (sep(*s))
	{
		while (sep(*s) && (*s) != ' ')
		{
			s++;
			len++;
		}		
	}
	return (len);
}

t_token	*ms_tokenizer(char *line)
{
	t_token	*all;
	t_token	*current;
	int		len;

	all = 0;
	while (*line)
	{
		while (*line == ' ' && *line)
			line++;
		len = count_len(line);
		if (!len)
			break ;
		current = check_each(len, line);
		ft_tokenadd_back(&all, current);
		line = line + len;
	}
	ft_tokenadd_back(&all, ft_newtoken(NULL));
	return (all);
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
	char *line = "test | this line";
	t_token	*all;

	all = ms_tokenizer(line);

	while(all->next)
	{
		printf("%s", (char *)all->value);
		printf(" (%s)\n", token_type_to_string(all->type));
		all = all->next;
	}
}
