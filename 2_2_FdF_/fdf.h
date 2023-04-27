#include <stdio.h>
#include <stdlib.h>
#include <mlx.h>
#include <math.h>
#include <fcntl.h> // open
#include "get_next_line.h"
#include "libft.h"

#define DEFAULT_SPACING 80
#define MAX_WIN_WIDTH 600
#define MAX_WIN_HEIGHT 600

#define MAX_ROTATION_ANGLE 6.28319
#define ISO_STEP 0.5
#define ROT_STEP 0.25
#define ZOOM_STEP 0.5
#define TRANS_STEP 1

typedef struct s_t_point3d
{
	unsigned int	axis;
	unsigned int	ordinate;
	int 			altitude;
} t_point3d;

typedef struct s_matrix3d
{
	t_point3d		**points;
	unsigned int	nrows;
	unsigned int	ncols;
} t_matrix3d;

typedef struct s_point2d
{
	unsigned int	x;
	unsigned int	y;
} t_point2d;

typedef struct  s_line {
	int dx;
	int sx;
	int dy;
	int sy;
	int err;
	int e2;
} t_line;

typedef struct s_matrix2d
{
	t_point2d		**points;
	t_line			*line;
	unsigned int	nrows;
	unsigned int	ncols;	
	unsigned int	win_width;
	unsigned int	win_height;
	float			iso_angle;
	float			rot_angle;
	float			zoom_level;
	t_point2d		*trans;
} t_matrix2d;

typedef struct  s_imgdata {
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
} t_imgdata;

typedef struct  s_data {
	void			*mlx;
	void			*win;	
	t_imgdata		*imgdata;
	t_matrix3d		*matrix3d;
	t_matrix2d		*matrix2d;	
} t_data;

// fdf_draw.c
void		render(t_data *data);
int			key_hook(int keycode, t_data *data);

// fdf_operations2d.c
void		print_2d_matrix(t_matrix2d *matrix2d);
t_matrix2d	*create_2d_matrix(int nrows, int ncols);
void		calc_zoom_level_and_window_size(t_matrix2d *matrix2d);

// fdf_operations3d.c
t_matrix3d 	*create_3d_matrix(char *filename);
void	    print_3d_matrix(t_matrix3d *matrix3d);
void		convert_matrix(t_matrix3d *matrix3d, t_matrix2d *matrix2d);

// fdf_read.c
int			get_dimensions(char *filename, t_matrix3d *matrix3d);
int			read_coords_from_file(int fd, t_matrix3d *matrix3d);