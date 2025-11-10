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
	if (keycode == ESC_KEY)
	{
		free_function(NULL, data);
		exit(0);
	}
	if (keycode == Q_KEY)
		data->keys.q = true;
	if (keycode == E_KEY)
		data->keys.e = true;
	if (keycode == H_KEY)
		data->keys.h = true;
	if (keycode == J_KEY)
		data->keys.j = true;
	if (keycode == K_KEY)
		data->keys.k = true;
	if (keycode == L_KEY)
		data->keys.l = true;
	return (0);
}

int	key_release(int keycode, t_data *data)
{
	if (keycode == Q_KEY)
		data->keys.q = false;
	if (keycode == E_KEY)
		data->keys.e = false;
	if (keycode == H_KEY)
		data->keys.h = false;
	if (keycode == J_KEY)
		data->keys.j = false;
	if (keycode == K_KEY)
		data->keys.k = false;
	if (keycode == L_KEY)
		data->keys.l = false;
	return (0);
}

void	handle_changes(t_data *data)
{
	if (data->keys.q)
		data->view.z_scale -= 0.5;
	if (data->keys.e)
		data->view.z_scale += 0.5;
	if (data->keys.h)
		data->view.off_x -= 2;
	if (data->keys.l)
		data->view.off_x += 2;
	if (data->keys.j)
		data->view.off_y += 2;
	if (data->keys.k)
		data->view.off_x -= 2;
}
