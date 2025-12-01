/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 20:07:25 by manmaria          #+#    #+#             */
/*   Updated: 2025/12/01 17:31:29 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf.h"

static void	key_press_helper(int keycode, t_data *data)
{
	if (keycode == XK_w)
		data->keys.w = true;
	if (keycode == XK_a)
		data->keys.a = true;
	if (keycode == XK_s)
		data->keys.s = true;
	if (keycode == XK_d)
		data->keys.d = true;
}

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
	key_press_helper(keycode, data);
	return (0);
}

static void	key_release_helper(int keycode, t_data *data)
{
	if (keycode == XK_w)
		data->keys.w = false;
	if (keycode == XK_a)
		data->keys.a = false;
	if (keycode == XK_s)
		data->keys.s = false;
	if (keycode == XK_d)
		data->keys.d = false;
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
	key_release_helper(keycode, data);
	return (0);
}
