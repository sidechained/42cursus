#include <stdio.h>
#include <sys/stat.h> // open
#include <fcntl.h>	  // open
#include "get_next_line.h"
#include "libft.h"

#define STDIN_FD 0

// cc -Wall -Werror -Wextra -Ilibft -Iget_next_line heredoc.c libft/ft_strlen.c libft/ft_strdup.c libft/ft_substr.c libft/ft_strjoin.c get_next_line/get_next_line.c && ./a.out 

void	here_doc(char *limiter)
{
	int	heredoc_fd;
	char *next_line;

	heredoc_fd = open(".heredoc_tmp",  O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (heredoc_fd < 0)
		printf("Error!\n"); // ft_printf!
	printf("pipe heredoc>\n");
	while(1)
	{
		next_line = get_next_line(STDIN_FD);
		// if (next_line == NULL)
		// 	exit(1);
		next_line[ft_strlen(next_line) - 1] = '\0';
		printf("\"%s\" \"%s\"\n", next_line, limiter);
		if (ft_strncmp(next_line, limiter, ft_strlen(next_line)) == 0)
			break;
		write(heredoc_fd, next_line, ft_strlen(next_line));
		write(heredoc_fd, "\n", 1);
		free(next_line);
	}
	printf("broken\n");
	free(next_line);

	close(heredoc_fd);
	// how to pass on file descriptor...
	// how to delete file when done? unlink(".heredoc_tmp");
}

int main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)envp;
	if(ft_strncmp(argv[1], "here_doc", 8) == 0)
		here_doc(argv[2]);
}