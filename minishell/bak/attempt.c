// NOTES
// eventually will have to use strnstr not strstr

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "ft_substr.c"

// #define UNDEFINED 0

// struct Element {
//   char* str;
//   int type;
//   bool in_single_quotes;
// };

// int main() {
//   struct Element raw_statement[1];
//   struct Element* splits;
//   raw_statement[0].str = "existing_array > array_to_insert > combined_array";
//   raw_statement[0].type = UNDEFINED;
//   raw_statement[0].in_single_quotes = 0;
//   splits = splitter(raw_statement, ">");
//   return 0;
// }


// start with an array containing existing_array element (the full statement "test > this")
// split it to create an array of combined_array elements ("test", ">", "this")
// create a new array with these combined_array elements in place of the original existing_array

void combine_arrays(char** combined_array, int combined_array_size, char** existing_array, char** array_to_insert, int array_to_insert_size, int index_to_insert_at)
{
	int i = 0;
	int j = 0;
	int k = 0;
	// printf("%i\n", array_to_insert_size);
	while(i < combined_array_size)
	{
		if (i == index_to_insert_at)
		{
			while(j < array_to_insert_size)
			{
				combined_array[i] = array_to_insert[j];
				// printf("%i, %s\n", i, combined_array[i]);
				i++;
				j++;
			}
			k++;
		}
		else
		{
			combined_array[i] = existing_array[k];
			i++;
			k++;
		}
	}
}

// int main()
// {
// 	char* existing_array[3] = {"first ", "test > this", " last"};
// 	char* array_to_insert[3] = {"test ", ">", " this"};
// 	int existing_array_size = sizeof(existing_array) / sizeof(char*);
// 	int array_to_insert_size = sizeof(array_to_insert) / sizeof(char*);
// 	int combined_array_size = existing_array_size + array_to_insert_size - 1;
// 	char* combined_array[combined_array_size];
// 	combine_arrays(combined_array, combined_array_size, existing_array, array_to_insert, array_to_insert_size, 1);
// 	// print the result
// 	int i = 0;
// 	while(i < combined_array_size)
// 	{
// 		printf("%s", combined_array[i]);
// 		i++;
// 	}
// 	return 0;
// }

// function to split string based on operators [WORKS]
// can be used to split on < > << >> |
// can handle multichar operators (i.e. >>) and multiple occurances of operators

int count_delimiters(char* string_to_split, char* delimiter)
{
	char* ret;
	int num_delimiters_found = 0;
	ret = string_to_split;
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

void collect_positions_of_delimiters(unsigned long* positions_of_delimiters, int num_delimiters_found, char* string_to_split, char* delimiter)
{
	char* ret;
	int i = 0;
	ret = string_to_split;
	while(i < num_delimiters_found)
	{
		ret = strstr(ret, delimiter);
		positions_of_delimiters[i] = strlen(string_to_split) - strlen(ret);
		ret = ret + strlen(delimiter);
		//printf("%lu\n", positions_of_delimiters[i]);
		i++;
	}
}

void build_array_of_splits(int num_delimiters_found, char** splits, unsigned long* positions_of_delimiters, char* string_to_split, char* delimiter)
{
	// first split:
	splits[0] = ft_substr(string_to_split, 0, positions_of_delimiters[0]);
	// middle splits:
	int i = 0;
	int startPos;
	int length;
	while(i < num_delimiters_found - 1)
	{
		splits[i*2+1] = delimiter;
		startPos = positions_of_delimiters[i] + strlen(delimiter);
		length = positions_of_delimiters[i+1] - startPos;
		splits[i*2+2] = ft_substr(string_to_split, startPos, length);
		i++;
	}
	// last split:
	splits[i*2+1] = delimiter;
	startPos = positions_of_delimiters[i] + strlen(delimiter);
	length = strlen(string_to_split) - startPos;
	splits[i*2+2] = ft_substr(string_to_split, startPos, length);
}

char* split_string(char* string_to_split, char* delimiter)
{
	int num_delimiters_found = count_delimiters(string_to_split, delimiter);
	unsigned long buf_positions_of_delimiters[num_delimiters_found];
	collect_positions_of_delimiters(buf_positions_of_delimiters, num_delimiters_found, string_to_split, delimiter);
	char* buf_splits[num_delimiters_found * 2 + 1];
	build_array_of_splits(num_delimiters_found, buf_splits, buf_positions_of_delimiters, string_to_split, delimiter);
	int i = 0;
	while(i < num_delimiters_found * 2 + 1)
	{
		printf("%s\n", buf_splits[i]);
		i++;
	}
	return buf_splits;
}

int main()
{
	char* statement[1] = { "existing_array | array_to_insert | combined_array | four" };
	char* delimiter = "|";
	int statement_size = sizeof(statement) / sizeof(char*);
	int i = 0;
	while(i < statement_size)
	{
		split_string(statement, delimiter);
		i++;
	}
// 	char* existing_array[3] = {"first ", "test > this", " last"};
// 	char* array_to_insert[3] = {"test ", ">", " this"};
// 	int existing_array_size = sizeof(existing_array) / sizeof(char*);
// 	int array_to_insert_size = sizeof(array_to_insert) / sizeof(char*);
// 	int combined_array_size = existing_array_size + array_to_insert_size - 1;
// 	char* combined_array[combined_array_size];
// 	combine_arrays(combined_array, combined_array_size, existing_array, array_to_insert, array_to_insert_size, 1);

	return 0;
}