/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbooth <gbooth@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 14:35:18 by gbooth            #+#    #+#             */
/*   Updated: 2023/05/11 12:02:51 by gbooth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

void	find_min_max_z(t_point **matrix, t_data *data)
{
	float			current_z;
	unsigned int	irow;
	unsigned int	icol;

	data->min_z = matrix[0][0].z;
	data->max_z = matrix[0][0].z;
	irow = 0;
	while (irow < data->nrows)
	{	
		icol = 0;
		while (icol < data->ncols)
		{
			current_z = matrix[irow][icol].z;
			if (current_z < data->min_z)
				data->min_z = current_z;
			if (current_z > data->max_z)
				data->max_z = current_z;
			icol++;
		}
		irow++;
	}
}

int	get_dims2(char **split_line, unsigned int *nrows, \
	unsigned int *ncols, unsigned int *prev_nrows)
{
	while (split_line[*nrows])
	{
		if (check_if_integer(*nrows, split_line[*nrows]) == -1)
		{
			ft_printf(ERR_NON_DIGIT_IN_FILE);
			free_split_line(nrows, split_line);
			return (-1);
		}
		(*nrows)++;
	}
	if (*prev_nrows != 0 && *nrows != *prev_nrows)
	{
		ft_printf(ERR_IRREGULAR_ROWS);
		free_split_line(nrows, split_line);
		return (-1);
	}
	*prev_nrows = *nrows;
	free_split_line(nrows, split_line);
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
	if (fd == -1)
	{
		ft_printf(ERR_OPENING_FILE);
		return (-1);
	}
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

int	read_coords_from_file2(char **split_line, t_point **matrix, \
	unsigned int *irow)
{
	unsigned int	icol;

	icol = 0;
	while (split_line[icol])
	{
		matrix[*irow][icol].x = icol;
		matrix[*irow][icol].y = *irow;
		matrix[*irow][icol].z = ft_atoi(split_line[icol]);
		free(split_line[icol]);
		icol++;
	}
	free(split_line);
	return (0);
}

int	read_coords_from_file(char *filename, t_point **matrix, t_data *data)
{
	int				fd;
	char			*next_line;
	char			**split_line;
	unsigned int	irow;

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
		read_coords_from_file2(split_line, matrix, &irow);
		irow++;
	}
	find_min_max_z(matrix, data);
	close(fd);
	return (0);
}
