/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_projections.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbooth <gbooth@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 14:35:18 by gbooth            #+#    #+#             */
/*   Updated: 2023/05/10 14:35:32 by gbooth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

void	isometric(t_point *p, float angle)
{
	p->x = p->x + cos(angle) * p->z - cos(angle) * p->y;
	p->y = -(p->y) * sin(angle) - p->z * sin(angle);
}

void	conic(t_point *p, t_data *data)
{
	double	cx;
	double	cy;
	double	cz;
	double	f;
	float	d;

	cx = data->translation.x;
	cy = data->translation.y;
	cz = data->z_scale * 20;
	f = data->scale;

	d = sqrt((p->x - cx) * (p->x - cx) + (p->y - cy) * \
		(p->y - cy) + (p->z - cz) * (p->z - cz));
	d = d * 1.5;
	p->x = f * (p->x - cx) / (d + cz - p->z);
	p->y = f * (p->y - cy) / (d + cz - p->z);

}
