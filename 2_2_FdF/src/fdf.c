/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbooth <gbooth@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 14:35:18 by gbooth            #+#    #+#             */
/*   Updated: 2023/05/08 21:21:36 by gbooth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

void	free_matrix(t_point **matrix, unsigned int ncols)
{
	unsigned int	i;

	i = 0;
	while (i < ncols)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

int	close_window(t_data *data)
{
	mlx_loop_end(data->mlx);
	free_matrix(data->matrix, data->ncols);
	return (0);
}

void	init_params_keys(t_data *data)
{
	data->projection_mode = 2;
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

	matrix = (t_point **)malloc(nrows * sizeof(t_point *));
	i = 0;
	while (i < ncols)
	{
		matrix[i] = (t_point *)malloc(ncols * sizeof(t_point));
		i++;
	}
	return (matrix);
}

int	main(int nargs, char **argv)
{
	t_data	data;

	if (nargs < 2)
	{
		printf("%s", ERR_NO_FILENAME);
		return (0);
	}
	if (get_dimensions(argv[1], &data.nrows, &data.ncols) == -1)
	{
		printf(ERR_MATRIX_DIMS);
		return (0);
	}
	printf("%u %u\n", data.nrows, data.ncols);
	init_params_keys(&data);
	data.matrix = malloc_matrix(data.nrows, data.ncols);
	read_coords_from_file(argv[1], data.matrix);
	scale_to_window(&data);
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WIN_WIDTH, WIN_HEIGHT, "FDF");
	mlx_hook(data.win, 2, 1L << 0, on_key_press, &data);
	mlx_hook(data.win, 3, 1L << 1, on_key_release, &data);
	mlx_hook(data.win, 17, 1L << 0, close_window, &data);
	mlx_loop_hook(data.mlx, on_loop, &data);
	mlx_loop(data.mlx);
	return (0);
}
