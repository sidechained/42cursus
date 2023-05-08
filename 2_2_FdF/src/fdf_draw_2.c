/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbooth <gbooth@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 14:35:18 by gbooth            #+#    #+#             */
/*   Updated: 2023/05/08 21:20:50 by gbooth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

void	render(t_data *data)
{
	data->img = mlx_new_image(data->mlx, WIN_WIDTH, WIN_HEIGHT);
	data->addr = mlx_get_data_addr(data->img, \
		&data->bits_per_pixel, &data->line_length, &data->endian);
	plot_matrix(data);
	mlx_clear_window(data->mlx, data->win);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	plot_menu(data);
	mlx_destroy_image(data->mlx, data->img);
}

void	plot_menu(t_data *data)
{
	int	x;
	int	y;
	int	x_off;
	int	y_off;
	int	c;

	x = 5;
	y = 15;
	x_off = 500;
	y_off = 13;
	c = 0x00EAEA;
	mlx_string_put(data->mlx, data->win, x, y + y_off * 0, c, TXT_L1);
	mlx_string_put(data->mlx, data->win, x, y + y_off * 1, c, TXT_L2);
	mlx_string_put(data->mlx, data->win, x, y + y_off * 2, c, TXT_L3);
	mlx_string_put(data->mlx, data->win, x, y + y_off * 3, c, TXT_L4);
	mlx_string_put(data->mlx, data->win, x, y + y_off * 4, c, TXT_L5);
	mlx_string_put(data->mlx, data->win, x + x_off, y + y_off * 1, c, TXT_R1);
	mlx_string_put(data->mlx, data->win, x + x_off, y + y_off * 2, c, TXT_R2);
	mlx_string_put(data->mlx, data->win, x + x_off, y + y_off * 3, c, TXT_R3);
}

t_point_int	transform_point(t_data *data, t_point *p)
{
	t_point	pp;

	pp.x = p->x;
	pp.y = p->y;
	pp.z = p->z;
	if (data->projection_mode == 2)
	{
		z_scale(&pp, data->z_scale);
		isometric(&pp, data->iso_angle);
	}
	if (data->projection_mode == 3)
		conic(&pp, data->iso_angle, data->scale, data->z_scale);
	rotate(&pp, data->rot_angle);
	scale(&pp, data->scale);
	center(&pp, data->nrows, data->ncols, data->scale);
	translate(&pp, &data->translation);
	return (convert_to_int(&pp));
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
