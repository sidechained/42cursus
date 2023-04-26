#include "fdf.h"

void	my_mlx_pixel_put(t_imgdata *imgdata, int x, int y, int color)
{
	char    *dst;

	dst = imgdata->addr + (y * imgdata->line_length + x * (imgdata->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	plot_line(t_imgdata *imgdata, t_point2d cp, t_point2d np, unsigned int win_width, unsigned int win_height)
{
	int dx;
	int sx;
	int dy;
	int sy;
	int err;
	int e2;

	dx =  abs((int)(np.x-cp.x));
	sx = cp.x<np.x ? 1 : -1;
	dy = -abs((int)(np.y-cp.y));
	sy = cp.y<np.y ? 1 : -1; 
	err = dx+dy;

	while (1)
	{
		if (cp.x < win_width && cp.y < win_height)
			my_mlx_pixel_put(imgdata, cp.x, cp.y, 0x00FF0000);
		if (cp.x==np.x && cp.y==np.y)
			break;
		e2 = 2*err;
		if (e2 >= dy)
		{
			err += dy;
			cp.x += sx;
		}
		if (e2 <= dx)
		{
			err += dx;
			cp.y += sy;
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
				plot_line(imgdata, matrix2d->points[irow][icol], matrix2d->points[irow+1][icol], matrix2d->win_width, matrix2d->win_height);
			}
			// if current col isn't last col, draw from current col to next col
			if (icol != matrix2d->ncols - 1)
			{	
				plot_line(imgdata, matrix2d->points[irow][icol], matrix2d->points[irow][icol+1], matrix2d->win_width, matrix2d->win_height);
			}
		irow++;
		}
		irow = 0;
		icol++;
	}
}

int		render(t_data *data)
{
	data->matrix2d->iso_angle = data->matrix2d->iso_angle + 0.5;
	convert_matrix(data->matrix3d, data->matrix2d);
	data->imgdata->img = mlx_new_image(data->mlx, data->matrix2d->win_width, data->matrix2d->win_height);
	data->imgdata->addr = mlx_get_data_addr(data->imgdata->img, &data->imgdata->bits_per_pixel, &data->imgdata->line_length, &data->imgdata->endian);
	plot_pixels(data->matrix2d, data->imgdata);
	mlx_clear_window(data->mlx, data->win);		
	mlx_put_image_to_window(data->mlx, data->win, data->imgdata->img, 0, 0);
	mlx_destroy_image(data->mlx, data->imgdata->img);
	return (0);
}