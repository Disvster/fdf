/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 19:37:28 by manmaria          #+#    #+#             */
/*   Updated: 2025/12/17 18:46:32 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf.h"

void	rotate_x(double *y, double *z, double angle)
{
	double	prev_y;
	double	prev_z;

	prev_y = *y;
	prev_z = *z;
	*y = prev_y * cos(angle) - prev_z * sin(angle);
	*z = prev_y * sin(angle) + prev_z * cos(angle);
}

void	rotate_y(double *x, double *z, double angle)
{
	double	prev_x;
	double	prev_z;

	prev_x = *x;
	prev_z = *z;
	*x = prev_x * cos(angle) + prev_z * sin(angle);
	*z = -prev_x * sin(angle) + prev_z * cos(angle);
}

void	rotate_z(double *x, double *y, double angle)
{
	double	prev_x;
	double	prev_y;

	prev_x = *x;
	prev_y = *y;
	*x = prev_x * cos(angle) - prev_y * sin(angle);
	*y = prev_x * sin(angle) + prev_y * cos(angle);
}
