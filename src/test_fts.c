/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_fts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 01:51:09 by manmaria          #+#    #+#             */
/*   Updated: 2025/11/11 01:51:32 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf.h"

void	print_map(t_data *data)
{
	int	y;
	int	x;
	int	i;

	y = 0;
	x = 0;
	i = 0;
	while (y < data->map.height)
	{
		while (x < data->map.width)
		{
			ft_printf(" x%d,y%d,z%d",
				data->points[i].x, data->points[i].y, data->points[i].z);
			x++;
			i++;
			if (x == data->map.width)
				ft_printf("\n");
		}
		x = 0;
		y++;
	}
	ft_printf("\ntotal nbr of points -> %d\n", data->map.points_total);
	ft_printf("total nbr of coordinates printed -> %d\n", i);
}

void	print_img(t_data *data)
{
	int	y;
	int	x;
	int	i;

	y = 0;
	x = 0;
	i = 0;
	while (y < data->map.height)
	{
		while (x < data->map.width)
		{
			ft_printf(" x%d,y%d ",
				data->points[i].display[0], data->points[i].display[1]);
			x++;
			i++;
			if (x == data->map.width)
				ft_printf("\n");
		}
		x = 0;
		y++;
	}
	ft_printf("\ntotal nbr of points -> %d\n", data->map.points_total);
	ft_printf("total nbr of coordinates printed -> %d\n", i);
}
