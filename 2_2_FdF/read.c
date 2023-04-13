#include "fdf.h"

// determine how many rows and columns our file has
int	get_3d_matrix_dimensions(char *filename, int *nrows, int *ncols)
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
	*ncols = 0;
	while (1)
	{
		next_line = get_next_line(fd);
		if(next_line == NULL)
			break;
		split_line = ft_split(next_line, ' ');
		*nrows = 0;
		while(split_line[*nrows])
			(*nrows)++;
		// TODO: reimplement this check that all lines have equal num of elements
		// printf("nnn: %i %i\n", *nrows, prev_nrows);
		// if (*nrows > 0 && *nrows != prev_nrows)
		// 	return (-1);
		// prev_nrows = *nrows;
		free(next_line);
		(*ncols)++;
	}
	close(fd);
	return (0);
}

// receiving fdf coordinates from a file and placing in a struct matrix of 3d points
matrix_3d	*read_coords_from_file(char *filename, matrix_3d *matrix3d)
{
	char		*next_line;
	int			fd;
	char 		**split_line;
	int			irow;
	int 		icol;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		printf("Error opening file");
		return (NULL);
	}
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
			matrix3d->points[irow][icol].axis = irow * DEFAULT_SPACING;
			matrix3d->points[irow][icol].ordinate = icol * DEFAULT_SPACING;
			matrix3d->points[irow][icol].altitude = ft_atoi(split_line[irow]);		
			irow++;
		}
		free(next_line);
		icol++;
	}
	close(fd);
	return (matrix3d);
}