/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbooth <gbooth@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 14:35:18 by gbooth            #+#    #+#             */
/*   Updated: 2023/05/09 21:47:56 by gbooth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

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

void	scale_to_window(t_data *data)
{
	float	w;
	float	h;

	if (data->scale * (data->nrows - 1) > data->win_width)
		w = data->win_width / (data->nrows - 1) * 0.75;
	else
		w = data->scale;
	if (data->scale * (data->ncols - 1) > data->win_height)
		h = data->win_height / (data->ncols - 1) * 0.75;
	else
		h = data->scale;
	if (w < h)
		data->scale = w;
	else
		data->scale = h;
}

void	keep_angle_in_range(float *rot_angle)
{
	if (*rot_angle > MAX_ROTATION_ANGLE)
		*rot_angle = *rot_angle - MAX_ROTATION_ANGLE;
	if (*rot_angle < 0)
		*rot_angle = *rot_angle + MAX_ROTATION_ANGLE;
}

void	print_matrix(t_point **matrix, unsigned int nrows, unsigned int ncols)
{
	unsigned int	irow;
	unsigned int	icol;

	irow = 0;
	icol = 0;
	while (icol < ncols)
	{
		while (irow < nrows)
		{
			ft_printf("[%i][%i]:\n", irow, icol);
			ft_printf(" x: %f\n", matrix[irow][icol].x);
			ft_printf(" y: %f\n", matrix[irow][icol].y);
			ft_printf(" z: %f\n", matrix[irow][icol].z);
			irow++;
		}
		irow = 0;
		icol++;
	}
}

t_point_int	convert_to_int(t_point *p)
{
	t_point_int	pp;

	pp.x = (int)round(p->x);
	pp.y = (int)round(p->y);
	return (pp);
}
