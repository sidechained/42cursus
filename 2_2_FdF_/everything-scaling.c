// TODO: int to unsigned int
// TODO: change angle in realtime using key events

// TODO: large altitudes
// TODO: realtime rotation of angle using A and D keys
// TODO: separation of rotation and perspective

// loop_hook for auto-rotation
// in line function, detect out of bounds and don't print
// centre values
// leave a default amount of space around

#include <stdio.h>
#include <stdlib.h>
#include <mlx.h>
#include <math.h>
#include <fcntl.h> // open
#include "get_next_line/get_next_line.h"
#include "libft/libft.h"

#define DEFAULT_SPACING 20
#define MAX_WIN_WIDTH 600
#define MAX_WIN_HEIGHT 600

// cc -Wall -Werror -Wextra -ggdb3 everything-scaling.c get_next_line/get_next_line.c libft/ft_strlen.c libft/ft_substr.c libft/ft_strjoin.c libft/ft_strdup.c libft/ft_split.c libft/ft_atoi.c libft/ft_isdigit.c -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz && ./a.out

typedef struct point_3d
{
	float axis;
	float ordinate;
	float altitude;
} point_3d;

typedef struct matrix_3d
{
	point_3d	**points;
} matrix_3d;

typedef struct point_2d
{
	float x;
	float y;
} point_2d;

typedef struct matrix_2d
{
	point_2d		**points;
	unsigned int	win_width;
	unsigned int	win_height;
	float			zoom_level;
} matrix_2d;

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

int	get_3d_matrix_dimensions(char *filename, int *nrows, int *ncols)
{
	char	*next_line;
	int		fd;
	char 	**split_line;
	// int		prev_nrows;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		printf("Error opening file");
		return (-1);
	}
	*ncols = 0;
	while (1)
	{
		next_line = get_next_line(fd);
		if(next_line == NULL)
			break;
		split_line = ft_split(next_line, ' ');
		*nrows = 0;
		while(split_line[*nrows])
			(*nrows)++;
		// TODO: reimplement this check that all lines have equal num of elements
		// printf("nnn: %i %i\n", *nrows, prev_nrows);
		// if (*nrows > 0 && *nrows != prev_nrows)
		// 	return (-1);
		// prev_nrows = *nrows;
		free(next_line);
		(*ncols)++;
	}
	close(fd);
	return (0);
}

// receiving fdf coordinates from a file and placing in a struct matrix of 3d points
matrix_3d	*read_coords_from_file(char *filename, matrix_3d	*matrix3d)
{
	char		*next_line;
	int			fd;
	char 		**split_line;
	int			irow;
	int 		icol;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		printf("Error opening file");
		return (NULL);
	}
	icol = 0;
	while (1)
	{
		next_line = get_next_line(fd);
		if(next_line == NULL)
			break;
		split_line = ft_split(next_line, ' ');
		irow = 0;
		while(split_line[irow])
		{
			matrix3d->points[irow][icol].axis = irow;
			matrix3d->points[irow][icol].ordinate = icol;
			matrix3d->points[irow][icol].altitude = ft_atoi(split_line[irow]);		
			irow++;
		}
		free(next_line);
		icol++;
	}
	close(fd);
	return (matrix3d);
}

matrix_3d	*create_3d_matrix(int nrows, int ncols)
{
	int i;

	matrix_3d	*matrix3d = malloc(sizeof(matrix_3d));
    point_3d	*values = malloc(nrows*ncols*sizeof(point_3d)); // enough memory for all the values
    point_3d	**points = malloc(nrows*sizeof(point_3d*)); // these are pointers to ints (existing ones?)
    i = 0;
    while(i < nrows)
    {
        points[i] = values + i*ncols; // increment the values pointer 
    	i++;
    }
    matrix3d->points = points;
    return (matrix3d);
}

float	calc_zoom_level_and_window_size(matrix_2d *matrix2d, int nrows, int ncols)
{
	unsigned int proposed_win_width;
	unsigned int proposed_win_height;
	float w;
	float h;

	proposed_win_width = DEFAULT_SPACING * (nrows - 1) + 1;
	proposed_win_height = DEFAULT_SPACING * (ncols - 1) + 1;

	if (proposed_win_width > MAX_WIN_WIDTH)
	{
		matrix2d->win_width = MAX_WIN_WIDTH;
		w = MAX_WIN_WIDTH / nrows;
	}
	else
	{
		matrix2d->win_width = proposed_win_width;
		w = DEFAULT_SPACING;
	}

	if (proposed_win_height > MAX_WIN_HEIGHT)
	{
		matrix2d->win_height = MAX_WIN_HEIGHT;
		h = MAX_WIN_HEIGHT / ncols;
	}
	else
	{
		matrix2d->win_height = proposed_win_height;
		h = DEFAULT_SPACING;
	}

	if (w < h)
		return(w);

	return(h);
}

matrix_2d	*create_2d_matrix(int nrows, int ncols)
{
	int i;

	matrix_2d *matrix2d = malloc(sizeof(matrix_2d));

    point_2d* values = malloc(nrows*ncols*sizeof(point_2d)); // enough memory for all the values
    point_2d** points = malloc(nrows*sizeof(point_2d*)); // these are pointers to ints (existing ones?)
    i = 0;
    while(i < nrows)
    {
        points[i] = values + i*ncols; // increment the values pointer 
    	i++;
    }
    matrix2d->points = points;
    return (matrix2d);
}

