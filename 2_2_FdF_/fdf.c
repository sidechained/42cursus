// cc -Wall -Werror -Wextra -Ilibft -Iget_next_line -ggdb3 fdf.c fdf_draw.c fdf_operations2d.c fdf_operations3d.c fdf_read.c get_next_line/get_next_line.c libft/ft_strlen.c libft/ft_substr.c libft/ft_strjoin.c libft/ft_strdup.c libft/ft_split.c libft/ft_atoi.c libft/ft_isdigit.c -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o fdf && ./fdf 3x3.fdf

// TODO: add another form of projection
// TODO: handle altitudes correctly
// TODO: map altitude to color
// TODO: malloc and free
// TODO: fix crashes when combining zoom level, rot_angle and iso_angle (isolate the issue - seems to happen when rotations take the image offscreen)
// TODO: handle all map types (test with 42 map first)
// TODO: size window correctly based on size of model (no border, but window should be able to fit any iso angle)
// TODO: zoom should zoom to centre?
// TODO: makefile
// Q: is there are max map size that should be handled?

#include "fdf.h"

int	close_window(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	return (0);
}

int		main(int nargs, char **argv)
{
	t_data		data;
	char 		*filename;
	t_imgdata	imgdata;
	t_line		line;
	t_point2d	trans;

	data.imgdata = &imgdata;

	if (nargs < 2)
	{
		printf("%s", "You must supply a filename!\n");
		return (0);
	}
	filename = argv[1];

	// init matrices:
	data.matrix3d = create_3d_matrix(filename);
	if (data.matrix3d == NULL)
		return (-1);
	// print_3d_matrix(data->matrix3d);
	data.matrix2d = create_2d_matrix(data.matrix3d->nrows, data.matrix3d->ncols);
	// print_2d_matrix(data->matrix2d);

	data.matrix2d->line = &line;

	// init window:
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, data.matrix2d->win_width, data.matrix2d->win_height, "FDF");
	data.matrix2d->iso_angle = 0.7853981634; // 45 degrees
	data.matrix2d->rot_angle = 0.7853981634;
	data.matrix2d->trans = &trans;
	data.matrix2d->trans->x = 0.0;
	data.matrix2d->trans->y = 0.0;

	// initial render
	render(&data);
	// loop and render:
	mlx_key_hook(data.win, key_hook, &data);
	mlx_hook(data.win, 17, 0, close_window, &data);
	// mlx_loop_hook(data.mlx, increase_iso_angle, &data);
	mlx_loop(data.mlx);
	return (0);
}
