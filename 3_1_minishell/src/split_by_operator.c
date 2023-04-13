// split by operator

// https://stackoverflow.com/questions/11656532/returning-an-array-using-c
// don't forget to free arrays that were malloc'd

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "ft_substr.c"

#define UNDETERMINED 0
#define PIPE_OPERATOR 1

#define INITIAL_NUM_ELEMENTS 1

struct element
{
 	char *str;
 	int type;
};

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

struct element *build_split_array_of_elements(int num_delimiters_found, unsigned long *positions_of_delimiters, struct element *element_to_split, char *delimiter)
{
	struct element *split_elements = malloc((num_delimiters_found * 2 + 1) * sizeof(struct element*));
	// first split:
	split_elements[0].str = ft_substr(element_to_split->str, 0, positions_of_delimiters[0]);
	split_elements[0].type = UNDETERMINED;
	// middle splits:
	int i = 0;
	int startPos;
	int length;
	while(i < num_delimiters_found - 1)
	{
		split_elements[i*2+1].str = delimiter;
		split_elements[i*2+1].type = PIPE_OPERATOR;
		startPos = positions_of_delimiters[i] + strlen(delimiter);
		length = positions_of_delimiters[i+1] - startPos;
		split_elements[i*2+2].str = ft_substr(element_to_split->str, startPos, length);
		split_elements[i*2+2].type = UNDETERMINED;		
		i++;
	}
	// last split:
	split_elements[i*2+1].str = delimiter;
	split_elements[i*2+1].type = PIPE_OPERATOR;
	startPos = positions_of_delimiters[i] + strlen(delimiter);
	length = strlen(element_to_split->str) - startPos;
	split_elements[i*2+2].str = ft_substr(element_to_split->str, startPos, length);
	split_elements[i*2+2].type = UNDETERMINED;
	// print check
	// i = 0;
	// while(split_elements[i].str != NULL)
	// {
	// 	printf("%i %s %i\n", i, split_elements[i].str, split_elements[i].type);
	// 	i++;
	// }					
	return split_elements;
}

struct element *split_element(struct element *element_to_split, char *delimiter)
{
	int num_delimiters_found = count_delimiters(element_to_split, delimiter);
	unsigned long *positions_of_delimiters = collect_positions_of_delimiters(num_delimiters_found, element_to_split, delimiter);
	struct element *split_elements = build_split_array_of_elements(num_delimiters_found, positions_of_delimiters, element_to_split, delimiter);
	// // print check
	// int i = 0;
	// while(split_elements[i].str != NULL)
	// {
	// 	printf("%i %s\n", i, split_elements[i].str);
	// 	i++;
	// }				
	return split_elements;
}

struct element *combine_elements(struct element *existing_elements, int existing_elements_size, struct element *elements_to_insert, int elements_to_insert_size, int index_to_insert_at)
{	
	int combined_elements_size = existing_elements_size + elements_to_insert_size - 1;
	struct element *combined_elements = malloc(combined_elements_size * sizeof(struct element*));
	int i = 0;
	int j = 0;
	int k = 0;
	while(i < combined_elements_size)
	{
		if (i == index_to_insert_at)
		{
			while(j < elements_to_insert_size)
			{
				combined_elements[i] = elements_to_insert[j];
				i++;
				j++;
			}
			k++;
		}
		else
		{
			combined_elements[i] = existing_elements[k];
			i++;
			k++;
		}
	}
	return combined_elements;
}

void split_undefined_elements(struct element *elements, int elements_size) // passing elements by reference
{
	struct element *split_elements;	
	int split_elements_size;
	struct element *combined_elements;
	int i = 0;
	while(i < INITIAL_NUM_ELEMENTS)
	{
		if (elements[i].type == UNDETERMINED)
		{
			split_elements = split_element(&elements[i], "|");
			//split_elements_size = sizeof(split_elements) / sizeof(split_elements[0]);

			split_elements_size = 5;
			combined_elements = combine_elements(elements, elements_size, split_elements, split_elements_size, i);

			// print check
			int i = 0;
			while(combined_elements[i].str != NULL)
			{
				printf("%i %s %i\n", i, combined_elements[i].str, combined_elements[i].type);
				i++;
			}					

		}
		i++;
	}	
}

int main()
{
	struct element elements[INITIAL_NUM_ELEMENTS];
	int elements_size = sizeof(elements) / sizeof(elements[0]);
	elements[0].str = "one | two | three";
	elements[0].type = UNDETERMINED;
	split_undefined_elements(elements, elements_size);
	return 0;
}
