#include <stdio.h>
#include <stdlib.h>
#include <mlx.h>
#include <math.h>
#include <fcntl.h> // open
#include "get_next_line/get_next_line.h"
#include "libft/libft.h"

#define DEFAULT_SPACING 50
#define MAX_WIN_WIDTH 600
#define MAX_WIN_HEIGHT 600

typedef struct point_3d
{
	int axis;
	int ordinate;
	int altitude;
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
	float			angle;
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

void		plot_to_window(matrix_2d *matrix2d, int nrows, int ncols);
matrix_3d	*read_coords_from_file(char *filename, matrix_3d *matrix3d);
void		print_3d_matrix(matrix_3d *matrix3d, int nrows, int ncols);
void		print_2d_matrix(matrix_2d *matrix2d, int nrows, int ncols);
matrix_3d	*init_3d_matrix(int nrows, int ncols);
matrix_2d	*init_2d_matrix(int nrows, int ncols);
int			get_3d_matrix_dimensions(char *filename, int *nrows, int *ncols);
matrix_2d	*matrix_3d_to_2d_iso(matrix_3d	*matrix3d, matrix_2d *matrix2d, int nrows, int ncols, float angles);
matrix_2d	*matrix_3d_to_2d_flat(matrix_3d	*matrix3d, matrix_2d *matrix2d, int nrows, int ncols);
matrix_2d	*scale_2d_matrix(matrix_2d *matrix2d, int nrows, int ncols);