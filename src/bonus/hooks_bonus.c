/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 17:03:49 by manmaria          #+#    #+#             */
/*   Updated: 2025/12/10 19:49:11 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/fdf_bonus.h"

static void	key_press_helper_bonus(int keycode, t_data *data)
{
	if (keycode == XK_i)
		data->keys.i = true;
	if (keycode == XK_o)
		data->keys.o = true;
	if (keycode == XK_r)
		data->keys.r = true;
}

int	key_press_bonus(int keycode, t_dlist **node)
{
	t_data	*data;

	data = (*node)->data;
	if (keycode == 65307)
		fdf_dlist_clear(node, bonus_wipe_image);
	if (keycode == XK_Right)
		data->keys.right = true;
	if (keycode == XK_Left)
		data->keys.left = true;
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
	key_press_helper_bonus(keycode, data);
	return (0);
}

static void	key_release_helper_bonus(int keycode, t_data *data)
{
	if (keycode == XK_i)
		data->keys.i = false;
	if (keycode == XK_o)
		data->keys.o = false;
	if (keycode == XK_r)
		data->keys.r = false;
}

int	key_release_bonus(int keycode, t_dlist **node)
{
	t_data	*data;

	data = (*node)->data;
	if (keycode == XK_Right)
		data->keys.right = false;
	if (keycode == XK_Left)
		data->keys.left = false;
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
	key_release_helper_bonus(keycode, data);
	return (0);
}
