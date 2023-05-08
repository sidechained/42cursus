/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_transformations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbooth <gbooth@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 14:35:18 by gbooth            #+#    #+#             */
/*   Updated: 2023/05/08 19:41:09 by gbooth           ###   ########.fr       */
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

void	center(t_point *p, unsigned int nrows, unsigned int ncols, float scale)
{
	p->x = p->x - nrows * scale / 2;
	p->y = p->y - ncols * scale / 2;
	p->x = p->x + WIN_WIDTH / 2;
	p->y = p->y + WIN_HEIGHT / 2;
}

void	scale(t_point *p, float scale)
{
	p->x = p->x * scale;
	p->y = p->y * scale;
}

void	z_scale(t_point *p, float z_scale)
{
	p->z = p->z * z_scale;
}
