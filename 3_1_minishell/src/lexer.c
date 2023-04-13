// performs a number of steps that together lex the given string
// identify parts in single quotes, double quotes, redirection operators, pipe operators
// expand env vars, remove whitespace from undetermined, remove any empty elements
// Reclassify element following redirection operators, removing operator
// Identify the first of a list of UNDETERMINED elements as a command
// Identify UNDETERMINED elements following commands as ARGUMENT's

// gcc -Wall -Werror -Wextra lexer.c -o lexer && ./lexer
// call line line or statment?
// call element what?

#include <stdbool.h>

#define INITIAL_ELEMENTS 4

#define SINGLE_QUOTES 0
#define DOUBLE_QUOTES 1

struct element
{
	int num_elements; // this will always be set in the first element of an array
 	int type;
 	char *str;
 	bool in_single_quotes;
 	bool in_double_quotes;
};

#include "identify.c"

void lexer(struct element *elements)
{
	print_elements(elements);
	// // Identify and split off elements in single quotes:
	// elements = identify_quotes(elements, SINGLE_QUOTES);
	// print_elements(elements);

	// Identify and split off elements in double quotes:
	// elements = identify_quotes(elements, DOUBLE_QUOTES);
	// print_elements(elements);

	// Split UNDETERMINED elements by redirection operators, labelling operators
	// elements = identify_redirection_operators();

	// Split UNDETERMINED elements by pipe, labelling pipes
	elements = identify_pipe_operators(elements);
	print_elements(elements);

	// Expand $'s anywhere but IN_SINGLE_QUOTES
	// elements = expand_environment_variables();

	// Remove whitespace from start and end of UNDETERMINED elements
	// Remove any UNDETERMINED elements that are empty
	// elements = remove_whitespace();

	// Split UNDETERMINED elements by whitespace
	// Reclassify element following redirection operators, removing operator
	// Identify the first of a list of UNDETERMINED elements as a command
	// Identify UNDETERMINED elements following commands as ARGUMENT's
	// elements = identify_commands()
}

int main()
{
	struct element elements[1];
	elements[0].num_elements = 1;
	elements[0].str = "echo 'bodiddly'$PWD trundlewheel | wc -c > \"outfile$?2\"";
	// elements[0].str = "echo 'bo||diddly'$PWD trundlewheel | wc -c > \"out|file$?2\"";
	// elements[0].str = "echo \'bo||diddly\'$PWD \"trundlewheel\" | \'wc -c\' thing";	
	// elements[0].num_elements = INITIAL_ELEMENTS;
	// elements[0].str = "one 'two' ";
	// elements[0].type = UNDETERMINED;
	// elements[0].in_single_quotes = false;
	// elements[0].in_double_quotes = false;
	// elements[1].str = " three ";	
	// elements[1].type = UNDETERMINED;
	// elements[1].in_single_quotes = false;
	// elements[1].in_double_quotes = false;
	// elements[2].str = " \"four\" five ";	
	// elements[2].type = UNDETERMINED;
	// elements[2].in_single_quotes = false;
	// elements[2].in_double_quotes = false;		
	// elements[3].str = "six";	
	// elements[3].type = UNDETERMINED;
	// elements[3].in_single_quotes = false;
	// elements[3].in_double_quotes = false;		
	lexer(elements);
}