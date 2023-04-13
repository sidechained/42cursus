// TODO: integrate insights from "returning_pointer_to_multidim_array_of_structs_using_malloc.c" and follow that approach in what's given below

#include <stdio.h>
#include <stdlib.h>
#include <mlx.h>
#include <math.h>

// cc 3d-to-2d.c -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz && ./a.out

typedef struct point3d
{
	unsigned int axis;
	unsigned int ordinate;
	int altitude;
} point3d;

typedef struct point2d
{
	unsigned int x;
	unsigned int y;
} point2d;

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


void	generate_3d_matrix(int nrows, int ncols, point3d *matrix_3d)
{
	int irow;
	int icol;

	irow = 0;
	icol = 0;

	while(icol < ncols)
	{
		while(irow < nrows)
		{
			matrix_3d[irow][icol]->axis = irow;
			matrix_3d[irow][icol]->ordinate = icol;
			matrix_3d[irow][icol]->altitude = 0; // no altitude for now
			icol++;
		}
		irow = 0;
		icol++;
	}
}

void	convert_matrix_from_3d_to_2d(int nrows, int ncols, point3d matrix_3d[nrows][ncols])
{
	int irow;
	int icol;
	int angle;

	irow = 0;
	icol = 0;
	angle = 0.7853981634; // 45 degrees
	point2d matrix_2d[nrows][ncols];
	while(icol < ncols)
	{
		while(irow < nrows)
		{
			matrix_2d[irow][icol].x = matrix_3d[irow][icol].axis + cos(angle) * matrix_3d[irow][icol].altitude - cos(angle) * matrix_3d[irow][icol].ordinate;
			matrix_2d[irow][icol].y = -matrix_3d[irow][icol].ordinate * sin(angle) - matrix_3d[irow][icol].altitude * sin(angle);
			icol++;
		}
		irow = 0;
		icol++;
	}
	// scaling:
	// return(matrix_2d);
}

void print_2d_matrix(int nrows, int ncols, point2d *matrix_3d[nrows][ncols])
{
	int irow;
	int icol;

	irow = 0;
	icol = 0;

	while(icol < ncols)
	{
		while(irow < nrows)
		{
			printf("[%i][%i]%i %i x, y ", irow, icol, matrix_3d[irow][icol]->x, matrix_3d[irow][icol]->y);
			icol++;
		}
		printf("\n");
		irow = 0;
		icol++;
	}
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char    *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
 
void	plotPixel(t_data *img, int x1, int y1, int x2, int y2, int dx, int dy, int decide)
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

int		main()
{
	// t_vars	vars;
	// t_data	img;

	int		nrows;
	int		ncols;

	// vars.mlx = mlx_init();
	// vars.win = mlx_new_window(vars.mlx, 200, 200, "Bresenham!");
	// img.img = mlx_new_image(vars.mlx, 200, 200);
	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

	nrows = 3;
	ncols = 3;
	point3d matrix_3d[nrows][ncols];
	// point2d matrix_2d[nrows][ncols];
	generate_3d_matrix(nrows, ncols, &matrix_3d);
	// matrix_2d = convert_matrix_from_3d_to_2d(matrix_3d, nrows, ncols);
	// print_2d_matrix(matrix_2d);
	// plotPixel_anySlope(&img, 30, 110, 125, 120);
	// plotPixel_anySlope(&img, 110, 125, 120, 30);
	// plotPixel_anySlope(&img, 125, 120, 30, 110);
	// plotPixel_anySlope(&img, 120, 30, 110, 125);

	// mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	// mlx_loop(vars.mlx);
	return (0);
}
