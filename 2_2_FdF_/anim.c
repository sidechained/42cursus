// cc -Wall -Werror -Wextra anim.c -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o anim && ./anim
// example here: https://framagit.org/awoimbee_42/fdf/-/tree/master/src

// what I learned from this:
// 1. we need a render function, called from mlx_loop_hook, that:
// - creates a new image
// - gets data address from it
// - puts pixels to it
// - clears the window
// - puts the image to the window
// - destroys the image
// (q: are all these steps necessary?)
// 2. all data should be accessible/referenced from a single struct, because we can only pass one struct to mlx_loop_hook
// 3. we should to create the window and give it its initial data in main (or an init function)

// consider what the img actually represents and how the struct should be organised
// we are calling it data, but what is it actually?

#include <stdio.h>
#include <stdlib.h>
#include <mlx.h>
#include <math.h>

typedef struct s_point2d
{
	unsigned int x;
	unsigned int y;
} t_point2d;

typedef struct  s_data {
	void		*mlx; // mlx instance (init function)
	void		*win; // window to plot to (init function)
	void		*img; // image instance (render function)
	char		*addr; // image instance (render function)
	int			bits_per_pixel; // 
	int			line_length; //
	int			endian; //
	t_point2d	*point;
	// in my situation the 2d and 3d matrix would be inside here
} t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char    *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int		update(t_data *data)
{
	static int mult = 1;
	if (data->point->x >= 200 || data->point->y >= 200)
		mult = -1;
	if (data->point->x <= 0 || data->point->y <= 0)
		mult = 1;	
	data->point->x += mult;
	data->point->y += mult;
	data->img = mlx_new_image(data->mlx, 200, 200);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
	my_mlx_pixel_put(data, data->point->x, data->point->y, 0x00FF0000);
	mlx_clear_window(data->mlx, data->win);		
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	mlx_destroy_image(data->mlx, data->img);
	return (0);
}

int		main()
{
	t_data		data;

	data.point = malloc(sizeof(t_point2d));
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, 200, 200, "FDF");
	data.point->x = 100;
	data.point->y = 100;
	mlx_loop_hook(data.mlx, update, &data);
	mlx_loop(data.mlx);
	return (0);
}
