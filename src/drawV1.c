/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawV1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 23:35:13 by manmaria          #+#    #+#             */
/*   Updated: 2025/11/03 00:00:51 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf.h"

void	draw_line(t_point p0, t_point p1, t_data *data)
{
	//{ these are in line struct
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
	//}
	t_color	color;

	x0 = p0.display[0];
	x1 = p1.display[0];
	y0 = p0.display[1];
	y1 = p1.display[1];

	//	HACK: db Print original coordinates
	printf("Original: (%d,%d) -> (%d,%d)\n", x0, y0, x1, y1);

	steep = ft_abs_fl(y1 - y0) > ft_abs_fl(x1 - x0);
	printf("Steep: %d\n", steep);// HACK: db
    if (steep)
    {
        ft_swap(&x0, &y0);
        ft_swap(&x1, &y1);
		printf("After steep swap: (%d,%d) -> (%d,%d)\n", x0, y0, x1, y1);// HACK: db
    }
    if (x0 > x1)
    {
        ft_swap(&x0, &x1);
        ft_swap(&y0, &y1);
        ft_swap(&p0.color, &p1.color);
		printf("After x-order swap: (%d,%d) -> (%d,%d)\n", x0, y0, x1, y1);// HACK: db
	}
	color = init_t_color(&p0, &p1);
	dx = x1 - x0;
	dy = y1 - y0;
	gradient = dy / dx;
	if (dx == 0.0)
		gradient = 1;
	printf("dx=%.2f, dy=%.2f, gradient=%.2f\n", dx, dy, gradient);// HACK: db
	x = x0;
	intersect_y = y0;

	if (dx == 0)//WARNING: check this
	{
		printf("Vertical line detected\n");// HACK: db
		int y_start = (y0 < y1) ? y0 : y1;
		int y_end = (y0 < y1) ? y1 : y0;
		for (int y = y_start; y <= y_end; y++)
		{
			color.inter = (float)(y - y0) / (float)(y1 - y0);
			color.r = color.r0 + color.inter * (color.r1 - color.r0);
			color.g = color.g0 + color.inter * (color.g1 - color.g0);
			color.b = color.b0 + color.inter * (color.b1 - color.b0);
			color.final = (color.r << 16) | (color.g << 8) | color.b;
			if (steep)
				my_mlx_pixel_put(data->img, y, x0, color.final);
			else
				my_mlx_pixel_put(data->img, x0, y, color.final);
		}
		return ;
	}

	int pixel_count = 0;// HACK: db
	while (x <= x1)
	{
		y = i_partof_number(intersect_y);//FIX:ed
		color.main_opa = rf_partof_number(intersect_y);//FIX:ed
		color.adja_opa = f_partof_number(intersect_y);//FIX:ed
		// if (steep)
		// 	color.t = (float)(y - y0) / (float)(y1 - y0);
		// else
		//{FIX:ed
		color.inter = (float)(x - x0) / (float)(x1 - x0);
		color.r = color.r0 + color.inter * (color.r1 - color.r0);
		color.g = color.g0 + color.inter * (color.g1 - color.g0);
		color.b = color.b0 + color.inter * (color.b1 - color.b0);
		color.final = (color.r << 16) | (color.g << 8) | color.b;
		//}FIX:ed

		if (pixel_count < 3)  // HACK: db printf first 3 pixels
			printf("  x=%d, y=%d, intersect_y=%.2f, hi_opa=%.2f, lo_opa=%.2f\n", 
				   x, y, intersect_y, color.main_opa, color.adja_opa);

		if (steep)
		{
			if (y >= 0 && y < IMG_WIDTH && x >= 0 && x < IMG_HEIGHT)
				my_mlx_pixel_put(data->img, y, x,
						set_pixel_opacity(color.final, color.main_opa));
			if (y + 1 >= 0 && y + 1 < IMG_WIDTH && x >= 0 && x < IMG_HEIGHT)
				my_mlx_pixel_put(data->img, y + 1, x,
						set_pixel_opacity(color.final, color.adja_opa));
		}
		else
		{
			if (x >= 0 && x < IMG_WIDTH && y >= 0 && y < IMG_HEIGHT)
				my_mlx_pixel_put(data->img, x, y,
						set_pixel_opacity(color.final, color.main_opa));
			if (x >= 0 && x < IMG_WIDTH && y + 1 >= 0 && y + 1 < IMG_HEIGHT)
				my_mlx_pixel_put(data->img, x, y + 1,
						set_pixel_opacity(color.final, color.adja_opa));
		}
		intersect_y += gradient;
		x++;
		pixel_count++;// HACK: db
	}
	printf("Drew %d pixels\n\n", pixel_count);// HACK: db
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
