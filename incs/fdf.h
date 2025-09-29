/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 01:31:37 by manmaria          #+#    #+#             */
/*   Updated: 2025/09/25 01:35:34 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	1024
# endif

# include "../libft/incs/libft.h"
# include <unistd.h>
# include "mlx.h"

typedef struct s_map
{
	int		width;
	int		height;
	int		points_total;
}				t_map;

typedef struct s_point
{
	int		x;
	int		y;
	int		z;
	char	*color;
}				t_point;

typedef struct s_data
{
	t_point	*points;
	t_map	*map;
}				t_data;

#endif
