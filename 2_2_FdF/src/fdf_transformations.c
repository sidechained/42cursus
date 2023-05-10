/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_transformations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbooth <gbooth@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 14:35:18 by gbooth            #+#    #+#             */
/*   Updated: 2023/05/09 21:51:05 by gbooth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

void	rotate(t_point *p, float angle)
{
	float	tx;
	float	ty;

	tx = p->x;
	ty = p->y;
	p->x = tx * cos(angle) - ty * sin(angle);
	p->x = tx * sin(angle) + ty * cos(angle);
}

void	translate(t_point *p, t_point *t)
{
	p->x = p->x + t->x;
	p->y = p->y + t->y;
}

void	center(t_point *p, t_data *data)
{
	p->x = p->x - data->ncols * data->scale / 2;
	p->y = p->y - data->nrows * data->scale / 2;
	p->x = p->x + data->win_width / 2;
	p->y = p->y + data->win_height / 2;
}

void	scale(t_point *p, float scale)
{
	p->x = p->x * scale;
	p->y = p->y * scale;
}

void	z_scale(t_point *p, float z_scale)
{
	p->z = p->z * z_scale * 0.3;
}
