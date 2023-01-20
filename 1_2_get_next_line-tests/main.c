#include <stdio.h> // printf
#include <fcntl.h> // open
#include "../1_get_next_line/get_next_line.h"

int	main()
{
	char		*next_line;
	int			fd;

	fd = open("../1_get_next_line-tests/simplerTest.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Error opening file");
		return (0);
	}
	while (1)
	{
		next_line = get_next_line(fd);
		printf("%s", next_line);
		if(next_line == NULL)
			break;
		free(next_line);
	}
	return (0);
}
