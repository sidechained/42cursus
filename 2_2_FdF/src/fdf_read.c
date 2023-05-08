/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbooth <gbooth@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 14:35:18 by gbooth            #+#    #+#             */
/*   Updated: 2023/05/08 21:14:38 by gbooth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
// open a file, get its next line
// split by ' ', iterate over split elements incrementing nrows
// if nrows differs from prev nrows (ever), return -1
// split elements must be integers
int	get_dimensions(char *filename, unsigned int *ncols, unsigned int *nrows)
{
	char			*next_line;
	int				fd;
	char			**split_line;
	unsigned int	prev_nrows;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		printf(ERR_OPENING_FILE);
		return (-1);
	}
	prev_nrows = 0;
	*ncols = 0;
	while (1)
	{
		next_line = get_next_line(fd);
		if (next_line == NULL)
			break ;
		if (next_line[ft_strlen(next_line) - 1] == '\n')
			next_line[ft_strlen(next_line) - 1] = '\0';
		split_line = ft_split(next_line, ' ');
		free(next_line);
		*nrows = 0;
		while (split_line[*nrows])
		{
			if (check_if_integer(*nrows, split_line[*nrows]) == -1)
				return (-1);
			free(split_line[*nrows]);
			(*nrows)++;
		}
		if (prev_nrows != 0 && *nrows != prev_nrows)
			return (-1);
		prev_nrows = *nrows;
		free(split_line);
		(*ncols)++;
	}
	close(fd);
	return (0);
}

// receiving fdf coordinates from a file
// and placing in a struct matrix of 3d points
int	read_coords_from_file(char *filename, t_point **matrix)
{
	int			fd;
	char		*next_line;
	char		**split_line;
	int			icol;
	int			irow;

	fd = open(filename, O_RDONLY);
	irow = 0;
	while (1)
	{
		next_line = get_next_line(fd);
		if (next_line == NULL)
			break ;
		if (next_line[ft_strlen(next_line) - 1] == '\n')
			next_line[ft_strlen(next_line) - 1] = '\0';
		split_line = ft_split(next_line, ' ');
		free(next_line);
		icol = 0;
		while (split_line[icol])
		{
			matrix[irow][icol].x = icol;
			matrix[irow][icol].y = irow;
			matrix[irow][icol].z = ft_atoi(split_line[icol]);
			free(split_line[icol]);
			icol++;
		}
		free(split_line);
		irow++;
	}
	close(fd);
	return (0);
}
