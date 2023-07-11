// Q: exit when?
// Q: how/when is get_next_line used? on output of readline?

// https://www.geeksforgeeks.org/signals-c-language/
// allowed functions (signals):
// signal, sigaction, sigemptyset, sigaddset, kill

// cc -Wall -Werror -Wextra -lreadline readline_test.c -o readline_test && ./readline_test

// TODO: modify strcmp to ft_strcmp
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <sys/ioctl.h>

void sigint_handler(int sig)
{
	if (sig == SIGINT) // ctrl + C
	{
		// g_status = 130;
		write(1, "\n", 1);
		rl_on_new_line(); // Tell update functions we have moved onto a new (empty) line
		rl_replace_line("", 0); // Replace the contents of rl_line_buffer with text
		rl_on_new_line(); // Tell the update routines that we have moved onto a new (empty) line, usually after ouputting a newline
		rl_redisplay(); // Change what’s displayed on the screen to reflect the current contents of rl_line_buffer. 
	}
}

int main()
{
	char *line;
	while (1)
	{
		signal(SIGINT, sigint_handler); // display new prompt on new line when CTRL + C pressed
		signal(SIGQUIT, SIG_IGN); // override/ignore default behaviour of CTRL + '\'
		line = readline("microshell% ");
		if (line == NULL) // using this to detect CTRL D, which sends EOF (what if line is actually NULL?)
			break ;
		if (strcmp(line, "clear") == 0)
			rl_clear_history();
		else
			add_history(line);
		free(line);
	}
	return (0);
}