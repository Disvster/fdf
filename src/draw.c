/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 23:35:13 by manmaria          #+#    #+#             */
/*   Updated: 2025/11/03 05:29:05 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf.h"

void	draw_wuaa_line(t_point p0, t_point p1, t_data *data)
{
	t_color	color;
	t_line	line;

	ft_bzero(&line, sizeof(t_line));
	line.x0 = p0.display[0];
	line.x1 = p1.display[0];
	line.y0 = p0.display[1];
	line.y1 = p1.display[1];
	line.steep = ft_abs_fl(line.y1 - line.y0) > ft_abs_fl(line.x1 - line.x0);
	prep_line_coords(&line, &p0, &p1);
	color = init_t_color(&p0, &p1);
	line.delta_x = line.x1 - line.x0;
	line.delta_y = line.y1 - line.y0;
	line.gradient = line.delta_y / line.delta_x;
	if (line.delta_x == 0)
		line.gradient = 1;
	line.x = line.x0;
	line.intersect_y = line.y0;
	if (line.delta_x == 0)
		draw_vertical_line(&line, &color, data);
	while (line.x <= line.x1)
	{
		line.y = i_partof_number(line.intersect_y);
		color.main_opa = rf_partof_number(line.intersect_y);
		color.adja_opa = f_partof_number(line.intersect_y);
		color.final = get_pixel_color(color, interpl(line.x, line.x0, line.x1));
		draw_wuaa_pixels(&line, &color, data);
	}
}

void	draw_wuaa_pixels(t_line *line, t_color *color, t_data *data)
{
	if (line->steep)
	{
		if (line->y >= 0 && line->y < IMG_WIDTH
			&& line->x >= 0 && line->x < IMG_HEIGHT)
			my_mlx_pixel_put(data->img, line->y, line->x,
				set_pixel_opacity(color->final, color->main_opa));
		if (line->y + 1 >= 0 && line->y + 1 < IMG_WIDTH
			&& line->x >= 0 && line->x < IMG_HEIGHT)
			my_mlx_pixel_put(data->img, line->y + 1, line->x,
				set_pixel_opacity(color->final, color->adja_opa));
	}
	else
	{
		if (line->x >= 0 && line->x < IMG_WIDTH
			&& line->y >= 0 && line->y < IMG_HEIGHT)
			my_mlx_pixel_put(data->img, line->x, line->y,
				set_pixel_opacity(color->final, color->main_opa));
		if (line->x >= 0 && line->x < IMG_WIDTH
			&& line->y + 1 >= 0 && line->y + 1 < IMG_HEIGHT)
			my_mlx_pixel_put(data->img, line->x, line->y + 1,
				set_pixel_opacity(color->final, color->adja_opa));
	}
	line->intersect_y += line->gradient;
	line->x++;
}

void	draw_vertical_line(t_line *line, t_color *color, t_data *data)
{
	int	y_start;
	int	y_end;
	int	y;

	y_start = line->y0;
	y_end = line->y1;
	if (y_start > y_end)
		ft_swap(&y_start, &y_end);
	y = y_start;
	while (y <= y_end)
	{
		color->final = get_pixel_color(*color, interpl(y, line->y0, line->y1));
		if (line->x0 >= 0 && line->x0 < IMG_WIDTH && y >= 0 && y < IMG_HEIGHT)
			my_mlx_pixel_put(data->img, line->x0, y, color->final);
		y++;
	}
	return ;
}

void	prep_line_coords(t_line *line, t_point *p0, t_point *p1)
{
	if (line->x0 == line->x1)
		return ;
	if (line->steep)
	{
		ft_swap(&line->x0, &line->y0);
		ft_swap(&line->x1, &line->y1);
	}
	if (line->x0 > line->x1)
	{
		ft_swap(&line->x0, &line->x1);
		ft_swap(&line->y0, &line->y1);
		ft_swap(&p0->color, &p1->color);
	}
}

void	render_map(t_data *data)
{
	int	i;
	int	row;
	int	col;
	int	width;

	if (data == NULL || data->map.width == 0 || data->map.height == 0)
		return ;
	row = 0;
	width = data->map.width;
	while (row < data->map.height)
	{
		col = 0;
		while (col < width)
		{
			i = row * width + col;
			if (col + 1 < width)
				draw_wuaa_line(data->points[i], data->points[i + 1], data);
			if (row + 1 < data->map.height)
				draw_wuaa_line(data->points[i], data->points[i + width], data);
			col++;
		}
		row++;
	}
}
