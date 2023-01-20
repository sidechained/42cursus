// https://stackoverflow.com/questions/11656532/returning-an-array-using-c
// don't forget to free arrays that were malloc'd

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "../libft/ft_substr.c"

#define UNDETERMINED 0
#define PIPE_OPERATOR 1

int count_delimiters(struct element *element_to_split, char *delimiter)
{
	char *ret;
	int num_delimiters_found = 0;
	ret = element_to_split->str;
	while(ret)
	{
		ret = strstr(ret, delimiter);
		if (ret)
		{
			ret = ret + strlen(delimiter);
			num_delimiters_found++;
		}
	}
	return num_delimiters_found;
}

unsigned long *collect_positions_of_delimiters(int num_delimiters_found, struct element *element_to_split, char *delimiter)
{
	unsigned long *positions_of_delimiters = malloc(num_delimiters_found * sizeof(unsigned long));
	char *ret;
	int i = 0;
	ret = element_to_split->str;
	while(i < num_delimiters_found)
	{
		ret = strstr(ret, delimiter);
		positions_of_delimiters[i] = strlen(element_to_split->str) - strlen(ret);
		ret = ret + strlen(delimiter);
		i++;
	}
	return positions_of_delimiters;
}

struct element *split_by_delimiter(int num_delimiters_found, unsigned long *positions_of_delimiters, struct element *element_to_split, char *delimiter)
{
	struct element *split_elements = malloc((num_delimiters_found * 2 + 1) * sizeof(struct element));
	// first split:
	split_elements[0].str = ft_substr(element_to_split->str, 0, positions_of_delimiters[0]);
	split_elements[0].type = UNDETERMINED;
	// middle splits:
	int i = 0;
	int startPos;
	int length;
	int index;	
	while(i < num_delimiters_found - 1)
	{

		index = i*2+1;
		split_elements[index].str = delimiter;
		split_elements[index].type = PIPE_OPERATOR;
		startPos = positions_of_delimiters[i] + strlen(delimiter);
		length = positions_of_delimiters[i+1] - startPos;
		index = i*2+2;
		split_elements[index].str = ft_substr(element_to_split->str, startPos, length);
		split_elements[index].type = UNDETERMINED;		
		i++;
	}
	// last split:
	index = i*2+1;
	split_elements[index].str = delimiter;
	split_elements[index].type = PIPE_OPERATOR;
	startPos = positions_of_delimiters[i] + strlen(delimiter);
	length = strlen(element_to_split->str) - startPos;
	index = i*2+2;
	split_elements[index].str = ft_substr(element_to_split->str, startPos, length);
	split_elements[index].type = UNDETERMINED;
	return split_elements;
}

struct element *reinsert_elements(struct element *existing_elements, int existing_elements_size, struct element *elements_to_insert, int elements_to_insert_size, int index_to_insert_at)
{	
	int reinserted_elements_size = existing_elements_size + elements_to_insert_size - 1;
	struct element *reinserted_elements = malloc(reinserted_elements_size * sizeof(struct element*));
	int i = 0;
	int j = 0;
	int k = 0;
	while(i < reinserted_elements_size)
	{
		if (i == index_to_insert_at)
		{
			while(j < elements_to_insert_size)
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
	return reinserted_elements;
}

struct element *split_by_pipe_operator(struct element *element_to_split, char *delimiter, int elements_size, int index_to_insert_at)
{
	int num_delimiters_found = count_delimiters(element_to_split, delimiter);
	unsigned long *positions_of_delimiters = collect_positions_of_delimiters(num_delimiters_found, element_to_split, delimiter);
	struct element *split_elements = split_by_delimiter(num_delimiters_found, positions_of_delimiters, element_to_split, delimiter);
	struct element *reinserted_elements = reinsert_elements(split_elements, elements_size, split_elements, num_delimiters_found * 2 + 1, index_to_insert_at);
	return reinserted_elements;
}

struct element *identify_pipe_operators(struct element *elements, int elements_size) // passing elements by reference
{
	struct element *reinserted_elements;
	int i = 0;
	while(i < elements_size)
	{
		if (elements[i].type == UNDETERMINED)
		{
			// NOTE: we should not always split, only if | identified
			if(strchr(elements[i].str, '|') != NULL)
			{
				reinserted_elements = split_by_pipe_operator(&elements[i], "|", elements_size, i);				
			}
		}
		i++;
	}
	return(reinserted_elements);
}