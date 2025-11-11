/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 17:02:57 by manmaria          #+#    #+#             */
/*   Updated: 2025/11/11 18:44:44 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf.h"

void	set_points_color(t_data *data)
{
	int		z_max;
	int		z_min;
	int		i;
	float	norm;

	if (data->map.has_color == true)
		return ;
	i = -1;
	z_max = data->points[i + 1].z;
	z_min = data->points[i + 1].z;
	while (++i < data->map.points_total)
	{
		if (z_max < data->points[i].z)
			z_max = data->points[i].z;
		if (z_min > data->points[i].z)
			z_min = data->points[i].z;
	}
	i = -1;
	while (++i < data->map.points_total)
	{
		norm = interpl(data->points[i].z, z_min, z_max);
		if (data->points[i].color == 0)
			data->points[i].color = set_height_color(norm);
	}
}

int	set_height_color(float norm)
{
	int	r;
	int	g;
	int	b;
	int	new_color;

	r = (int)(255 * (1.0f - norm));
	g = 0;
	b = (int)(255 * norm);
	if (r > 255)
		r = 255;
	if (r < 0)
		r = 0;
	if (g > 255)
		g = 255;
	if (g < 0)
		g = 0;
	if (b > 255)
		b = 255;
	if (b < 0)
		b = 0;
	new_color = (r << 16) | (g << 8) | b;
	if (new_color == 0)
		new_color = BASE_COLOR;
	return (new_color);
}

int	get_pixel_color(t_color color, float inter)
{
	color.r = color.r0 + inter * (color.r1 - color.r0);
	color.g = color.g0 + inter * (color.g1 - color.g0);
	color.b = color.b0 + inter * (color.b1 - color.b0);
	return ((color.r << 16) | (color.g << 8) | color.b);
}

	// r = (old_color >> 16) & 0xFF;//r is the first 8 bits in old colour
	// g = (old_color >> 8) & 0xFF;//g is the middle 8  bits in old colour
	// b = old_color & 0xFF;//b is the last 8 bit in old_colour
int	set_pixel_opacity(int old_color, float intensity)
{
	int	r;
	int	g;
	int	b;
	int	new_color;

	r = (old_color >> 16) & 0xFF;
	g = (old_color >> 8) & 0xFF;
	b = old_color & 0xFF;
	r = (int)(r * intensity);
	g = (int)(g * intensity);
	b = (int)(b * intensity);
	if (r > 255)
		r = 255;
	if (r < 0)
		r = 0;
	if (g > 255)
		g = 255;
	if (g < 0)
		g = 0;
	if (b > 255)
		b = 255;
	if (b < 0)
		b = 0;
	new_color = (r << 16) | (g << 8) | b;
	return (new_color);
}

t_color	init_t_color(t_point *p0, t_point *p1)
{
	t_color	color;

	ft_bzero(&color, sizeof(t_color));
	color.r0 = (p0->color >> 16) & 0xFF;
	color.g0 = (p0->color >> 8) & 0xFF;
	color.b0 = p0->color & 0xFF;
	color.r1 = (p1->color >> 16) & 0xFF;
	color.g1 = (p1->color >> 8) & 0xFF;
	color.b1 = p1->color & 0xFF;
	return (color);
}
