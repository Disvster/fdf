/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xiaolin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 16:50:09 by manmaria          #+#    #+#             */
/*   Updated: 2025/10/27 00:09:23 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf.h"

int	get_pixel_color(int old_color, float intensity)
{
	int	r;
	int	g;
	int	b;
	int	new_color;
	//0xRRGGBB
	r = (old_color >> 16) & 0xFF;//r is the first 8 bits in old colour
	g = (old_color >> 8) & 0xFF;//g is the middle 8  bits in old colour
	b = old_color & 0xFF;//b is the last 8 bit in olc_colour
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

t_color	init_t_color(t_point p0, t_point p1)
{
	t_color	color;
	
	ft_bzero(&color, sizeof(t_color));
	printf("p0.color = %d\np1.color = %d\n", p0.color, p0.color);
	if (p0.color == 0)
		p0.color = 16711680;
	if (p1.color == 0)
		p1.color = 16711680;
	color.r0 = (p0.color >> 16) & 0xFF;
	color.g0 = (p0.color >> 8) & 0xFF;
	color.b0 = p0.color & 0xFF;

	color.r1 = (p1.color >> 16) & 0xFF;
	color.g1 = (p1.color >> 8) & 0xFF;
	color.b1 = p1.color & 0xFF;
	return (color);
}

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

float ft_abs_float(float nb)
{
	if (nb >= 0)
		return (nb);
	else
		return (nb * -1);
}

int	i_partof_number(float nb)
{
	return ((int)nb);
}

float	f_partof_number(float nb)
{
	return (ft_abs_float(nb - i_partof_number(nb)));
}

float	rf_partof_number(float nb)
{
	return (1 - f_partof_number(nb));
}

// #include <stdio.h>
// int	main(void)
// {
// 	float i = -0.80;
//
// 	printf("i = %.2f\ni_partof_number(i) = %d\n", i, i_partof_number(i));
// 	printf("f_partof_number(i) = %.2f\n", f_partof_number(i));
// 	printf("rf_partof_number(i) = %.2f\n", rf_partof_number(i));
// 	return (0);
// }
