#include "libft.h"
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

# define ERR_NO_FILENAME "Error: No filename given"
# define ERR_OPENING_FILE "Error: Map file can not be opened\n"
# define ERR_MATRIX_TOO_SMALL "Error: Map should contain at least 2 rows and 2 columns\n"
# define ERR_MATRIX_MEMORY_ALLOC "Error: Could not allocate memory for map\n"
# define ERR_NON_DIGIT_IN_FILE "Error: Map file contains items \
other than digits\n"
# define ERR_IRREGULAR_ROWS "Error: Not all map rows have the \
same number of elements\n"

int	check_if_integer(unsigned int irow, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0 && irow != 0 && str[i] != '-')
			return (-1);
		i++;
	}
	return (0);
}

int	get_dims2(char **split_line, unsigned int *nrows, \
	unsigned int *ncols, unsigned int *prev_nrows)
{
	while (split_line[*nrows])
	{
		// if (check_if_integer(*nrows, split_line[*nrows]) == -1)
		// {
		// 	printf(ERR_NON_DIGIT_IN_FILE);
		// 	free(split_line[*nrows]);
		// 	return (-1);
		// }
		(*nrows)++;
	}
	unsigned int i = 0;
	while(i < *nrows)
	{
		free(split_line[i]);
		i++;
	}
	// if (*prev_nrows != 0 && *nrows != *prev_nrows)
	// {
	// 	printf(ERR_IRREGULAR_ROWS);
	// 	free(split_line);
	// 	return (-1);
	// }	
	*prev_nrows = *nrows;
	free(split_line);
	(*ncols)++;
	return (0);
}

int	get_dims(char *filename, unsigned int *ncols, \
	unsigned int *nrows, unsigned int *prev_nrows)
{
	char			*next_line;
	int				fd;
	char			**split_line;

	fd = open(filename, O_RDONLY);
	// if (fd == -1)
	// {
	// 	printf(ERR_OPENING_FILE);
	// 	return (-1);
	// }
	while (1)
	{
		next_line = get_next_line(fd);
		if (next_line == NULL)
			break ;
		if (next_line[ft_strlen(next_line) - 1] == '\n')
			next_line[ft_strlen(next_line) - 1] = '\0';
		split_line = ft_split(next_line, ' ');
		free(next_line);
		if (get_dims2(split_line, nrows, ncols, prev_nrows) == -1)
			return (-1);
	}
	close(fd);
	return (0);
}

int main()
{
	unsigned int	nrows;
	unsigned int	ncols;
	unsigned int	prev_nrows;

	nrows = 0;
	ncols = 0;
	prev_nrows = 0;

	get_dims("gnl_test.txt", &nrows, &ncols, &prev_nrows);
}