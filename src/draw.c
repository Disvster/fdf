/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 23:35:13 by manmaria          #+#    #+#             */
/*   Updated: 2025/11/03 00:15:24 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf.h"

void	draw_line_helper(t_line *line, t_color *color, t_data *data);
void	fdf_swap(t_line *line, t_point *p0, t_point *p1);
void	draw_line_vertical(t_line *line, t_color *color, t_data *data);

//NOTE: change name to smth like line handler ?
void	draw_line(t_point *p0, t_point *p1, t_data *data)
{
	t_color	color;
	t_line	line;

	ft_bzero(&line, sizeof(t_line));
	line.x0 = p0->display[0];
	line.x1 = p1->display[0];
	line.y0 = p0->display[1];
	line.y1 = p1->display[1];
	line.steep = ft_abs_fl(line.y1 - line.y0) > ft_abs_fl(line.x1 - line.x0);
	fdf_swap(&line, p0, p1);
	color = init_t_color(p0, p1);
	line.delta_x = line.x1 - line.x0;
	line.delta_y = line.y1 - line.y0;
	line.gradient = line.delta_y / line.delta_x;
	if (line.delta_x == 0.0)
		line.gradient = 1;
	line.x = line.x0;
	line.intersect_y = line.y0;
	if (line.delta_x == 0.0)    // NOTE:can optimize with fract/rev-fract?
		draw_line_vertical(&line, &color, data);
	while (line.x <= line.x1)
	{
		line.y = i_partof_number(line.intersect_y);
		color.main_opa = rf_partof_number(line.intersect_y);
		color.adja_opa = f_partof_number(line.intersect_y);
		color.inter = interpolate(line.x, line.x0, line.x1);
		color.final = get_pixel_color(&color);
		draw_line_helper(&line, &color, data);
		line.intersect_y += line.gradient;	
		line.x++;
	}
}

void	draw_line_helper(t_line *line, t_color *color, t_data *data)
{
	if (line->steep)
	{	// WARNING: why x height
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
}

void	draw_line_vertical(t_line *line, t_color *color, t_data *data)
{
	int	y_start;
	int	y_end;
	int	y;

	line->gradient = 1;
	y_start = line->y0;
	y_end = line->y1;
	if (y_start > y_end)//{y_start = line->y1; y_end = line->y0;}
		ft_swap(&y_start, &y_end);
	y = y_start;
	while (y <= y_end)
	{
		color->inter = interpolate(y, line->y0, line->y1);
		color->final = get_pixel_color(color);
		if (line->x0 >= 0 && line->x0 < IMG_WIDTH && y >= 0 && y <= IMG_HEIGHT)
			my_mlx_pixel_put(data->img, line->x0, y, color->final);
		y++;
	}
	return ;
}

//NOTE: change name to line_swaps ?
void	fdf_swap(t_line *line, t_point *p0, t_point *p1)
{
	if (line->x0 == line->x1)
		return ;
	// WARNING: below: Why swap?
    if (line->steep)// NOTE: if line is not straight we draw top to bot
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

void	draw_in_image(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->map.points_total)
	{
		if ((i + 1) % data->map.width != 0 && (i + 1) < data->map.points_total)
			draw_line(&data->points[i], &data->points[i + 1], data);
		if ((i + data->map.width) < data->map.points_total) // NOTE: changed from < to <= bc this prog seems to be skipping last y
			draw_line(&data->points[i], &data->points[i + data->map.width], data);
	}
}
