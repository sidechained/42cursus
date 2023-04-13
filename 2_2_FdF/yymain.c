#include <stdlib.h>
#include <mlx.h>

int main(void)
{
	void	*mlx_ptr;

	mlx_ptr = mlx_init();
	mlx_new_window(mlx_ptr, 100, 100, "test");
	mlx_loop(mlx_ptr);
	// mlx_destroy_display(mlx_ptr);
	// free(mlx_ptr);
}