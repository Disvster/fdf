/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 20:07:25 by manmaria          #+#    #+#             */
/*   Updated: 2025/11/08 22:30:47 by manmaria         ###   ########.fr       */
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
	return (0);
}

void	handle_changes(t_data *data)
{
	if (data->keys.q)
		data->view.z_scale -= 0.5;
	if (data->keys.e)
		data->view.z_scale += 0.5;
	handle_boundaries(data);
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
