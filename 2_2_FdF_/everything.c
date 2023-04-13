// TODO: int to unsigned int
// TODO: change angle in realtime using key events
// TODO: filename as arg

// TODO: scaling
//	- replicate binary
//	- large maps give large windows
//  - large altitudes
//  - default spacing of 10 pixels or so, up until the max window width or height
//	- window_width = nrows * DEFAULT_SPACING
//  - window_height = ncols * DEFAULT_SPACING
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

#define DEFAULT_SPACING 30
// cc -Wall -Werror -Wextra -ggdb3 everything.c get_next_line/get_next_line.c libft/ft_strlen.c libft/ft_substr.c libft/ft_strjoin.c libft/ft_strdup.c libft/ft_split.c libft/ft_atoi.c libft/ft_isdigit.c -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz && ./a.out

typedef struct point3d
{
	float axis;
	float ordinate;
	float altitude;
} point3d;

typedef struct point2d
{
	float x;
	float y;
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
point3d**	read_coords_from_file(char *filename, point3d** matrix3d)
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
			matrix3d[irow][icol].axis = irow;
			matrix3d[irow][icol].ordinate = icol;
			matrix3d[irow][icol].altitude = ft_atoi(split_line[irow]);		
			irow++;
		}
		free(next_line);
		icol++;
	}
	close(fd);
	return (matrix3d);
}

point3d**	create_3d_matrix(int nrows, int ncols)
{
	int i;
    point3d* values = malloc(nrows*ncols*sizeof(point3d)); // enough memory for all the values
    point3d** matrix3d = malloc(nrows*sizeof(point3d*)); // these are pointers to ints (existing ones?)

    i = 0;
    while(i < nrows)
    {
        matrix3d[i] = values + i*ncols; // increment the values pointer 
    	i++;
    }
    return (matrix3d);
}

point2d**	create_2d_matrix(int nrows, int ncols)
{
	int i;
    point2d* values = malloc(nrows*ncols*sizeof(point2d)); // enough memory for all the values
    point2d** matrix2d = malloc(nrows*sizeof(point2d*)); // these are pointers to ints (existing ones?)

    i = 0;
    while(i < nrows)
    {
        matrix2d[i] = values + i*ncols; // increment the values pointer 
    	i++;
    }
    return (matrix2d);
}

// ideally we would take a pointer to matrix 3d, to avoid copying and extra memory usage
point2d**	convert_matrix_from_3d_to_2d(point3d** matrix3d, int nrows, int ncols)
{
	int irow;
	int icol;
	float angle;
	// float angle2;
	point2d** matrix2d;

	irow = 0;
	icol = 0;
	// angle = 0;
	angle = 0.7853981634; // 45 degrees
	// angle2 = 1,5708; // 45 degrees
	// angle = 1,5708; // 90 in radians
	matrix2d = create_2d_matrix(nrows, ncols);
	while(icol < ncols)
	{
		while(irow < nrows)
		{
			matrix2d[irow][icol].x = matrix3d[irow][icol].axis + cos(angle) * matrix3d[irow][icol].altitude - cos(angle) * matrix3d[irow][icol].ordinate;
			matrix2d[irow][icol].y = -(matrix3d[irow][icol].ordinate) * sin(angle) - matrix3d[irow][icol].altitude * sin(angle);	
			irow++;
		}
		irow = 0;
		icol++;
	}
	return(matrix2d);
}

// ideally we would take a pointer to matrix 3d, to avoid copying and extra memory usage
point2d**	scale_2d_matrix(point2d** matrix2d, int nrows, int ncols)
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
			matrix2d[irow][icol].x += 2;
			matrix2d[irow][icol].x /= 4;		
			matrix2d[irow][icol].x *= nrows * DEFAULT_SPACING; // place this as a parameter of matrix2d?
			matrix2d[irow][icol].y += 2;
			matrix2d[irow][icol].y /= 4;		
			matrix2d[irow][icol].y *= ncols * DEFAULT_SPACING; // place this as a parameter of matrix2d?		
			irow++;
		}
		irow = 0;
		icol++;
	}
	return(matrix2d);
}

void	print_2d_matrix(point2d** matrix2d, int nrows, int ncols)
{
	int	irow = 0;
	int	icol = 0;

	while(icol < nrows)
	{
		while(irow < ncols)
		{
			printf("[%i][%i]:\n", irow, icol);
			printf(" x: %f\n", (matrix2d[irow] + icol)->x);	
			printf(" y: %f\n", (matrix2d[irow] + icol)->y);
			irow++;
		}
		irow = 0;
		icol++;
	}
}

void	print_3d_matrix(point3d** matrix3d, int nrows, int ncols)
{
	int	irow = 0;
	int	icol = 0;

	while(icol < nrows)
	{
		while(irow < ncols)
		{
			printf("[%i][%i]:\n", irow, icol);
			printf(" axis: %f\n", (matrix3d[irow] + icol)->axis);	
			printf(" ord : %f\n", (matrix3d[irow] + icol)->ordinate);
			printf(" alt : %f\n", (matrix3d[irow] + icol)->altitude);
			irow++;
		}
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

point2d**	calc_matrices(char *filename, int *nrows, int *ncols)
{
	point3d		**matrix3d;
	point2d		**matrix2d;
	// int			ret;

	// ret = 
	get_3d_matrix_dimensions(filename, nrows, ncols);w
	// if (ret == -1)
	// 	return (NULL); // not quite the right approach!!
	matrix3d = create_3d_matrix(*nrows, *ncols);
	matrix3d = read_coords_from_file(filename, matrix3d);
	// if (ret == NULL)
	// 	return (NULL); // not quite the right approach!!	
	// print_3d_matrix(matrix3d, *nrows, *ncols);

	matrix2d = convert_matrix_from_3d_to_2d(matrix3d, *nrows, *ncols);
	print_2d_matrix(matrix2d, *nrows, *ncols);

	matrix2d = scale_2d_matrix(matrix2d, *nrows, *ncols);
	
	return (matrix2d);
}

void	plot_pixels(point2d** matrix2d, t_data *img, int nrows, int ncols)
{
	int	irow = 0;
	int	icol = 0;

	while(icol < nrows)
	{
		while(irow < ncols)
		{
			if (irow < nrows - 1)
				plotPixel_anySlope(img, matrix2d[irow][icol].x, matrix2d[irow][icol].y, matrix2d[irow+1][icol].x, matrix2d[irow+1][icol].y);
			if (icol < ncols - 1)
				plotPixel_anySlope(img, matrix2d[irow][icol].x, matrix2d[irow][icol].y, matrix2d[irow][icol+1].x, matrix2d[irow][icol+1].y);
			irow++;
		}
		irow = 0;
		icol++;
	}
	
}

void	plot_to_window(point2d** matrix2d, int nrows, int ncols)
{
	t_vars	vars;
	t_data	img;

	unsigned int	window_width = DEFAULT_SPACING * nrows;
	unsigned int 	window_height = DEFAULT_SPACING * ncols;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, window_width, window_height, "Everything!");
	img.img = mlx_new_image(vars.mlx, window_width, window_height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

	plot_pixels(matrix2d, &img, nrows, ncols);

	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_loop(vars.mlx);
}

int		main(int nargs, char **argv)
{
	int			nrows;
	int			ncols;
	point2d		**matrix2d;
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
