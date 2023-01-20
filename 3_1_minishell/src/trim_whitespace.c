#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "ft_strtrim.c"

#define NUM_ELEMENTS 6

#define UNDEFINED 0
#define PIPE_OPERATOR 1

struct element
{
 	char *str;
 	int type;
 	bool in_single_quotes;
};

void strip_whitespace(struct element *elements)
{
	int i = 0;
	while(i < NUM_ELEMENTS)
	{
		if (elements[i].in_single_quotes == false)
		{	
			elements[i].str = ft_strtrim(elements[i].str, " ");
		}
		i++;
	}
}


int count_num_elements_with_empty_strings(struct element *elements)
{
	int i = 0;
	int c = 0;
	while(i < NUM_ELEMENTS)
	{
		if (strcmp(elements[i].str, "") == 0)
			c++;
		i++;
	}
	return c;
}

struct element *remove_elements_with_empty_strings(struct element *elements, int num_elements_to_remove)
{
	// malloc new elements
	struct element *new_elements = malloc(sizeof(struct element*) * (NUM_ELEMENTS - num_elements_to_remove));
	// copy old elements that aren't empty into new elements
	int i = 0;
	int j = 0;
	while(i < NUM_ELEMENTS - num_elements_to_remove)
	{
		if (strcmp(elements[j].str, "") == 0)
		{
			j++;
		}
		new_elements[i] = elements[j];
		i++;
		j++;
	}
	return new_elements;
}

void print_elements(struct element *elements, int size)
{
	int i = 0;
	while(i < size)
	{
		printf("%i `%s`\n", i, elements[i].str);
		i++;
	}	
}

int main()
{
	struct element elements[NUM_ELEMENTS];
	struct element *new_elements;
	int num_elements_to_remove;
	elements[0].str = " t est ";
	elements[0].type = UNDEFINED;
	elements[0].in_single_quotes = false;
	elements[1].str = "|";
	elements[1].type = PIPE_OPERATOR;
	elements[1].in_single_quotes = false;
	elements[2].str = "";
	elements[2].type = UNDEFINED;
	elements[2].in_single_quotes = false;
	elements[3].str = "'this '";
	elements[3].type = UNDEFINED;
	elements[3].in_single_quotes = true;
	elements[4].str = " ";
	elements[4].type = UNDEFINED;
	elements[4].in_single_quotes = false;
	elements[5].str = "func tion";
	elements[5].type = UNDEFINED;
	elements[5].in_single_quotes = false;
	printf("before strip\n");
	print_elements(elements, NUM_ELEMENTS);
	strip_whitespace(elements);
	printf("after strip\n");	
	print_elements(elements, NUM_ELEMENTS);
	num_elements_to_remove = count_num_elements_with_empty_strings(elements);
	new_elements = remove_elements_with_empty_strings(elements, num_elements_to_remove);
	printf("after empty-quote removal\n");		
	print_elements(new_elements, NUM_ELEMENTS - num_elements_to_removes§);
	free(new_elements);
	return 0;
}