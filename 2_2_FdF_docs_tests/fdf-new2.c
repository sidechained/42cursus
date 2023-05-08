#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, t_point_int *p, int color)
{
	char    *dst;

	if (p->x > 0 && p->y > 0 && p->x < WIN_WIDTH && p->y < WIN_HEIGHT)
	{
		dst = data->addr + (p->y * data->line_length + p->x * (data->bits_per_pixel / 8));
		*(int*)dst = color;
	}
}

t_point_int transform_point(t_data *data, t_point *p)
{
	t_point pp;

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
	return(convert_to_int(&pp));
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	plot_line2(t_data *data, t_point *cp, t_point_int *cp_, t_point_int *np_, t_line *l)
{
	int color;
	while (1)
	{	
		(void)cp;
		color = create_trgb(0, 255, 0, 0);
		my_mlx_pixel_put(data, cp_, color); //0x00FFFFFF
		if (cp_->x == np_->x && cp_->y == np_->y)
			break;
		l->e2 = 2*l->err;
		if (l->e2 >= l->dy)
		{
			l->err += l->dy;
			cp_->x += l->sx;
		}
		if (l->e2 <= l->dx)
		{
			l->err += l->dx;
			cp_->y += l->sy;
		}
	}
}
void	plot_line(t_data *data, unsigned int irow, unsigned int icol, bool vertical)
{
	t_line l;
	t_point *cp;
	t_point *np;
	t_point_int cp_;
	t_point_int np_;

	cp = &data->matrix[irow][icol];
	if (vertical == false)
		np = &data->matrix[irow+1][icol];
	else
		np = &data->matrix[irow][icol+1];
	cp_ = transform_point(data, cp);
	np_ = transform_point(data, np);
	l.dx = abs(np_.x - cp_.x);
	if (cp_.x < np_.x)
		l.sx = 1;
	else
		l.sx = -1;
	l.dy = -abs(np_.y - cp_.y);
	if (cp_.y < np_.y)
		l.sy = 1;
	else
		l.sy = -1;
	l.err = l.dx + l.dy;
	plot_line2(data, cp, &cp_, &np_, &l);
}

void	plot_matrix(t_data *data)
{
	unsigned int	irow;
	unsigned int	icol;

	irow = 0;
	icol = 0;
	while(icol < data->ncols)
	{
		while(irow < data->nrows)
		{
			if (data->projection_mode == 0)
			{
				t_point_int tp = transform_point(data, &data->matrix[irow][icol]);
				my_mlx_pixel_put(data, &tp, 0x00FFFFFF);
			}
			else
			{
				if (irow != data->nrows - 1)
					plot_line(data, irow, icol, false);
				if (icol != data->ncols - 1)
					plot_line(data, irow, icol, true);
			}
			irow++;
		}
		irow = 0;
		icol++;
	}
}

void	plot_menu(t_data *data)
{
	int x;
	int y;
	int x_off;
	int y_off;
	int color;

	x = 5;
	y = 15;
	x_off = 500;
	y_off = 13;
	color = 0x00EAEA;
	mlx_string_put(data->mlx, data->win, x, y + y_off * 0, color, "1 3 : -/+ zoom altitude");
	mlx_string_put(data->mlx, data->win, x, y + y_off * 1, color, "Q E : -/+ isometric angle");
	mlx_string_put(data->mlx, data->win, x, y + y_off * 2, color, "A D : -/+ rotation");
	mlx_string_put(data->mlx, data->win, x, y + y_off * 3, color, " S  : toggle projection mode");	
	mlx_string_put(data->mlx, data->win, x, y + y_off * 4, color, "Z C : -/+ zoom");
	mlx_string_put(data->mlx, data->win, x + x_off, y + y_off * 1, color, " ^ ");
	mlx_string_put(data->mlx, data->win, x + x_off, y + y_off * 2, color, "< > : move");
	mlx_string_put(data->mlx, data->win, x + x_off, y + y_off * 3, color, " v");	
}
