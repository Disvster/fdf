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

#include "mlx.h"
#include "../libft/incs/libft.h"

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;

}				t_data;

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init(); //display init
	if (!mlx)
		return (1);
	//mlx_win = mlx_new_window(mlx, 192, 108, "Hello world!"); //window init
	img.img = mlx_new_image(mlx, 192, 108);
	// check what's below
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
}
