// cc -Wall -Werror -Wextra key-repeat.c -Lmlx_linux -lmlx_Linux -Imlx_linux -lXext -lX11 -lm -lz

#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define ESCAPE_KEY 65307

typedef struct s_data {
    void *mlx;
    void *win;
    bool is_key_pressed;
} t_data;

int on_key_press(int keycode, t_data *data)
{
    if (keycode == ESCAPE_KEY)
    {
        mlx_destroy_window(data->mlx, data->win);
        exit(0);
    }
    // Handle other keycodes here
    data->is_key_pressed = true;
    return (0);
}

int on_key_release(int keycode, t_data *data)
{
    // Handle other keycodes here
    data->is_key_pressed = false;
    (void)keycode;
    return (0);
}

int on_loop(t_data *data)
{
    if (data->is_key_pressed)
    {
        // Handle key repeat here
    }
    return (0);
}

int main(void)
{
    t_data data;

    data.mlx = mlx_init();
    if (!data.mlx)
        return (EXIT_FAILURE);

    data.win = mlx_new_window(data.mlx, 640, 480, "Key repeat example");
    if (!data.win)
        return (EXIT_FAILURE);

    mlx_hook(data.win, 2, 0, (void *)on_key_press, &data);
    mlx_hook(data.win, 3, 0, (void *)on_key_release, &data);
    mlx_loop_hook(data.mlx, (void *)on_loop, &data);
    mlx_loop(data.mlx);
    return (EXIT_SUCCESS);
}