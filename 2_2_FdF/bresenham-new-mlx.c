// C++ program for Bresenhams Line Generation
// https://www.geeksforgeeks.org/bresenhams-line-generation-algorithm/

#include <stdio.h>
#include <stdlib.h>
#include <mlx.h>

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

typedef struct	s_vars {
	void	*mlx;
	void	*win;
} t_vars;

typedef struct  s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
} t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char    *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
 
void plotPixel(t_data *img, int x1, int y1, int x2, int y2, int dx, int dy, int decide)
{
	int pk = 2 * dy - dx;
	for (int i = 0; i <= dx; i++) {
		// printf("%i %i\n", x1, y1);
		x1 < x2 ? x1++ : x1--;
		if (pk < 0) {
			if (decide == 0)
			{
				my_mlx_pixel_put(img, x1, y1, 0x00FF0000);
				pk = pk + 2 * dy;
			}
			else
			{
				my_mlx_pixel_put(img, y1, x1, 0x00FF0000);
				pk = pk + 2 * dy;
			}
		}
		else {
			y1 < y2 ? y1++ : y1--;
			if (decide == 0)
				my_mlx_pixel_put(img, x1, y1, 0x00FF0000);
			else
				my_mlx_pixel_put(img,y1, x1, 0x00FF0000);
			pk = pk + 2 * dy - 2 * dx;
		}
	}
}

void	plotPixel_anySlope(t_data *img, int x1, int y1, int x2, int y2)
{
	int dx;
	int dy;

	dx = abs(x2 - x1);
	dy = abs(y2 - y1);	
	if (dx > dy)
		plotPixel(img, x1, y1, x2, y2, dx, dy, 0);
	else
		plotPixel(img, y1, x1, y2, x2, dy, dx, 1); 
}

void	plotPrettyPatterns(t_data *img)
{
	int i, x1, y1, x2, y2;	
	i = 0;
	x1 = 5;
	y1 = 5;
	x2 = 95;
	y2 = 95;
	while(i < 50)
	{
		plotPixel_anySlope(img, x1, y1, x2, y2);
		x1 += 14;
		// y2 -= 2;
		y1 += 10;
		if (x1 < 0)
			x1 = 0;
		if (x1 > 200)
			x1 = 200;
		if (y1 < 0)
			y1 = 0;
		if (y1 > 200)
			y1 = 200;
		if (x2 < 0)
			x2 = 0;
		if (x2 > 200)
			x2 = 200;
		if (y2 < 0)
			y2 = 0;
		if (y2 > 200)
			y2 = 200;								
		i++;
	}
}

int	close(int keycode, void *mlx, void *mlx_win)
{
	mlx_destroy_window(mlx, mlx_win);
	return (0);
}

int main()
{
	t_vars	vars;
	t_data	img;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 200, 200, "Bresenham!");
	img.img = mlx_new_image(vars.mlx, 200, 200);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	// plotPixel_anySlope(&img, 30, 110, 125, 120);
	// plotPixel_anySlope(&img, 110, 125, 120, 30);
	// plotPixel_anySlope(&img, 125, 120, 30, 110);
	// plotPixel_anySlope(&img, 120, 30, 110, 125);
	plotPrettyPatterns(&img);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	// mlx_hook(vars.win, 2, 1L<<0, close, &vars);
	// mlx_hook(vars.win, 5, 1L<<0, close, &vars);
	mlx_loop(vars.mlx);
}