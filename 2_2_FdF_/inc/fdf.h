/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbooth <gbooth@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 14:35:18 by gbooth            #+#    #+#             */
/*   Updated: 2023/05/11 12:11:02 by gbooth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FDF_H
# define FDF_H

# include <stdio.h> // remove
# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include <stdbool.h>
# include <fcntl.h>

# include "libft.h"
# include "get_next_line.h"
# include "ft_printf.h"

# define ISO_ANGLE_STEP 0.001
# define ROT_ANGLE_STEP 0.001
# define SCALE_STEP 0.01
# define Z_SCALE_STEP 0.0005
# define TRANSLATION_STEP 0.1
# define MAX_ROTATION_ANGLE 6.28319
# define MAX_WIN_WIDTH 1920
# define MAX_WIN_HEIGHT 1000
# define MIN_WIN_WIDTH 400
# define MIN_WIN_HEIGHT 400
# define ERR_NO_FILENAME "Error: No filename given"
# define ERR_OPENING_FILE "Error: Map file can not be opened\n"
# define ERR_MATRIX_TOO_SMALL "Error: Map should contain at least \
2 rows and 2 columns\n"
# define ERR_MATRIX_MEMORY_ALLOC "Error: Could not allocate memory for map\n"
# define ERR_NON_DIGIT_IN_FILE "Error: Map file contains items \
other than digits\n"
# define ERR_IRREGULAR_ROWS "Error: Not all map rows have the \
same number of elements\n"

# define POINTS_2D 0
# define LINES_2D 1
# define POINTS_ISO 2
# define LINES_ISO 3
# define POINTS_CONIC 4
# define LINES_CONIC 5

# define TXT_L1 "1 3 : -/+ zoom altitude"
# define TXT_L2 "Q E : -/+ isometric angle"
# define TXT_L3 "A D : -/+ rotation"
# define TXT_L4 " S  : toggle projection mode"
# define TXT_L5 "Z C : -/+ zoom"
# define TXT_R1 " ^ "
# define TXT_R2 "< > : move"
# define TXT_R3 " v"

typedef struct s_point
{
	float	x;
	float	y;
	float	z;
}	t_point;

typedef struct s_point_int
{
	int		x;
	int		y;
}	t_point_int;

typedef struct s_line {
	int	dx;
	int	sx;
	int	dy;
	int	sy;
	int	err;
	int	e2;
}	t_line;

typedef struct s_data {
	void			*mlx;
	void			*win;	
	void			*img;
	char			*addr;
	int				win_width;
	int				win_height;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	unsigned int	nrows;
	unsigned int	ncols;
	unsigned int	prev_nrows;
	t_point			**matrix;
	t_line			*l;
	int				projection_mode;
	float			iso_angle;
	float			rot_angle;
	t_point			translation;
	float			scale;
	float			z_scale;
	float			min_z;
	float			max_z;
	bool			keypress_1;
	bool			keypress_3;
	bool			keypress_q;
	bool			keypress_e;
	bool			keypress_a;
	bool			keypress_d;	
	bool			keypress_z;
	bool			keypress_c;
	bool			keypress_left_arrow;
	bool			keypress_right_arrow;
	bool			keypress_up_arrow;
	bool			keypress_down_arrow;	
}	t_data;

int			get_dims(char *filename, unsigned int *ncols, unsigned int *nrows, \
	unsigned int *prev_nrows);
void		free_split_line(unsigned int *nrows, char **split_line);
int			read_coords_from_file(char *filename, t_point **matrix, \
	t_data *data);
void		scale_to_window(t_data *data);
int			on_key_press(int keycode, t_data *data);
int			on_key_release(int keycode, t_data *data);
int			on_loop(t_data *data);
int			create_trgb(int t, int r, int g, int b);
t_point_int	transform_point(t_data *data, t_point *p);
void		rotate(t_point *p, float angle);
void		z_scale(t_point *p, float z_scale);
void		isometric(t_point *p, float angle);
void		conic(t_point *p, t_data *data);
void		scale(t_point *p, float scale);
void		center(t_point *p, t_data *data);
void		translate(t_point *p, t_point *t);
t_point_int	convert_to_int(t_point *p);
int			check_if_integer(unsigned int irow, char *str);
void		plot_matrix(t_data *data);
void		plot_menu(t_data *data);
int			close_window(t_data *data);
void		keep_angle_in_range(float *rot_angle);
void		my_mlx_pixel_put(t_data *data, t_point_int *p, int color);
void		render(t_data *data);

#endif