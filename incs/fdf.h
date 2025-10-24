/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 01:31:37 by manmaria          #+#    #+#             */
/*   Updated: 2025/10/23 20:18:50 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	1024
# endif

# include "../libft/incs/libft.h"
# include "../minilibx-linux/mlx.h"
# include <math.h>

typedef struct s_view
{
	int		off_x;
	int		off_y;
	double	alpha;
	double	beta;
	double	gamma;
	double	scale;
	double	angle;
	int		zoom;
}				t_view;

typedef struct s_point
{
	int		x;
	int		y;
	int		z;
	int		color;
	int		display[2];
}				t_point;

typedef struct s_disp
{
}				t_disp;

typedef struct s_map
{
	int		width;
	int		height;
	int		points_total;
}				t_map;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_data
{
	t_view	view;
	t_point	*points;
	t_map	map;
	t_img	*img;
}				t_data;

// Test Functions
void	print_map(t_data *data);
void	print_img(t_data *data);

// Split
size_t	count_words_fdf(char const *s, char *sep);
char	**ft_split_fdf(char const *s, char *c);

// Map Parsing
t_map	map_data_init(int fd);
void	*free_buffer(char *buffer);
void	set_point(t_data *data, int i, int x, char *buffer);
void	*map_read_data(t_data *data, int fd);
t_data	parse_map(char *file_name);
void	free_points(t_data *data);

// Projection
void	init_view(t_data *data);
void	project(t_data *data, t_point *points);
void	transform(t_data *data);

#endif
