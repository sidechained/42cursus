#include "fdf.h"

void	my_mlx_pixel_put(t_imgdata *imgdata, int x, int y, int color)
{
	char    *dst;

	dst = imgdata->addr + (y * imgdata->line_length + x * (imgdata->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	plot_line(t_imgdata *imgdata, t_point2d cp, t_point2d np, t_matrix2d *matrix2d)
{
	t_line *l;

	l = matrix2d->line;
	l->dx = abs((int)(np.x - cp.x));
	if (cp.x < np.x)
		l->sx = 1;
	else
		l->sx = -1;
	l->dy = -abs((int)(np.y - cp.y));
	if (cp.y < np.y)
		l->sy = 1;
	else
		l->sy = -1;
	l->err = l->dx + l->dy;
	while (1)
	{
		if (cp.x < matrix2d->win_width && cp.y < matrix2d->win_height)
			my_mlx_pixel_put(imgdata, cp.x, cp.y, 0x00FFFFFF);
		if (cp.x==np.x && cp.y==np.y)
			break;
		l->e2 = 2*l->err;
		if (l->e2 >= l->dy)
		{
			l->err += l->dy;
			cp.x += l->sx;
		}
		if (l->e2 <= l->dx)
		{
			l->err += l->dx;
			cp.y += l->sy;
		}
	}
}

void	plot_pixels(t_matrix2d *matrix2d, t_imgdata *imgdata)
{
	unsigned int	irow;
	unsigned int	icol;

	irow = 0;
	icol = 0;
	while(icol < matrix2d->ncols)
	{
		while(irow < matrix2d->nrows)
		{
			// current row isn't last row, draw from current row to next row
			if (irow != matrix2d->nrows - 1)
			{
				plot_line(imgdata, matrix2d->points[irow][icol], matrix2d->points[irow+1][icol], matrix2d);
			}
			// if current col isn't last col, draw from current col to next col
			if (icol != matrix2d->ncols - 1)
			{	
				plot_line(imgdata, matrix2d->points[irow][icol], matrix2d->points[irow][icol+1], matrix2d);
			}
		irow++;
		}
		irow = 0;
		icol++;
	}
}

void	render(t_data *data)
{
	convert_matrix(data->matrix3d, data->matrix2d);
	data->imgdata->img = mlx_new_image(data->mlx, data->matrix2d->win_width, data->matrix2d->win_height);
	data->imgdata->addr = mlx_get_data_addr(data->imgdata->img, &data->imgdata->bits_per_pixel, &data->imgdata->line_length, &data->imgdata->endian);
	plot_pixels(data->matrix2d, data->imgdata);
	mlx_clear_window(data->mlx, data->win);		
	mlx_put_image_to_window(data->mlx, data->win, data->imgdata->img, 0, 0);
	mlx_destroy_image(data->mlx, data->imgdata->img);
}

void	increase_iso_angle(t_data *data)
{
	data->matrix2d->iso_angle = data->matrix2d->iso_angle + ISO_STEP;
}

void	decrease_iso_angle(t_data *data)
{
	data->matrix2d->iso_angle = data->matrix2d->iso_angle - ISO_STEP;
	render(data);
}

float	keep_rot_in_range(float angle)
{
	if (angle > MAX_ROTATION_ANGLE)
		angle = angle - MAX_ROTATION_ANGLE;
	if (angle < 0)
		angle = angle + MAX_ROTATION_ANGLE;
	// printf("a: %f\n", angle);
	return (angle);
}

void	increase_rot_angle(t_data *data)
{
	data->matrix2d->rot_angle = data->matrix2d->rot_angle + ROT_STEP;
	data->matrix2d->rot_angle = keep_rot_in_range(data->matrix2d->rot_angle);
	render(data);
}

void	decrease_rot_angle(t_data *data)
{
	data->matrix2d->rot_angle = data->matrix2d->rot_angle - ROT_STEP;
	data->matrix2d->rot_angle = keep_rot_in_range(data->matrix2d->rot_angle);
	render(data);
}

void	increase_zoom_level(t_data *data)
{
	data->matrix2d->zoom_level = data->matrix2d->zoom_level + ZOOM_STEP;
	render(data);
}

void	decrease_zoom_level(t_data *data)
{
	data->matrix2d->zoom_level = data->matrix2d->zoom_level - ZOOM_STEP;
	render(data);
}

void	translate_left(t_data *data)
{
	data->matrix2d->trans->x = data->matrix2d->trans->x - TRANS_STEP;
	render(data);
}

void	translate_right(t_data *data)
{
	data->matrix2d->trans->x = data->matrix2d->trans->x + TRANS_STEP;
	render(data);
}

void	translate_up(t_data *data)
{
	data->matrix2d->trans->y = data->matrix2d->trans->y - TRANS_STEP;
	render(data);
}

void	translate_down(t_data *data)
{
	data->matrix2d->trans->y = data->matrix2d->trans->y + TRANS_STEP;
	render(data);
}

int		key_hook(int keycode, t_data *data)
{
	// printf("%i\n", keycode);
	if (keycode == 65307) // ESC
	{
		mlx_destroy_window(data->mlx, data->win);
		mlx_loop_end(data->mlx); // exit the loop
	}
	// iso_angle
	if (keycode == 113) // 'Q'
		decrease_iso_angle(data);
	if (keycode == 101) // 'E'
		increase_iso_angle(data);
	// rotation
	if (keycode == 97) // 'A'
		decrease_rot_angle(data);
	if (keycode == 100) // 'D'
		increase_rot_angle(data);
	// zoom
	if (keycode == 121) // 'Z'
		decrease_zoom_level(data);
	if (keycode == 99) // 'C'
		increase_zoom_level(data);
	// translation
	if (keycode == 65361) // left arrow
		translate_left(data);
	if (keycode == 65363) // right arrow
		translate_right(data);	
	if (keycode == 65362) // up arrow
		translate_up(data);
	if (keycode == 65364) // down arrow
		translate_down(data);		
	return (0);
}
