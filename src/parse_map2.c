/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 22:40:06 by manmaria          #+#    #+#             */
/*   Updated: 2025/10/18 04:15:24 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf.h"

void	set_point(t_data *data, int i, int x, char *buffer)
{
	static char	**xline;
	int			xi;

	xi = (data->map->width / 2) + x;
	if (!xline)
	{
		xline = ft_split(buffer, ' ');
		if (!xline)
			exit (1);// HACK: need to free here
	}
	ft_printf("xi=%d\n",xi);
	data->points[i].x = x;
	data->points[i].z = ft_atoi(xline[xi]);
	if (ft_strchr(xline[xi], ','))
	{
		xline[xi] = ft_strchr(xline[xi], ',');
		data->points[i].color = ft_strdup(xline[xi]);
		if (!data->points[i].color)
			exit (1); // HACK: need to free here
	}
	ft_printf("x bef split=%d\n",x == (data->map->width / 2));
	if (i == data->map->points_total)
		free_split(xline);
	else
		xline = NULL;
}

void	*free_buffer(char *buffer)
{
	if (buffer)
		free(buffer);
	buffer = NULL;
	return (NULL);
}
	// int	j = 0;
	// while (xline[j])
	// {
	// 	if (!xline[j + 1])
	// 		ft_printf("\"%s\" \n ", xline[j]);
	// 	else if (xline[j])
	// 		ft_printf("\"%s\" ", xline[j]);
	// 	j++;
	// }
