/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 23:35:13 by manmaria          #+#    #+#             */
/*   Updated: 2025/10/27 00:01:23 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf.h"

void	draw_line(t_point p0, t_point p1, t_data *data)
{

}

void	draw_in_image(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->map.points_total)
	{
		if ((i + 1) % data->map.width != 0 && (i + 1) < data->map.points_total)
			draw_line(data->points[i], data->points[i + 1], data);
		if (i + data->map.width < data->map.points_total)
			draw_line(data->points[i], data->points[i + data->map.width], data);
	}
}
