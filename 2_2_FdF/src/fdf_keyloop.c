/* ************************************************************************** */

/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_keyloop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbooth <gbooth@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 14:35:18 by gbooth            #+#    #+#             */
/*   Updated: 2023/05/09 20:59:47 by gbooth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

void	on_key_press1(int keycode, t_data *data)
{
	if (keycode == 65307)
		close_window(data);
	if (keycode == 115)
		data->projection_mode = (data->projection_mode + 1) % 6;
	if (keycode == 49)
		data->keypress_1 = true;
	if (keycode == 51)
		data->keypress_3 = true;
}

int	on_key_press(int keycode, t_data *data)
{
	on_key_press1(keycode, data);
	if (keycode == 113)
		data->keypress_q = true;
	if (keycode == 101)
		data->keypress_e = true;
	if (keycode == 97)
		data->keypress_a = true;
	if (keycode == 100)
		data->keypress_d = true;
	if (keycode == 121)
		data->keypress_z = true;
	if (keycode == 99)
		data->keypress_c = true;
	if (keycode == 65361)
		data->keypress_left_arrow = true;
	if (keycode == 65363)
		data->keypress_right_arrow = true;
	if (keycode == 65362)
		data->keypress_up_arrow = true;
	if (keycode == 65364)
		data->keypress_down_arrow = true;
	return (0);
}

int	on_key_release(int keycode, t_data *data)
{
	if (keycode == 49)
		data->keypress_1 = false;
	if (keycode == 51)
		data->keypress_3 = false;
	if (keycode == 113)
		data->keypress_q = false;
	if (keycode == 101)
		data->keypress_e = false;
	if (keycode == 97)
		data->keypress_a = false;
	if (keycode == 100)
		data->keypress_d = false;
	if (keycode == 121)
		data->keypress_z = false;
	if (keycode == 99)
		data->keypress_c = false;
	if (keycode == 65361)
		data->keypress_left_arrow = false;
	if (keycode == 65363)
		data->keypress_right_arrow = false;
	if (keycode == 65362)
		data->keypress_up_arrow = false;
	if (keycode == 65364)
		data->keypress_down_arrow = false;
	return (0);
}

void	on_loop_1(t_data *data)
{
	if (data->keypress_1)
		data->z_scale = data->z_scale - Z_SCALE_STEP;
	if (data->keypress_3)
		data->z_scale = data->z_scale + Z_SCALE_STEP;
	if (data->keypress_q)
	{
		data->iso_angle = data->iso_angle - ISO_ANGLE_STEP;
		keep_angle_in_range(&data->iso_angle);
	}
	if (data->keypress_e)
	{
		data->iso_angle = data->iso_angle + ISO_ANGLE_STEP;
		keep_angle_in_range(&data->iso_angle);
	}
	if (data->keypress_a)
	{
		data->rot_angle = data->rot_angle - ROT_ANGLE_STEP;
		keep_angle_in_range(&data->rot_angle);
	}
	if (data->keypress_d)
	{
		data->rot_angle = data->rot_angle + ROT_ANGLE_STEP;
		keep_angle_in_range(&data->rot_angle);
	}
}

int	on_loop(t_data *data)
{
	on_loop_1(data);
	if (data->keypress_z)
		data->scale = data->scale - SCALE_STEP;
	if (data->keypress_c)
		data->scale = data->scale + SCALE_STEP;
	if (data->keypress_left_arrow)
		data->translation.x = data->translation.x - TRANSLATION_STEP;
	if (data->keypress_right_arrow)
		data->translation.x = data->translation.x + TRANSLATION_STEP;
	if (data->keypress_up_arrow)
		data->translation.y = data->translation.y - TRANSLATION_STEP;
	if (data->keypress_down_arrow)
		data->translation.y = data->translation.y + TRANSLATION_STEP;
	render(data);
	return (0);
}
