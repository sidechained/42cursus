/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbooth <gbooth@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 14:35:18 by gbooth            #+#    #+#             */
/*   Updated: 2023/05/10 15:10:03 by gbooth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, t_point_int *p, int color)
{
	char	*dst;

	if (p->x > 0 && p->y > 0 && p->x < data->win_width && \
		p->y < data->win_height)
	{
		dst = data->addr + \
			(p->y * data->line_length + p->x * (data->bits_per_pixel / 8));
		*(int *)dst = color;
	}
}

void	render(t_data *data)
{
	data->img = mlx_new_image(data->mlx, data->win_width, data->win_height);
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

	x_off = data->win_width - 100;
	y_off = 13;
	x = 20;
	y = data->win_height - y_off * 5;
	c = 0x00EAEA;
	mlx_string_put(data->mlx, data->win, x, y + y_off * 0, c, TXT_L1);
	mlx_string_put(data->mlx, data->win, x, y + y_off * 1, c, TXT_L2);
	mlx_string_put(data->mlx, data->win, x, y + y_off * 2, c, TXT_L3);
	mlx_string_put(data->mlx, data->win, x, y + y_off * 3, c, TXT_L4);
	mlx_string_put(data->mlx, data->win, x, y + y_off * 4, c, TXT_L5);
	mlx_string_put(data->mlx, data->win, x_off, y + y_off * 1, c, TXT_R1);
	mlx_string_put(data->mlx, data->win, x_off, y + y_off * 2, c, TXT_R2);
	mlx_string_put(data->mlx, data->win, x_off, y + y_off * 3, c, TXT_R3);
}

t_point_int	transform_point(t_data *data, t_point *p)
{
	t_point	pp;

	pp.x = p->x;
	pp.y = p->y;
	pp.z = p->z;
	if (data->projection_mode == POINTS_ISO || \
		data->projection_mode == LINES_ISO)
	{
		z_scale(&pp, data->z_scale);
		isometric(&pp, data->iso_angle);
	}
	if (data->projection_mode == POINTS_CONIC || \
		data->projection_mode == LINES_CONIC)
		conic(&pp, data);
	rotate(&pp, data->rot_angle);
	scale(&pp, data->scale);
	if (data->projection_mode != POINTS_CONIC || \
		data->projection_mode != LINES_CONIC)
		center(&pp, data);
	if (data->projection_mode != POINTS_CONIC || \
		data->projection_mode != LINES_CONIC)
		translate(&pp, &data->translation);
	return (convert_to_int(&pp));
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
