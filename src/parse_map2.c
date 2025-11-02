/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 22:40:06 by manmaria          #+#    #+#             */
/*   Updated: 2025/10/23 20:21:17 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf.h"

void	set_point(t_data *data, int i, int x, char *buffer)// FIX: size
{
	static char	**xline;
	int			xi;

	xi = (data->map.width / 2) + x;
	if (!xline)
	{
		xline = ft_split_fdf(buffer, " \n");
		if (!xline)
			return ;// FIX: need to free here
	}
	data->points[i].x = x;
	data->points[i].z = ft_atoi(xline[xi]);
	if (ft_strchr(xline[xi], ',') != NULL)
	{
		ft_printf("color = %s\n", ft_strchr(xline[xi], ','));
		data->points[i].color = ft_atoi_base
			(ft_strchr(xline[xi], ',') + 3, "0123456789ABCDEF");
		if (!data->points[i].color)
			return ; // FIX: need to free here
	}
	if (!xline[xi + 1])
	{
		free_split(xline);
		xline = NULL;
	}
}

	// ft_printf("xline + 1 = %s\n", ft_strchr(xline[xi], ',') + 3);// HACK: d
	// ft_printf("deu free\n");// HACK: db
	// ft_printf("buffer = %s", buffer);// HACK: db
	// ft_printf("xi = %d\n", xi);// HACK: db
	// ft_printf("x = %d\n", x);// HACK: db
	// ft_printf("i = %d\n", i);// HACK: db
	// ft_printf("xline = %s\n", xline[xi]);// HACK: db
	// ft_printf("xline + 1 = %s\n", xline[xi + 1]);// HACK: db
	// ft_printf("xttl = %d\n", data->map->width);// HACK: db
		// int	j = 0;			// HACK: db for split
		// while (xline[j])
		// {
		// 	if (!xline[j + 1])
		// 		ft_printf("\"%s\" \n ", xline[j]);
		// 	else if (xline[j])
		// 		ft_printf("\"%s\" ", xline[j]);
		// 	j++;
		// }

void	*free_buffer(char *buffer)
{
	if (buffer)
		free(buffer);
	buffer = NULL;
	return (NULL);
}

void free_points(t_data *data)
{
	free(data->points);
	data->points = NULL;
}
