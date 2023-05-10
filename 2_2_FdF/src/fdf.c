/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbooth <gbooth@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 14:35:18 by gbooth            #+#    #+#             */
/*   Updated: 2023/05/10 15:34:32 by gbooth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

int	close_window(t_data *data)
{
	unsigned int	i;

	i = 0;
	while (i < data->nrows)
	{
		free(data->matrix[i]);
		i++;
	}
	mlx_loop_end(data->mlx);
	return (0);
}

void	init_params_keys(t_data *data)
{
	data->projection_mode = 0;
	data->iso_angle = 4.71238898;
	data->rot_angle = 0.7853981634 * 2;
	data->translation.x = 0;
	data->translation.y = 0;
	data->scale = 50;
	data->z_scale = 1;
	data->keypress_1 = false;
	data->keypress_3 = false;
	data->keypress_q = false;
	data->keypress_e = false;
	data->keypress_a = false;
	data->keypress_d = false;
	data->keypress_z = false;
	data->keypress_c = false;
	data->keypress_left_arrow = false;
	data->keypress_right_arrow = false;
	data->keypress_up_arrow = false;
	data->keypress_down_arrow = false;
}

t_point	**malloc_matrix(unsigned int nrows, unsigned int ncols)
{
	t_point			**matrix;
	unsigned int	i;

	matrix = (t_point **)malloc(sizeof(t_point *) * nrows);
	i = 0;
	while (i < nrows)
	{
		matrix[i] = malloc(sizeof(t_point) * ncols);
		i++;
	}
	return (matrix);
}

int	handle_winsize_arguments(int nargs, char **argv, t_data *data)
{
	if (nargs == 2 || nargs == 3)
	{
		data->win_width = 600;
		data->win_height = 600;
	}
	if (nargs == 4)
	{
		data->win_width = ft_atoi(argv[2]);
		data->win_height = ft_atoi(argv[3]);
		if (data->win_width > MAX_WIN_WIDTH)
			data->win_width = MAX_WIN_WIDTH;
		if (data->win_height > MAX_WIN_HEIGHT)
			data->win_height = MAX_WIN_HEIGHT;
		if (data->win_width < MIN_WIN_WIDTH)
		{
			ft_printf(WARN_MIN_WIDTH);
			data->win_width = MIN_WIN_WIDTH;
		}
		if (data->win_height < MIN_WIN_HEIGHT)
		{
			ft_printf(WARN_MIN_HEIGHT);
			data->win_height = MIN_WIN_HEIGHT;
		}
	}
	return (0);
}

int	main(int nargs, char **argv)
{
	t_data	data;
	t_line	l;

	if (nargs < 2)
	{
		ft_printf(ERR_NO_FILENAME);
		return (-1);
	}
	if (handle_winsize_arguments(nargs, argv, &data) == -1)
		return (0);
	if (get_dimensions(argv[1], &data.nrows, &data.ncols) == -1)
		return (0);
	init_params_keys(&data);
	data.matrix = malloc_matrix(data.nrows, data.ncols);
	data.l = &l;
	read_coords_from_file(argv[1], data.matrix, &data);
	scale_to_window(&data);
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, data.win_width, data.win_height, "FDF");
	mlx_hook(data.win, 2, 1L << 0, on_key_press, &data);
	mlx_hook(data.win, 3, 1L << 1, on_key_release, &data);
	mlx_hook(data.win, 17, 1L << 0, close_window, &data);
	mlx_loop_hook(data.mlx, on_loop, &data);
	mlx_loop(data.mlx);
	return (0);
}
