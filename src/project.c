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
	data->view.angle = 0.523599;
	data->view.off_x = IMG_WIDTH / 2;
	data->view.off_y = IMG_WIDTH / 2;
}
	// data->view.angle = M_PI / 6;
	// data->view.angle = 0.523599;

void	project(t_data *data, t_point *points, float *min_x, float *min_y)
{
	points->t_x = ((points->x - points->y) * cos(data->view.angle));
	points->t_y = ((points->x + points->y) * sin(data->view.angle) - points->z);
	if (points->t_x < *min_x)
		*min_x = points->t_x;
	if (points->t_y < *min_y)
		*min_y = points->t_y;
}

void	transform(t_data *data)
{
	int		i;
	float	min_x;
	float	min_y;

	i = -1;
	min_x = FLT_MAX;
	min_y = FLT_MAX;
	init_view(data);
	i = -1;
	while (++i < data->map.points_total)
		project(data, &data->points[i], &min_x, &min_y);
	i = -1;
	while (++i < data->map.points_total)
	{
		data->points[i].t_x -= min_x;
		data->points[i].t_y -= min_y;
		data->points[i].display[0] = (int)(data->points[i].t_x
				* data->view.scale + data->view.off_x);
		data->points[i].display[1] = (int)(data->points[i].t_y
				* data->view.scale + data->view.off_y);
	}
	print_img(data);// HACK: db
}

// if (data->points[i].display[0] < min_x)
// 	min_x = data->points[i].display[0];
// if (data->points[i].display[1] < min_y)
// 	min_y = data->points[i].display[1];
// data->points[i].display[0] -= min_x;
// data->points[i].display[1] -= min_y;
// data->points[i].display[0] = (int)(px * data->view.scale + data->view.off_x);
// data->points[i].display[1] = (int)(py * data->view.scale + data->view.off_y);
//
// x = (int)((point->world_3d[0] - point->world_3d[1])
// 			* cos(data->view.angle))
// y = (int)((point->world_3d[0] + point->world_3d[1])
// 			* sin(data->view.angle) - point->world_3d[2]);
// void	old_project(t_data *data, t_point *points)
// {
// 	double	px;
// 	double	py;
//
// points->display[0] = (int)(points->x + cos(data->view.angle) * points->z);
// points->display[1] = (int)(points->x + sin(data->view.angle) * points->z);
// 	px = ((points->x - points->y) * cos(data->view.angle));
// 	py = ((points->x + points->y) * sin(data->view.angle) - points->z);
// 	points->display[0] = (int)(px * data->view.scale + data->view.off_x);
// 	points->display[1] = (int)(py * data->view.scale + data->view.off_y);
// }