// ideally we would take a pointer to matrix 3d, to avoid copying and extra memory usage
matrix_2d	*convert_matrix_from_3d_to_2d(matrix_3d	*matrix3d, int nrows, int ncols)
{
	int irow;
	int icol;
	float angle;
	matrix_2d	*matrix2d;
	float zoom_level;

	irow = 0;
	icol = 0;
	angle = 0.7853981634; // 45 degrees
	matrix2d = create_2d_matrix(nrows, ncols);
	zoom_level = calc_zoom_level_and_window_size(matrix2d, nrows, ncols);
	printf("%f\n", zoom_level);
	while(icol < ncols)
	{
		while(irow < nrows)
		{
			matrix2d->points[irow][icol].x = matrix3d->points[irow][icol].axis + cos(angle) * matrix3d->points[irow][icol].altitude - cos(angle) * matrix3d->points[irow][icol].ordinate;
			matrix2d->points[irow][icol].y = -(matrix3d->points[irow][icol].ordinate) * sin(angle) - matrix3d->points[irow][icol].altitude * sin(angle);	
			// (void)angle;
			// matrix2d->points[irow][icol].x = matrix3d->points[irow][icol].axis * zoom_level;
			// matrix2d->points[irow][icol].y = matrix3d->points[irow][icol].ordinate * zoom_level;
			irow++;
		}
		irow = 0;
		icol++;
	}
	return(matrix2d);
}

// ideally we would take a pointer to matrix 3d, to avoid copying and extra memory usage
matrix_2d	*scale_matrix_2d(matrix_2d *matrix2d, int nrows, int ncols)
{
	int irow;
	int icol;

	irow = 0;
	icol = 0;
	while(icol < ncols)
	{
		while(irow < nrows)
		{
			// goes from -2 to 2, should go from 0 to WINDOW_WIDTH or WINDOW_HEIGHT
			matrix2d->points[irow][icol].x += 2;
			matrix2d->points[irow][icol].x /= 4;		
			matrix2d->points[irow][icol].x *= matrix2d->win_width; // place this as a parameter of matrix2d?
			matrix2d->points[irow][icol].y += 2;
			matrix2d->points[irow][icol].y /= 4;		
			matrix2d->points[irow][icol].y *= matrix2d->win_height; // place this as a parameter of matrix2d?		
			irow++;
		}
		irow = 0;
		icol++;
	}
	return(matrix2d);
}

void	print_2d_matrix(matrix_2d *matrix2d, int nrows, int ncols)
{
	int	irow = 0;
	int	icol = 0;

	while(icol < nrows)
	{
		while(irow < ncols)
		{
			printf("[%i][%i]:\n", irow, icol);
			printf(" x: %f\n", (matrix2d->points[irow] + icol)->x);	
			printf(" y: %f\n", (matrix2d->points[irow] + icol)->y);
			irow++;
		}
		irow = 0;
		icol++;
	}
}

void	print_3d_matrix(matrix_3d	*matrix3d, int nrows, int ncols)
{
	int	irow = 0;
	int	icol = 0;

	while(icol < nrows)
	{
		while(irow < ncols)
		{
			printf("[%i][%i]:\n", irow, icol);
			printf(" axis: %f\n", (matrix3d->points[irow] + icol)->axis);	
			printf(" ord : %f\n", (matrix3d->points[irow] + icol)->ordinate);
			printf(" alt : %f\n", (matrix3d->points[irow] + icol)->altitude);
			irow++;
		}
		irow = 0;
		icol++;
	}
}

matrix_2d *calc_matrices(char *filename, int *nrows, int *ncols)
{
	matrix_3d	*matrix3d;
	matrix_2d	*matrix2d;

	get_3d_matrix_dimensions(filename, nrows, ncols); // HANDLE NULL!
	matrix3d = create_3d_matrix(*nrows, *ncols);
	matrix3d = read_coords_from_file(filename, matrix3d); // HANDLE NULL!
	matrix2d = convert_matrix_from_3d_to_2d(matrix3d, *nrows, *ncols);

	matrix2d = scale_matrix_2d(matrix2d, *nrows, *ncols);
	print_2d_matrix(matrix2d, *nrows, *ncols);
	
	return (matrix2d);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char    *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	plot_line(t_data *img, point_2d cp, point_2d np, unsigned int win_width, unsigned int win_height)
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
			my_mlx_pixel_put(img, cp.x, cp.y, 0x00FF0000);
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

void	plot_pixels(matrix_2d *matrix2d, t_data *img, int nrows, int ncols)
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

	plot_pixels(matrix2d, &img, nrows, ncols);
	
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_loop(vars.mlx);
}

int		main(int nargs, char **argv)
{
	int			nrows;
	int			ncols;
	matrix_2d	*matrix2d;
	char 		*filename;

	if (nargs < 2)
	{
		printf("%s", "You must supply a filename!\n");
		return (0);
	}
	filename = argv[1];
	matrix2d = calc_matrices(filename, &nrows, &ncols);
	plot_to_window(matrix2d, nrows, ncols);
	return (0);
}
