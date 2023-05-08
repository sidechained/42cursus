// clear; cc -Wall -Werror -Wextra close_window_check.c -Lmlx_linux -lmlx_Linux -Imlx_linux -lXext -lX11 -lm -lz && ./a.out

#include <mlx.h>
#include <stdio.h>

#define WIN_WIDTH 600
#define WIN_HEIGHT 600

typedef struct  s_data {
	void			*mlx;
	void			*win;
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;	
	// unsigned int 	nrows;
	// unsigned int 	ncols;
	// t_point			**matrix;
} t_data;

int		close_window(t_data *data)
{
	mlx_loop_end(data->mlx);
	// free_matrix(data->matrix, data->ncols);
	// free_matrix(data->matrix, data->ncols);
	// mlx_destroy_window(data->mlx, data->win);
	return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char    *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(int*)dst = color;
}

int		on_loop(t_data *data)
{
	my_mlx_pixel_put(data, 100, 100, 0x00FFFFFF);
	my_mlx_pixel_put(data, 100, 101, 0x00FFFFFF);
	my_mlx_pixel_put(data, 100, 102, 0x00FFFFFF);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
    return (0);
}

int	main()
{
	t_data	data;

	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WIN_WIDTH, WIN_HEIGHT, "FDF");
	data.img = mlx_new_image(data.mlx, WIN_WIDTH, WIN_HEIGHT);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);
	mlx_hook(data.win, 17, 1L<<0, close_window, &data);
	mlx_loop_hook(data.mlx, on_loop, &data);
	mlx_loop(data.mlx);
	return (0);
}
