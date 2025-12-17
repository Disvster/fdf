/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xiaolin_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 16:50:09 by manmaria          #+#    #+#             */
/*   Updated: 2025/12/17 18:46:32 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf.h"

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

double	ft_abs_fl(double nb)
{
	if (nb >= 0)
		return (nb);
	else
		return (nb * -1);
}

int	i_partof_number(double nb)
{
	return ((int)nb);
}

double	f_partof_number(double nb)
{
	return (ft_abs_fl(nb - i_partof_number(nb)));
}

double	rf_partof_number(double nb)
{
	return (1 - f_partof_number(nb));
}
