#include <stdio.h>
#include <mlx.h>

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int	close(int keycode, t_vars *vars)
{
	printf("%i\n", keycode);
	if (keycode == 65307) // ESC
	{
		mlx_destroy_window(vars->mlx, vars->win);
		mlx_loop_end(vars->mlx); // exit the loop
	}
	return (0);
}

// int	mousedown(int button, int x, int y, t_vars *vars)
// {
// 	mlx_destroy_window(vars->mlx, vars->win);
// 	return (0);
// }

// int	destroy(t_vars *vars)
// {
// 	mlx_destroy_window(vars->mlx, vars->win);
// 	return (0);
// }

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
	mlx_hook(vars.win, 2, 1L<<0, close, &vars);
	// mlx_hook(vars.win, 4, 1L<<2, mousedown, &vars);
	// mlx_hook(vars.win, 17, 1L<<2, destroy, &vars);
	mlx_loop(vars.mlx);
}
