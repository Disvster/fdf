/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 17:20:13 by manmaria          #+#    #+#             */
/*   Updated: 2025/11/08 22:06:34 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf.h"

int	error_exit(int fd, char *str)
{
	if (fd == -1)
		perror("File not found!\n");
	else
	{
		if (str)
			perror(str);
		if (fd > -1)
			close (fd);
	}
	return (1);
}

void	free_function(char **buffer, t_data *data)
{
	if (buffer && *buffer)
	{
		free(*buffer);
		*buffer = NULL;
	}
	if (data && data->points)
	{
		free(data->points);
		data->points = NULL;
	}
	if (data && data->mlx)
	{
		mlx_destroy_image(data->mlx, data->img);
		mlx_destroy_window(data->mlx, data->mlx_win);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		data->mlx = NULL;
	}
}

float	interpl(int n, int start, int end)
{
	return ((float)(n - start) / (float)(end - start));
}
