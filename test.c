/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 23:36:41 by manmaria          #+#    #+#             */
/*   Updated: 2025/09/23 23:53:01 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include "libft/incs/libft.h"

int	main(void)
{
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init(); //display init
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!"); //window init
}
