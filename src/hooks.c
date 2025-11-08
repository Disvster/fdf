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
	if (keycode == K_KEY)
		data->keys.k = true;
	if (keycode == J_KEY)
		data->keys.j = true;
	return (0);
}

int	key_release(int keycode, t_data *data)
{
	if (keycode == K_KEY)
		data->keys.k = false;
	if (keycode == J_KEY)
		data->keys.j = false;
	return (0);
}
