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

# ifndef BASE_COLOR
#  define BASE_COLOR	16711680
# endif

# include <X11/keysym.h>
# include <stdio.h>
# include <math.h>
# include <float.h>
# include <stdbool.h>
# include "../libft/incs/libft.h"
# include "../minilibx-linux/mlx.h"

# define ERR_MAL	"Memory Error \n"
# define IMG_WIDTH	1920
# define IMG_HEIGHT 1080 
# define ESC_KEY	9
# define Q_KEY		24
# define E_KEY		26
# define H_KEY		43
# define J_KEY		44
# define K_KEY		45
# define L_KEY		46

typedef struct s_view
{
	int		off_x;
	int		off_y;
	float	alpha;
	float	beta;
	float	gamma;
	float	scale;
	float	angle;
	float	z_scale;
	float	zoom;
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
	bool	has_color;
	char	py;
}				t_map;

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

typedef struct	s_hook
{
	bool	h;
	bool	j;
	bool	k;
	bool	l;
	bool	q;
	bool	e;
	bool	right;
	bool	left;
}				t_hook;

typedef struct s_data
{
	t_view	view;
	t_point	*points;
	t_map	map;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
	void	*mlx;
	void	*mlx_win;
	t_hook	keys;
	int		fd;
	//BONUS
	int		nb_maps;
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
void	parse_map(t_data *data, char *file_name);

// Free funcs
void	free_function(char **buffer, t_data *data);
int		error_exit(int fd, char *str);
int		fdf_close_window(t_data *data);

// Projection
void	fdf_init_window(t_data	*data);
void	fdf_init_view(t_data *data);
void	project(t_data *data, t_point *points);
void	transform(t_data *data);

// Draw
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	render_map(t_data *data);
void	draw_wuaa_line(t_point p0, t_point p1, t_data *data);
void	draw_wuaa_pixels(t_line *line, t_color *color, t_data *data);
void	draw_vertical_line(t_line *line, t_color *color, t_data *data);
void	prep_line_coords(t_line *line, t_point *p0, t_point *p1);

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
int		handle_color_code(char *str, t_data *data);

//Hooks
int		key_press(int keycode, t_data *data);
int		key_release(int keycode, t_data *data);
void	handle_changes(t_data *data);
void	clear_image(t_data *data);
void	handle_boundaries(t_data *data);

//BONUS
int	handle_multiple_maps(int ac, char **av);

#endif
