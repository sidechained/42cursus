#include "libft.h"
#include "get_next_line.h"
#include <fcntl.h>

int main()
{
	char			*filename = "gnl_test.txt";
	char			*next_line;
	char			**split_line;
	int				fd;

	fd = open(filename, O_RDONLY);
	next_line = get_next_line(fd);
	split_line = ft_split(next_line, ' ');
	free(next_line);
	free(split_line[0]);
	free(split_line[1]);
	free(split_line[2]);		
	free(split_line);
	return (0);
}