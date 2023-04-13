// identify items in quotes, identify pipe_operators

// https://stackoverflow.com/questions/11656532/returning-an-array-using-c
// don't forget to free arrays that were malloc'd
// TODO: test with quotes at start, back-to-back quotes, quotes at end - there will def be problems with quotes at start and end!

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "../libft/ft_substr.c"

#define UNDETERMINED 0
#define PIPE_OPERATOR 1

#define SINGLE_QUOTES 0
#define DOUBLE_QUOTES 1

struct split_str
{
	int start_pos;
	int end_pos;
};

// generic
void print_elements(struct element *elements_to_print)
{
	int i = 0;
	while(i < elements_to_print[0].num_elements)
	{
		char *type;
		char *in_single_quotes;
		char *in_double_quotes;

		switch(elements_to_print[i].type)
		{
			case 0:
				type = "UNDETERMINED";
				break;
			case 1:
				type = "PIPE_OPERATOR";
				break;
		}

		if(elements_to_print[i].in_single_quotes == 1)
		{
				in_single_quotes = "in single quotes";
		}
		else
		{
				in_single_quotes = "";
		}

		if(elements_to_print[i].in_double_quotes == 1)
		{
				in_double_quotes = "in double quotes";
		}
		else
		{
				in_double_quotes = "";
		}
		printf("%i:`%s` %s %s %s\n", i, elements_to_print[i].str, type, in_single_quotes, in_double_quotes);
		i++;
	}
	printf("\n");
}

// generic
int count_delimiters(char str_to_split[], char delimiter)
{
	int num_delimiters_found = 0;
	int i = 0;
	while(str_to_split[i])
	{
		if (str_to_split[i] == delimiter)
			num_delimiters_found++;
		i++;
	}
	return(num_delimiters_found);
}

// generic
unsigned long *collect_positions_of_delimiters(int num_delimiters_found, char str_to_split[], char delimiter)
{
	unsigned long *positions_of_delimiters = malloc((num_delimiters_found * 2 + 1) * sizeof(unsigned long));
	positions_of_delimiters[0] = 0;
	int i = 0;
	int j = 1;
	while(str_to_split[i])
	{
		if (str_to_split[i] == delimiter)
		{
			positions_of_delimiters[j] = i;
			j++;
		}
		i++;
	}
	positions_of_delimiters[j] = strlen(str_to_split);
	return(positions_of_delimiters);
}

// generic
struct element *reinsert_elements(struct element *existing_elements, struct element *elements_to_insert, int index_to_insert_at)
{	
	int num_reinserted_elements = existing_elements[0].num_elements + elements_to_insert[0].num_elements - 1;
	struct element *reinserted_elements = malloc(num_reinserted_elements * sizeof(struct element*));
	int i = 0;
	int j = 0;
	int k = 0;
	while(i < num_reinserted_elements)
	{
		if (i == index_to_insert_at)
		{
			while(j < elements_to_insert[0].num_elements)
			{
				reinserted_elements[i] = elements_to_insert[j];
				i++;
				j++;
			}
			k++;
		}
		else
		{
			reinserted_elements[i] = existing_elements[k];
			i++;
			k++;
		}
	}
	reinserted_elements[0].num_elements = elements_to_insert[0].num_elements + existing_elements[0].num_elements - 1;
	return reinserted_elements;
}

// quotes only
char *truncate_unclosed_quotes(int num_delimiters_found, unsigned long *positions_of_delimiters, char *str_to_split)
{
	char *truncated_str;
	if (num_delimiters_found % 2 == 1)
	{
		int position_to_truncate_to = positions_of_delimiters[num_delimiters_found - 1];
		truncated_str = malloc((position_to_truncate_to + 1) * sizeof(char));
		strlcpy(truncated_str, str_to_split, position_to_truncate_to + 1);		
	}
	else
	{
		truncated_str = malloc(strlen(str_to_split) * sizeof(char));
		strcpy(truncated_str, str_to_split);
	}
	return(truncated_str);
}

// QUOTES:

