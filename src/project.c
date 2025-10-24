/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 19:06:27 by manmaria          #+#    #+#             */
/*   Updated: 2025/10/23 20:36:04 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf.h"

void	init_view(t_data *data)
{
	data->view.alpha = 0;
	data->view.beta = 0;
	data->view.gamma = 0;
	data->view.zoom = 25;
	data->view.scale = 1;
	data->view.angle = 0.523599;
}

void	project(t_data *data, t_point *points)
{
	points->display[0] = abs((int)((points->x - points->y) * cos(data->view.angle)));
	points->display[1] = abs((int)((points->x + points->y) * sin(data->view.angle) - points->z));
	ft_printf("disp x = %d\n", points->display[0]);
	ft_printf("disp y = %d\n", points->display[1]);
}
// x = (int)((point->world_3d[0] - point->world_3d[1])
// 			* cos(data->view.angle))
// y = (int)((point->world_3d[0] + point->world_3d[1])
// 			* sin(data->view.angle) - point->world_3d[2]);

void	transform(t_data *data)
{
	int	i;

	i = -1;
	init_view(data);
	while (++i < data->map.points_total)
		project(data, &data->points[i]);
}
