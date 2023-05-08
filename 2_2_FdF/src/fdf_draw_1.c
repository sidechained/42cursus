/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbooth <gbooth@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 14:35:18 by gbooth            #+#    #+#             */
/*   Updated: 2023/05/08 20:31:00 by gbooth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, t_point_int *p, int color)
{
	char	*dst;

	if (p->x > 0 && p->y > 0 && p->x < WIN_WIDTH && p->y < WIN_HEIGHT)
	{
		dst = data->addr + \
			(p->y * data->line_length + p->x * (data->bits_per_pixel / 8));
		*(int *)dst = color;
	}
}

//0x00FFFFFF
void	plot_line2(t_data *data, t_point *cp, \
	t_point_int *cp_, t_point_int *np_)
{
	int	color;

	while (1)
	{	
		(void)cp;
		color = create_trgb(0, 255, 0, 0);
		my_mlx_pixel_put(data, cp_, color);
		if (cp_->x == np_->x && cp_->y == np_->y)
			break ;
		data->l->e2 = 2 * data->l->err;
		if (data->l->e2 >= data->l->dy)
		{
			data->l->err += data->l->dy;
			cp_->x += data->l->sx;
		}
		if (data->l->e2 <= data->l->dx)
		{
			data->l->err += data->l->dx;
			cp_->y += data->l->sy;
		}
	}
}

void	plot_line(t_data *data, unsigned int irow, unsigned int icol, bool vert)
{
	t_point		*cp;
	t_point		*np;
	t_point_int	cp_;
	t_point_int	np_;

	cp = &data->matrix[irow][icol];
	if (vert == false)
		np = &data->matrix[irow + 1][icol];
	else
		np = &data->matrix[irow][icol + 1];
	cp_ = transform_point(data, cp);
	np_ = transform_point(data, np);
	data->l->dx = abs(np_.x - cp_.x);
	if (cp_.x < np_.x)
		data->l->sx = 1;
	else
		data->l->sx = -1;
	data->l->dy = -abs(np_.y - cp_.y);
	if (cp_.y < np_.y)
		data->l->sy = 1;
	else
		data->l->sy = -1;
	data->l->err = data->l->dx + data->l->dy;
	plot_line2(data, cp, &cp_, &np_);
}

void	plot_lines(t_data *data, unsigned int irow, unsigned int icol)
{
	if (irow != data->nrows - 1)
		plot_line(data, irow, icol, false);
	if (icol != data->ncols - 1)
		plot_line(data, irow, icol, true);
}

void	plot_matrix(t_data *data)
{
	unsigned int	irow;
	unsigned int	icol;
	t_point_int		tp;

	irow = 0;
	icol = 0;
	while (icol < data->ncols)
	{
		while (irow < data->nrows)
		{
			if (data->projection_mode == 0)
			{
				tp = transform_point(data, &data->matrix[irow][icol]);
				my_mlx_pixel_put(data, &tp, 0x00FFFFFF);
			}
			else
			{
				plot_lines(data, irow, icol);
			}
			irow++;
		}
		irow = 0;
		icol++;
	}
}
