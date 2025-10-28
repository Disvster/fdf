/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 19:06:27 by manmaria          #+#    #+#             */
/*   Updated: 2025/10/27 00:04:29 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf.h"

void	init_view(t_data *data)
{
	data->view.alpha = 0;
	data->view.beta = 0;
	data->view.gamma = 0;
	data->view.zoom = 25;
	data->view.scale = 20.0;
	// data->view.angle = 0.523599;
	data->view.angle = M_PI / 6;
}

// x = (int)((point->world_3d[0] - point->world_3d[1])
// 			* cos(data->view.angle))
// y = (int)((point->world_3d[0] + point->world_3d[1])
// 			* sin(data->view.angle) - point->world_3d[2]);
void	project(t_data *data, t_point *points)
{
	points->display[0] = (int)((points->x - points->y)
		* cos(data->view.angle));
	points->display[1] = (int)((points->x + points->y)
		* sin(data->view.angle) - points->z);
	// points->display[0] = (int)(points->x + cos(data->view.angle) * points->z);
	// points->display[1] = (int)(points->x + sin(data->view.angle) * points->z);
}

void	transform(t_data *data)
{
	int	i;
	int	min_x;
	int	min_y;

	i = -1;
	min_x = INT_MAX;
	min_y = INT_MAX;
	init_view(data);
	while (++i < data->map.points_total)
		project(data, &data->points[i]);
	i = -1;
	while (++i < data->map.points_total)
	{
		if (data->points[i].display[0] < min_x)
			min_x = data->points[i].display[0];
		if (data->points[i].display[1] < min_y)
			min_y = data->points[i].display[1];
		data->points[i].display[0] -= min_x;
		data->points[i].display[1] -= min_y;
		data->points[i].display[0] = (int)(data->points[i].display[0]
		* data->view.scale + 200);// NOTE: 100 HERE TO TEST
		data->points[i].display[1] = (int)(data->points[i].display[1]
		* data->view.scale + 200);// NOTE: 100 HERE TO TEST
	}
	print_img(data);
}
