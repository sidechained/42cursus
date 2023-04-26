// cc -Wall -Werror -Wextra -Ilibft -Iget_next_line -ggdb3 fdf.c fdf_draw.c fdf_operations2d.c fdf_operations3d.c fdf_read.c get_next_line/get_next_line.c libft/ft_strlen.c libft/ft_substr.c libft/ft_strjoin.c libft/ft_strdup.c libft/ft_split.c libft/ft_atoi.c libft/ft_isdigit.c -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o fdf && ./fdf 3x3.fdf

// TODO: fix error when wrong filename given
// TODO: change angle in realtime using key events

// TODO: large altitudes
// TODO: realtime rotation of angle using A and D keys
// TODO: separation of rotation and perspective

// loop_hook for auto-rotation
// in line function, detect out of bounds and don't print
// centre values
// leave a default amount of space around

#include "fdf.h"

int		main(int nargs, char **argv)
{
	t_data		data;
	char 		*filename;
	t_imgdata	imgdata;

	data.imgdata = &imgdata;
	
	if (nargs < 2)
	{
		printf("%s", "You must supply a filename!\n");
		return (0);
	}
	filename = argv[1];

	// init matrices:
	data.matrix3d = create_3d_matrix(filename);
	// print_3d_matrix(data->matrix3d);
	data.matrix2d = create_2d_matrix(data.matrix3d->nrows, data.matrix3d->ncols);
	// print_2d_matrix(data->matrix2d);

	// init window:
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, data.matrix2d->win_width, data.matrix2d->win_height, "FDF");
	data.matrix2d->iso_angle = 0.7853981634; // 45 degrees

	// loop and render:
	mlx_loop_hook(data.mlx, render, &data);
	mlx_loop(data.mlx);
	return (0);
}
