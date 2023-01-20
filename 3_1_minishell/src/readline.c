// DESC: read lines from a simulated command prompt, including history
// gcc -Wall -Werror -Wextra -lreadline readline.c && ./a.out

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>

char* get_line_from_command_prompt()
{
	char *user = getenv("USER");
	int user_len = strlen(user);
	char *hostname = "minishell";
	int hostname_len = strlen(hostname);	
	char *dir = strrchr(getenv("PWD"), '/');
	dir++;
	int dir_len = strlen(dir);
	char *endprompt = " % ";
	int endprompt_len = strlen(endprompt);
	char *prompt = malloc((user_len + 1 + hostname_len + 1 + dir_len + endprompt_len + 1) * sizeof(char));
	char *line;
	strcpy(prompt, user);
	strcat(prompt, "@");
	strcat(prompt, hostname);
	strcat(prompt, " ");
	strcat(prompt, dir);
	strcat(prompt, endprompt);
	line = readline(prompt);
	add_history(line);
	free(prompt);
	return(line);
}

int main()
{
	// handle single line for now:
	char *line;
	line = get_line_from_command_prompt();

	printf("%s\n", line);
}

// rl_clear_history - Clear the history list by deleting all of the entries, in the same manner as the History library’s clear_history() function. This differs from clear_history because it frees private data Readline saves in the history list.
// rl_on_new_line - Tell the update functions that we have moved onto a new (empty) line, usually after outputting a newline.
// rl_replace_line - Replace the contents of rl_line_buffer with text. The point and mark are preserved, if possible. If clear_undo is non-zero, the undo list associated with the current line is cleared.
// rl_redisplay - Change what’s displayed on the screen to reflect the current contents of rl_line_buffer.