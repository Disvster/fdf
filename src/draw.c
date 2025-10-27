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


	// color = 0;
	// i = -1;
	// while (++i < data->map.points_total)
	// {
	// 	if (data->points[i].color != 0)
	// 		color = data->points[i].color;
	// 	else
	// 		color = 0x00FF0000;
	// 	my_mlx_pixel_put(img,
	// 			   data->points[i].display[0],
	// 			   data->points[i].display[1],
	// 			   color);
	// }
void	draw_line(int x0, int y0, int x1, int y1, t_data *data)
{
	int dx = abs(x1 - x0);
	int dy = abs(y1 - y0);
	int sx = (x0 < x1) ? 1 : -1;
	int sy = (y0 < y1) ? 1 : -1;
	int err = dx - dy;
	int color;

	// Use color from starting point, or default if zero
	color = data->points[0].color ? data->points[0].color : 0x00FF0000;

	while (1)
	{
		my_mlx_pixel_put(data->img, x0, y0, color);
		if (x0 == x1 && y0 == y1)
			break;
		int e2 = 2 * err;
		if (e2 > -dy)
		{
			err -= dy;
			x0 += sx;
		}
		if (e2 < dx)
		{
			err += dx;
			y0 += sy;
		}
	}
}

// void	draw_line(int x0, int y0, int x1, int y1, t_data *data)
// {
// 	int	x;
// 	int	y;
// 	int	dx;
// 	int	dy;
// 	int	m;
// 	int	i;
// 	int	color;
//
// 	dx = x1 - x0;
// 	dy = y1 - y0;
// 	m = 1;
// 	if (dx != 0)
// 		m = dy / dx;
// 	i = -1;
// 	while (++i < dx)// or dx + 1
// 	{
// 		x = x0 + i;
// 		y = y0 + i * m;
// 		if (data->points[i].color != 0)
// 			color = data->points[i].color;
// 		else
// 			color = 0x00FF0000;
// 		my_mlx_pixel_put(data->img, (int)x, (int)y, color);
// 	}
// }

void	draw_in_image(t_data *data)
{
	int	i;
	int	x0;
	int	x1;
	int	y0;
	int	y1;

	i = -1;
	while (++i < data->map.points_total)
	{
		if ((i + 1) % data->map.width != 0 && (i + 1) < data->map.points_total)
		{
			x0 = data->points[i].display[0];
			y0 = data->points[i].display[1];
			x1 = data->points[i + 1].display[0];
			y1 = data->points[i + 1].display[1];
			draw_line(x0, y0, x1, y1, data);
		}
		if (i + data->map.width < data->map.points_total)
		{
			x0 = data->points[i].display[0];
			y0 = data->points[i].display[1];
			x1 = data->points[i + data->map.width].display[0];
			y1 = data->points[i + data->map.width].display[1];
			draw_line(x0, y0, x1, y1, data);
		}
	}
}
