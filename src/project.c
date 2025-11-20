/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 19:06:27 by manmaria          #+#    #+#             */
/*   Updated: 2025/11/11 18:25:51 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf.h"

void	fdf_init_view(t_data *data)
{
	int	max_dimension;

	max_dimension = data->map.width;
	if (data->map.height > max_dimension)
		max_dimension = data->map.height;
	data->view.alpha = 0;
	data->view.beta = 0;
	data->view.gamma = 0;
	data->view.scale = 20.0;
	data->view.angle = 0.523599;
	data->view.off_x = IMG_WIDTH / 2;
	data->view.off_y = IMG_HEIGHT / 2;
	data->view.z_scale = 5.5;
	if (max_dimension < 100)
		data->view.zoom = 1;
	else if (max_dimension <= 200)
		data->view.zoom = 0.35;
	else
		data->view.zoom = 0.125;
}

void	project(t_data *data, t_point *points)
{
	double	x;
	double	y;
	double	z;

	x = points->x * data->view.zoom;
	y = points->y * data->view.zoom;
	z = points->z * data->view.zoom * data->view.z_scale;
	points->t_x = ((x - y) * cos(data->view.angle)
			* data->view.scale + (double)data->view.off_x);
	points->t_y = ((x + y) * sin(data->view.angle)
			* data->view.scale - z + (double)data->view.off_y);
}

void	transform(t_data *data)
{
	int		i;

	i = -1;
	while (++i < data->map.points_total)
		project(data, &data->points[i]);
	i = -1;
	while (++i < data->map.points_total)
	{
		data->points[i].display[0] = (int)(data->points[i].t_x);
		data->points[i].display[1] = (int)(data->points[i].t_y);
	}
}
