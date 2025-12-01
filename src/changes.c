/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   changes.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 16:59:22 by manmaria          #+#    #+#             */
/*   Updated: 2025/12/01 17:02:17 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf.h"

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
	double	speed;

	speed = 0.025;
	if (data->keys.w)
		data->view.angle_x += speed;
	if (data->keys.a)
		data->view.angle_y -= speed;
	if (data->keys.s)
		data->view.angle_x -= speed;
	if (data->keys.d)
		data->view.angle_y += speed;
}
