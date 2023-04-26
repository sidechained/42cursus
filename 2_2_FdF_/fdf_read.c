#include "fdf.h"

int	get_dimensions(char *filename, t_matrix3d *matrix3d)
{
	char	*next_line;
	int		fd;
	char 	**split_line;
	// int		prev_nrows;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		printf("Error opening file");
		return (-1);
	}
	matrix3d->ncols = 0;
	while (1)
	{
		next_line = get_next_line(fd);
		if(next_line == NULL)
			break;
		split_line = ft_split(next_line, ' ');
		matrix3d->nrows = 0;
		while(split_line[matrix3d->nrows])
			matrix3d->nrows++;
		// TODO: reimplement this check that all lines have equal num of elements
		// printf("nnn: %i %i\n", *nrows, prev_nrows);
		// if (*nrows > 0 && *nrows != prev_nrows)
		// 	return (-1);
		// prev_nrows = *nrows;
		free(next_line);
		matrix3d->ncols++;
	}
	close(fd);
	return (0);
}

// receiving fdf coordinates from a file and placing in a struct matrix of 3d points
int	read_coords_from_file(int fd, t_matrix3d *matrix3d)
{
	char		*next_line;
	char 		**split_line;
	int			irow;
	int 		icol;

	icol = 0;
	while (1)
	{
		next_line = get_next_line(fd);
		if(next_line == NULL)
			break;
		split_line = ft_split(next_line, ' ');
		irow = 0;
		while(split_line[irow])
		{
			matrix3d->points[irow][icol].axis = irow;
			matrix3d->points[irow][icol].ordinate = icol;
			matrix3d->points[irow][icol].altitude = ft_atoi(split_line[irow]);		
			irow++;
		}
		free(next_line);
		icol++;
	}
	close(fd);
	return (0);
}