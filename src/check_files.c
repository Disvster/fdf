/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 17:55:12 by manmaria          #+#    #+#             */
/*   Updated: 2025/11/19 19:02:46 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf.h"

static int	error_msg(char *str)
{
	ft_putstr_fd("Error: ", 2);
	ft_putstr_fd(str, 2);
	return (0);
}

int	check_valid_files(int ac, char **av)
{
	const char	*map;
	int			i;
	int			fd;

	fd = 0;
	i = 1;
	if (ac <= 1)
		return (error_msg("No file found\n"));
	map = ft_strnstr(av[i], ".fdf", ft_strlen(av[i]));
	if (!map)
		return (error_msg("Invalid map file\n"));
	fd = open(av[i], O_RDONLY);
	if (fd == -1)
		return (error_msg("Invalid file path or permissions\n"));
	close(fd);
	return (1);
}
