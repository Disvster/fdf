/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 17:20:13 by manmaria          #+#    #+#             */
/*   Updated: 2025/11/15 18:16:37 by manmaria         ###   ########.fr       */
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
	return (0);
}

void	free_function(char **buffer, t_data *data)
{
	if (buffer && *buffer)
	{
		free(*buffer);
		if (data)
		{
			*buffer = get_next_line(data->fd);
			while (*buffer)
			{
				free(*buffer);
				*buffer = get_next_line(data->fd);
			}
		}
		*buffer = NULL;
	}
	if (data && data->points)
	{
		free(data->points);
		data->points = NULL;
	}
}

float	interpl(int n, int start, int end)
{
	return ((float)(n - start) / (float)(end - start));
}
