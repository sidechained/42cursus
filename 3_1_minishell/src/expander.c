// expand $ or $?
// get env from main
// expand things that are already in env
// NAME=value
// use getenv to get elements from envp for now (see if it is allowed in final assignment)
// $ are valid within double quotes but not in single quotes
// Q: can we $HOME122143

// `echo `								UNDETERMINED
// `'bo||diddly'`						IN_SINGLE_QUOTES
// `$PWD trundlewheel `				UNDETERMINED
// `|`									PIPE_OPERATOR
// ` wc -c `							UNDETERMINED
// `>`									OUTPUT_REDIRECTION_OPERATOR
// ` `									UNDETERMINED
// `"out|file$?2"`						IN_DOUBLE_QUOTES

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "ft_substr.c"

#define UNDETERMINED 0
#define PIPE_OPERATOR 1
#define OUTPUT_REDIRECTION_OPERATOR 2

struct element
{
 	char *str;
 	int type;
 	bool in_single_quotes;
 	bool in_double_quotes;
};

int main()
{
	// define in_double_quotes in below?!
	struct element elements[8];
	elements[0].str = "echo ";
	elements[0].type = UNDETERMINED;
	elements[0].in_single_quotes = false;
	elements[0].in_double_quotes = false;
	elements[1].str = "bo||diddly";
	elements[1].type = UNDETERMINED;
	elements[1].in_single_quotes = true;
	elements[1].in_double_quotes = false;
	elements[2].str = "$PWD trundlewheel ";
	elements[2].type = UNDETERMINED;
	elements[2].in_single_quotes = false;
	elements[2].in_double_quotes = false;
	elements[3].str = "|";
	elements[3].type = PIPE_OPERATOR;
	elements[3].in_single_quotes = false;
	elements[3].in_double_quotes = false;
	elements[4].str = " wc -c ";
	elements[4].type = UNDETERMINED;
	elements[4].in_single_quotes = false;
	elements[4].in_double_quotes = false;
	elements[5].str = ">";
	elements[5].type = OUTPUT_REDIRECTION_OPERATOR;
	elements[5].in_single_quotes = false;
	elements[5].in_double_quotes = false;
	elements[6].str = " ";
	elements[6].type = UNDETERMINED;
	elements[6].in_single_quotes = false;
	elements[6].in_double_quotes = false;
	elements[7].str = "out|file$?"; // change back to $? later
	elements[7].type = UNDETERMINED;
	elements[7].in_single_quotes = false;
	elements[7].in_double_quotes = true;

	int elements_size = sizeof(elements) / sizeof(elements[0]);
	int i = 0;
	while(i < elements_size)
	{
		// only expand within UNDETERMINED elements that aren't in single quotes (where expansion isn't allowed)
		if (elements[i].type == UNDETERMINED && elements[i].in_single_quotes == false)
		{
			// do first for single $, then handle more than one $
			char *from_dollar;
			from_dollar = strchr(elements[i].str, '$');
			if (from_dollar != NULL)
			{
				if (from_dollar[1] == '?')
				{
					printf("qm\n");
				}
				else
				{
					printf("nqm\n");
					int j = 1;
					while(from_dollar[j] != '\0')
					{
						if (from_dollar[j] == ' ' || from_dollar[j] == '\t' || from_dollar[j] == '\n')
							break;
						j++;
					}
					char *env_var_name = ft_substr(from_dollar, 1, j - 1);
					char *env_var_val = getenv(env_var_name);
					// reconsitute new string (wouldn't using strlcat be better?)
					int len_before = strlen(elements[i].str) - strlen(from_dollar);
					int env_var_val_len = strlen(env_var_val);
					int len_after = strlen(from_dollar) - strlen(env_var_name) - 1;
					char *new_str = malloc(sizeof(char *) * len_before + env_var_val_len + len_after);
					// new_str = "out|file                " <- orig_str = "out|file----------"
					memcpy(new_str, elements[i].str, len_before);
					// new_str = "out|file/hello/here     " <- env_var_val = "/hello/here"
					memcpy(new_str + len_before, env_var_val, env_var_val_len);
					// new_str = "out|file/hello/here test" <- orig_str = "------------- test"
					memcpy(new_str + len_before + env_var_val_len, elements[i].str + len_before + strlen(env_var_name) + 1, len_after);
					elements[i].str = new_str;
					//free(new_str); // freeing this here causes first conversion to be deleted!
				}
			}
		}
		i++;
	}
	i = 0;
	while(i < elements_size)
	{
		printf("`%s`\n", elements[i].str);
		i++;
	}		
	return 0;
}