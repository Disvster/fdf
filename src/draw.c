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

// void	draw_line(int x0, int y0, int x1, int y1, t_data *data)
// { //BRENHAM ALGO
// 	int dx = abs(x1 - x0);
// 	int dy = abs(y1 - y0);
// 	int sx = (x0 < x1) ? 1 : -1;
// 	int sy = (y0 < y1) ? 1 : -1;
// 	int err = dx - dy;
// 	int color;
//
// 	// Use color from starting point, or default if zero
// 	color = data->points[0].color ? data->points[0].color : 0x00FF0000;
//
// 	while (1)
// 	{
// 		my_mlx_pixel_put(data->img, x0, y0, color);
// 		if (x0 == x1 && y0 == y1)
// 			break;
// 		int e2 = 2 * err;
// 		if (e2 > -dy)
// 		{
// 			err -= dy;
// 			x0 += sx;
// 		}
// 		if (e2 < dx)
// 		{
// 			err += dx;
// 			y0 += sy;
// 		}
// 	}
// }

void	draw_line(t_point p0, t_point p1, t_data *data)
{
	double	dx;
	double	dy;
	double	gradient;
	double	intersect_y;
	int		x;
	int		y;
    int		steep;
	int		x0;
	int		x1;
	int		y0;
	int		y1;
	t_color	color;



	x0 = p0.display[0];
	x1 = p1.display[0];
	y0 = p0.display[1];
	y1 = p1.display[1];
	steep = ft_abs_float(y1 - y0) > ft_abs_float(x1 - x0);
    if (steep)
    {
        ft_swap(&x0, &y0);
        ft_swap(&x1, &y1);
    }
    if (x0 > x1)
    {
        ft_swap(&x0, &x1);
        ft_swap(&y0, &y1);
        ft_swap(&p0.color, &p1.color);
	}
	color = init_t_color(p0, p1);
	dx = x1 - x0;
	dy = y1 - y0;
	gradient = dy / dx;
	if (dx == 0.0)
		gradient = 1;
	x = x0;
	intersect_y = y0;
    if (dx == 0)//WARNING: check this
    {
        for (int y = y0; y <= y1; y++)
        {
			color.t = (float)(y - y0) / (float)(y1 - y0);
			color.r = ((p0.color >> 16) & 0xFF) + color.t * (((p1.color >> 16) & 0xFF) - ((p0.color >> 16) & 0xFF));
			color.g = ((p0.color >> 8) & 0xFF) + color.t * (((p1.color >> 8) & 0xFF) - ((p0.color >> 8) & 0xFF));
			color.b = (p0.color & 0xFF) + color.t * ((p1.color & 0xFF) - (p0.color & 0xFF));
			color.final = (color.r << 16) | (color.g << 8) | color.b;
			if (steep)
			my_mlx_pixel_put(data->img, y, x0, color.final);
			else
			my_mlx_pixel_put(data->img, x0, y, color.final);
			}
        return;
    }
	while (x <= x1)
	{
		y = i_partof_number(intersect_y);
		color.hi_opa = rf_partof_number(intersect_y);
		color.lo_opa = f_partof_number(intersect_y);
		if (steep)
			color.t = (float)(y - y0) / (float)(y1 - y0);
		else
			color.t = (float)(x - x0) / (float)(x1 - x0);
		color.r = color.r0 + color.t * (color.r1 - color.r0);
		color.g = color.g0 + color.t * (color.g1 - color.g0);
		color.b = color.b0 + color.t * (color.b1 - color.b0);
		color.final = (color.r << 16) | (color.g << 8) | color.b;
		if (steep && (x >= 0 && x < IMG_WIDTH && y >= 0 && y < IMG_HEIGHT))
		{
			my_mlx_pixel_put(data->img, y, x,
					get_pixel_color(color.final, color.hi_opa));
			my_mlx_pixel_put(data->img, y - 1, x,
					get_pixel_color(color.final, color.lo_opa));
		}
		else if (x >= 0 && x < IMG_WIDTH && y >= 0 && y < IMG_HEIGHT)
		{
			my_mlx_pixel_put(data->img, x, y,
					get_pixel_color(color.final, color.hi_opa));
			my_mlx_pixel_put(data->img, x, y - 1,
					get_pixel_color(color.final, color.lo_opa));
		}
		intersect_y += gradient;
		x++;
	}
}

void	draw_in_image(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->map.points_total)
	{
		if ((i + 1) % data->map.width != 0 && (i + 1) < data->map.points_total)
			draw_line(data->points[i], data->points[1 + 1], data);
		if (i + data->map.width < data->map.points_total)
			draw_line(data->points[i], data->points[i + data->map.width], data);
	}
}
		// if ((i + 1) % data->map.width != 0 && (i + 1) < data->map.points_total)
		// {
			// x0 = data->points[i].display[0];
			// y0 = data->points[i].display[1];
			// x1 = data->points[i + 1].display[0];
			// y1 = data->points[i + 1].display[1];
		// if (i + data->map.width < data->map.points_total)
		// {
			// x0 = data->points[i].display[0];
			// y0 = data->points[i].display[1];
			// x1 = data->points[i + data->map.width].display[0];
			// y1 = data->points[i + data->map.width].display[1];
