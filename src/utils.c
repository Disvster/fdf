/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 17:20:13 by manmaria          #+#    #+#             */
/*   Updated: 2025/11/03 17:25:34 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf.h"

int	error_exit(int fd)
{
	if (fd == -1)
		perror("File not found!\n");
	else
	{
		perror("Error\n");
		close (fd);
	}
	return (1);
}
