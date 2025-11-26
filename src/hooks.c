/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 20:07:25 by manmaria          #+#    #+#             */
/*   Updated: 2025/11/26 02:15:47 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf.h"

int	key_press(int keycode, t_data *data)
{
	if (keycode == 65307)
		fdf_close_window(data);
	if (keycode == XK_q)
		data->keys.q = true;
	if (keycode == XK_e)
		data->keys.e = true;
	if (keycode == XK_h)
		data->keys.h = true;
	if (keycode == XK_j)
		data->keys.j = true;
	if (keycode == XK_k)
		data->keys.k = true;
	if (keycode == XK_l)
		data->keys.l = true;
	if (keycode == XK_i)
		data->keys.i = true;
	if (keycode == XK_o)
		data->keys.o = true;
	if (keycode == XK_r)
		data->keys.r = true;
	if (keycode == XK_w)
		data->keys.w = true;
	if (keycode == XK_a)
		data->keys.a = true;
	if (keycode == XK_s)
		data->keys.s = true;
	if (keycode == XK_d)
		data->keys.d = true;
	return (0);
}

int	key_release(int keycode, t_data *data)
{
	if (keycode == XK_q)
		data->keys.q = false;
	if (keycode == XK_e)
		data->keys.e = false;
	if (keycode == XK_h)
		data->keys.h = false;
	if (keycode == XK_j)
		data->keys.j = false;
	if (keycode == XK_k)
		data->keys.k = false;
	if (keycode == XK_l)
		data->keys.l = false;
	if (keycode == XK_i)
		data->keys.i = false;
	if (keycode == XK_o)
		data->keys.o = false;
	if (keycode == XK_r)
		data->keys.r = false;
	if (keycode == XK_w)
		data->keys.w = false;
	if (keycode == XK_a)
		data->keys.a = false;
	if (keycode == XK_s)
		data->keys.s = false;
	if (keycode == XK_d)
		data->keys.d = false;
	return (0);
}

void	handle_changes(t_data *data)
{
	if (data->keys.q)
		data->view.z_scale -= 0.03;
	if (data->keys.e)
		data->view.z_scale += 0.03;
	if (data->keys.o)
		data->view.zoom -= 0.005;
	if (data->keys.i)
		data->view.zoom += 0.005;
	if (data->keys.r)
		fdf_init_view(data);
	handle_boundaries(data);
	handle_rotations(data);
}

void	handle_boundaries(t_data *data)
{
	if (data->keys.h)
	{
		data->view.off_x -= 20;
		if (data->view.off_x < -(data->map.width))
			data->view.off_x = IMG_WIDTH;
	}
	if (data->keys.l)
	{
		data->view.off_x += 20;
		if (data->view.off_x > (IMG_WIDTH + data->map.width * 2))
			data->view.off_x = 0;
	}
	if (data->keys.j)
	{
		data->view.off_y += 20;
		if (data->view.off_y > (IMG_HEIGHT + data->map.height * 2))
			data->view.off_y = 0;
	}
	if (data->keys.k)
	{
		data->view.off_y -= 20;
		if (data->view.off_y < -(data->map.height))
			data->view.off_y = IMG_HEIGHT;
	}
}

void	handle_rotations(t_data *data)
{
	float	speed = 0.025;

	if (data->keys.w)
		data->view.angle_x += speed;
	if (data->keys.a)
		data->view.angle_y -= speed;
	if (data->keys.s)
		data->view.angle_x -= speed;
	if (data->keys.d)
		data->view.angle_y += speed;
}
