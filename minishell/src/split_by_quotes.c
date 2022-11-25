// ft_substr - Allocates and returns a substring from the string ’s’ at index ’start’ and of max size ’len’.
// ft_strtrim - Allocates and returns a copy of ’s1’ with the characters specified in ’set’ removed from the beginning and the end of the string.
// strnstr	- locate the first occurrence of the null-terminated string little in the null-terminated string big.
// strchr - searches for the first occurrence of the character c (an unsigned char) in the string pointed to by the argument str.

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "ft_substr.c"

int count_quotes(char *string_to_split)
{
	char *ret;
	int num_quotes_found = 0;
	ret = string_to_split;
	while(ret)
	{
		ret = strchr(ret, '\'');
		if (ret)
		{
			ret = ret + 1;
			num_quotes_found++;
		}
	}
	return num_quotes_found;
}

unsigned long *collect_positions_of_quotes(int num_quotes_found, char *string_to_split)
{
	unsigned long *positions_of_quotes = malloc(num_quotes_found * sizeof(unsigned long));
	char *ret;
	int i = 0;
	ret = string_to_split;
	while(i < num_quotes_found)
	{
		ret = strchr(ret, '\'');
		positions_of_quotes[i] = strlen(string_to_split) - strlen(ret);
		ret = ret + 1;
		i++;
	}
	return positions_of_quotes;
}

char **build_split_array_of_quotes(int num_quotes_found, unsigned long *positions_of_quotes, char *string_to_split)
{
	// assume quotes match for now
	// what if string starts with quote?

	char **split_elements = malloc((num_quotes_found + 1) * sizeof(char *));
	// start to first quote
	split_elements[0] = ft_substr(string_to_split, 0, positions_of_quotes[0]);
	printf("%i %s\n", 0, split_elements[0]);
	int i = 1;
	int startPos;
	int length;
	while(i < num_quotes_found)
	{
		startPos = positions_of_quotes[i-1];
		length = positions_of_quotes[i] - startPos + 1;
		split_elements[i] = ft_substr(string_to_split, startPos, length);
		printf("%i %s\n", i, split_elements[i]);
		i++;
	}
	// fourth quote to end
	startPos = positions_of_quotes[num_quotes_found-1] + 1;
	length = strlen(string_to_split) - startPos;
	split_elements[num_quotes_found] = ft_substr(string_to_split, startPos, length);
	printf("%i %s\n", num_quotes_found, split_elements[num_quotes_found]);	
	return split_elements;
}

char** split_quotes(char* statement)
{
	char **splits = NULL;
	int num_quotes_found = count_quotes(statement);
	unsigned long *positions_of_quotes = collect_positions_of_quotes(num_quotes_found, statement);
	splits = build_split_array_of_quotes(num_quotes_found, positions_of_quotes, statement);
	// int i = 0;
	// while(i < num_quotes_found + 1)
	// {
	// 	printf("%i %s\n", i, splits[i]);
	// 	i++;
	// }	
	return splits;
}

int main()
{
	char* statement = "start 'quotes' andthen 'quotes2' end";
//	char* statement = "start 'quotes' andthen 'quotes2' end 'test";
	split_quotes(statement);
}

