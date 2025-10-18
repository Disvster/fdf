/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 01:31:37 by manmaria          #+#    #+#             */
/*   Updated: 2025/10/18 01:16:13 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	1024
# endif

# include "../libft/incs/libft.h"
# include <unistd.h>
# include "../minilibx-linux/mlx.h"

typedef struct s_point
{
	int		x;
	int		y;
	int		z;
	char	*color;
}				t_point;

typedef struct s_map
{
	int		width;
	int		height;
	int		points_total;
}				t_map;

typedef struct s_data
{
	t_point	*points;
	t_map	*map;
}				t_data;

//Map Parsing
t_map	map_data_init(int fd);
void	*free_buffer(char *buffer);
void	set_point(t_data *data, int i, int x, char *buffer);
// void	set_point(t_point *point, int x, int y, char *buffer);
// t_point	*map_read_data(t_point *points, int width, int height, int fd);
void	*map_read_data(t_data *data, int fd);
void	parse_map(char *file_name);

#endif
