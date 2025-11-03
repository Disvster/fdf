/** ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 01:31:37 by manmaria          #+#    #+#             */
/*   Updated: 2025/11/03 17:23:26 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	1024
# endif

# ifndef BASE_COLOR
#  define BASE_COLOR	16711680
# endif

# include <stdio.h>
# include <math.h>
# include <float.h>
# include "../libft/incs/libft.h"
# include "../minilibx-linux/mlx.h"
# ifndef IMG_WIDTH 
# define IMG_WIDTH 1000
# endif
# ifndef IMG_HEIGTH 
# define IMG_HEIGHT 1000
# endif

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
	float	t_x;
	float	t_y;
}				t_point;

typedef struct s_color
{
	int		r;
	int		r0;
	int		r1;
	int		g;
	int		g0;
	int		g1;
	int		b;
	int		b0;
	int		b1;
	int		final;
	float	main_opa;
	float	adja_opa;
}				t_color;

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

typedef struct s_line
{
	float	delta_x;
	float	delta_y;
	float	gradient;
	float	intersect_y;
	int		x;
	int		y;
	int		x0;
	int		x1;
	int		y0;
	int		y1;
    int		steep;
}				t_line;

typedef struct s_data
{
	t_view	view;
	t_point	*points;
	t_map	map;
	t_img	*img;
	int		fd;
}				t_data;

// Test Functions
void	print_map(t_data *data);
void	print_img(t_data *data);

// Split
size_t	count_words_fdf(char const *s, char *sep);
char	**ft_split_fdf(char const *s, char *c);

// Map Parsing
t_map	map_init_data(int fd);
void	set_point(t_data *data, int i, int x, char *buffer);
void	map_read_data(t_data *data, int fd);
t_data	parse_map(char *file_name);

// Free funcs
void	free_function(char **buffer, t_data *data);
int		error_exit(int fd);

// Projection
void	init_view(t_data *data);
// void	project(t_data *data, t_point *points);
void	project(t_data *data, t_point *points, float *min_x, float *min_y);
void	transform(t_data *data);

void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
void	render_map(t_data *data);
void	draw_wuaa_line(t_point p0, t_point p1, t_data *data);
void	draw_wuaa_pixels(t_line *line, t_color *color, t_data *data);
void	prep_line_coords(t_line *line, t_point *p0, t_point *p1);
void	draw_vertical_line(t_line *line, t_color *color, t_data *data);

//Xiaolin Utils
void	ft_swap(int *a, int *b);
float	ft_abs_fl(float nb);
int		i_partof_number(float nb);
float	f_partof_number(float nb);
float	rf_partof_number(float nb);
float	interpl(int n, int start, int end);

// Colors
void	set_points_color(t_data *data);
int		set_height_color(float norm);
int		set_pixel_opacity(int old_color, float intensity);
int		get_pixel_color(t_color color, float inter);
t_color	init_t_color(t_point *p0, t_point *p1);

#endif
