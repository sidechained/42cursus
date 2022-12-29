// We consider that get_next_line() has an undefined behavior if the file pointed to by the file descriptor changed since the last call whereas read() didn’t reach the end of file.
// We also consider that get_next_line() has an undefined behavior when reading a binary file. However, you can implement a logical way to handle this behavior if you want to.

// cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <files>.c
// cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c && ./a.out

// TODO
// - handle bad BUFFER_SIZE's (i.e. 0 or less)

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		chars_from_file[BUFFER_SIZE + 1];
	int			num_bytes_read;
	char 		*next_line;
	char		*empty_str;

	empty_str = "";
	if (first_call)
		buffer = "";
	if (ft_strchr(buffer, '\n') == NULL)
	{
		num_bytes_read = read(fd, chars_from_file, BUFFER_SIZE);
		if (num_bytes_read < 1)
		{
			if (num_bytes_read == -1)
				return (NULL);
			if (num_bytes_read == 0)
			{
				if (buffer == empty_str)
				{
					next_line = ft_substr(buffer, 0, ft_strlen(buffer));
					buffer = "";
					return (next_line);
				}
				else
					return (NULL);
			}
		}
		chars_from_file[num_bytes_read] = '\0';
		buffer = ft_strjoin(buffer, chars_from_file);
	}
	
	int i = 0;
	while(buffer[i])
	{
		if (buffer[i] == '\n')
		{
			next_line = ft_substr(buffer, 0, i + 1);
			buffer = ft_substr(buffer, i+1, ft_strlen(buffer));
			return(next_line);
		}
		i++;
	}
	return ("");
}

#include <stdio.h> // printf
#include <fcntl.h> // open
int	main()
{
	char		*next_line;
	int			fd;

	fd = open("simplerTest.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Error opening file");
		return (0);
	}
	while (1)
	{
		next_line = get_next_line(fd);
		if (next_line == NULL)
			break;
		printf("%s", next_line);
	}
	return (0);
}