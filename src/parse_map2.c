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

void	set_point(t_data *data, int i, int x, char *buffer)// FIX: size
{
	static char	**xline;
	int			xi;

	xi = (data->map->width / 2) + x;
	if (!xline)
	{
		xline = ft_split(buffer, ' ');
		if (!xline)
			return ;// FIX: need to free here
	}
	data->points[i].x = x;
	data->points[i].z = ft_atoi(xline[xi]);
	if (ft_strchr(xline[xi], ',') != NULL)
	{
		xline[xi] = ft_strchr(xline[xi], ',');
		data->points[i].color = ft_strdup(xline[xi]);
		if (!data->points[i].color)
			return ; // FIX: need to free here
	}
	else
		data->points[i].color = NULL;
	ft_printf("x = %d\n", x);// HACK: db
	ft_printf("i = %d\n", i);// HACK: db
	ft_printf("%s\n", xline[xi + 1]);// HACK: db
	if (!xline[xi + 1])
	{
		ft_printf("deu free\n");// HACK: db
		free_split(xline);
		xline = NULL;
	}
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
