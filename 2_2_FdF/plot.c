#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char    *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

// cp = current point (draw line from)
// np = next point (draw line to)
// we keep moving cp and drawing a pixel there until it's coordinates equal or exceed np (the point to draw to)
void	plot_line(t_data *img, point_2d cp, point_2d np, unsigned int win_width, unsigned int win_height)
{
	int dx;
	int sx;
	int dy;
	int sy;
	int err;
	int e2;
	int g;

	// this fix kind of works but we get extra pixels
	if (cp.x>=np.x && cp.y>=np.y)
		g = 1;
	else
		g = 0;

	dx =  abs((int)(np.x-cp.x));
	sx = (int)cp.x<np.x ? 1 : -1;
	dy = -abs((int)(np.y-cp.y));
	sy = (int)cp.y<np.y ? 1 : -1; 
	err = dx+dy;

	while (1)
	{
		// printf("cp.x %f cp.y %f np.x %f np.y %f\n", cp.x, cp.y, np.x, np.y);
		if (cp.x < win_width && cp.y < win_height && cp.x > 0 && cp.y > 0)
			my_mlx_pixel_put(img, cp.x, cp.y, 0x00FF0000);
		if ((g == 1 && cp.x<=np.x && cp.y<=np.y) || (g == 0 && cp.x>=np.x && cp.y>=np.y))
			break ;
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

void	plot_pixels(matrix_2d *matrix2d, t_data *img, int nrows, int ncols)
{
	int	irow = 0;
	int	icol = 0;

	while(icol < ncols)
	{
		while(irow < nrows)
		{
			my_mlx_pixel_put(img, matrix2d->points[irow][icol].x, matrix2d->points[irow][icol].y, 0x00FFFF00);
			irow++;
		}
		irow = 0;
		icol++;
	}
}

// iterate over 2d matrix colwise, then rowwise, up to nrows/ncols - 1
// draw a line from the current point to the next point right
// draw a line from the current point to the next point down
void	plot_lines(matrix_2d *matrix2d, t_data *img, int nrows, int ncols)
{
	int	irow = 0;
	int	icol = 0;

	while(icol < ncols)
	{
		while(irow < nrows)
		{
			if (irow < (nrows - 1))
				plot_line(img, matrix2d->points[irow][icol], matrix2d->points[irow+1][icol], matrix2d->win_width, matrix2d->win_height);
			if (icol < (ncols - 1))
				plot_line(img, matrix2d->points[irow][icol], matrix2d->points[irow][icol+1], matrix2d->win_width, matrix2d->win_height);
			irow++;
		}
		irow = 0;
		icol++;
	}
}

void	plot_to_window(matrix_2d *matrix2d, int nrows, int ncols)
{
	t_vars	vars;
	t_data	img;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, matrix2d->win_width, matrix2d->win_height, "Everything!");
	img.img = mlx_new_image(vars.mlx, matrix2d->win_width, matrix2d->win_height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	plot_lines(matrix2d, &img, nrows, ncols);
	plot_pixels(matrix2d, &img, nrows, ncols);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_loop(vars.mlx);
}