// quotes only
struct element *split_by_quote_delimiter(int num_delimiters_found, unsigned long *positions_of_delimiters, char *str_to_split, char *delimiter, int quotes_type)
{
	struct element *split_elements = malloc((num_delimiters_found + 2) * sizeof(struct element));
	// first split:
	split_elements[0].str = ft_substr(str_to_split, 0, positions_of_delimiters[0]);
	// middle splits:
	int i = 0;
	int startPos;
	int length;
	while(i < num_delimiters_found - 1)
	{
		startPos = positions_of_delimiters[i] + strlen(delimiter);
		length = positions_of_delimiters[i+1] - startPos;
		split_elements[i+1].str = ft_substr(str_to_split, startPos, length);
		if ((i + 1) % 2 == 1)
		{
			if(quotes_type == SINGLE_QUOTES)
			{
				split_elements[i+1].in_single_quotes = true;
			}
			else if(quotes_type == DOUBLE_QUOTES)
			{
				split_elements[i+1].in_double_quotes = true;
			}
		}
		else
		{
			if(quotes_type == SINGLE_QUOTES)
			{
				split_elements[i+1].in_single_quotes = false;
			}
			else if(quotes_type == DOUBLE_QUOTES)
			{
				split_elements[i+1].in_double_quotes = false;
			}
		}
		i++;
	}
	// last split:
	startPos = positions_of_delimiters[i] + strlen(delimiter);
	length = strlen(str_to_split) - startPos;
	split_elements[i+1].str = ft_substr(str_to_split, startPos, length);
	split_elements[0].num_elements = num_delimiters_found + 1;
	return split_elements;
}

// quotes only
struct element *identify_quotes(struct element *elements, int quotes_type) // passing elements by reference
{
	char *delimiter;
	if (quotes_type == SINGLE_QUOTES)
	{
		delimiter = "\'";
	}
	else
	{
		delimiter = "\"";
	}
	int i = 0;
	while(i < elements[0].num_elements)
	{
		if (elements[i].type == UNDETERMINED)
		{
			if(strchr(elements[i].str, delimiter[0]))
			{
				int num_delimiters_found = count_delimiters(elements[i].str, delimiter[0]);
				unsigned long *positions_of_delimiters = collect_positions_of_delimiters(num_delimiters_found, elements[i].str, delimiter[0]);
				char *truncated_str = truncate_unclosed_quotes(num_delimiters_found, positions_of_delimiters, elements[i].str);
				struct element *split_elements = split_by_quote_delimiter(num_delimiters_found, positions_of_delimiters, truncated_str, delimiter, quotes_type);
				free(positions_of_delimiters);
				free(truncated_str);
				printf("sss: %i %i %i\n", elements[0].num_elements, split_elements[0].num_elements, i);
				elements = reinsert_elements(elements, split_elements, i);
				i = i + elements[0].num_elements; // skip past the elements we just split (no need to split again)
			}
		}
		i++;
	}
	return(elements);
}

// PIPES

struct element *split_by_pipe_delimiter(unsigned long *positions_of_delimiters, int num_delimiters, char *str_to_split)
{
	struct element *split_elements = malloc(num_delimiters * sizeof(struct element));
	int i = 0;
	int startPos;
	int length;
	while(i < num_delimiters - 1)
	{
		startPos = positions_of_delimiters[i] + 1;
		length = positions_of_delimiters[i+1] - startPos;		
		split_elements[i].str = ft_substr(str_to_split, startPos, length);
		split_elements[i].type = UNDETERMINED;			
		split_elements[i+1].str = "|";
		split_elements[i+1].type = PIPE_OPERATOR;
		i++;
	}
	return(split_elements);
}

struct element *identify_pipe_operators(struct element *elements) // passing elements by reference
{
	int i = 0;
	while(i < elements[0].num_elements)
	{
		if (elements[i].type == UNDETERMINED)
		{
			if(strchr(elements[i].str, '|') != NULL)
			{	
				int num_delimiters_found = count_delimiters(elements[i].str, '|');
				unsigned long *positions_of_delimiters = collect_positions_of_delimiters(num_delimiters_found, elements[i].str, '|');
				struct element *split_elements = split_by_pipe_delimiter(positions_of_delimiters, num_delimiters_found * 2 + 1, elements[i].str);
				free(positions_of_delimiters);
				elements = reinsert_elements(elements, split_elements, i);
			}
		}
		i++;
	}
	return(elements);
}