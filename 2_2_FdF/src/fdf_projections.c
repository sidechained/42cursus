/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_projections.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbooth <gbooth@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 14:35:18 by gbooth            #+#    #+#             */
/*   Updated: 2023/05/08 19:40:58 by gbooth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

void	isometric(t_point *p, float angle)
{
	p->x = p->x + cos(angle) * p->z - cos(angle) * p->y;
	p->y = -(p->y) * sin(angle) - p->z * sin(angle);
}

// cx, cy, cz, f = Center of projection x, y, z coordinate, focal length
void	conic(t_point *p, float iso_angle, float scale, float z_scale)
{
	double	cx;
	double	cy;
	double	cz;
	double	f;
	float	d;

	cx = iso_angle;
	cy = iso_angle * 2;
	cz = z_scale * 5;
	f = scale / 20;
	d = sqrt((p->x - cx) * (p->x - cx) + (p->y - cy) * \
		(p->y - cy) + (p->z - cz) * (p->z - cz));
	p->x = f * (p->x - cx) / (d + cz - p->z);
	p->y = f * (p->y - cy) / (d + cz - p->z);
}
