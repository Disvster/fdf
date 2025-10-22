#include "../incs/fdf.h"

void	print_map(t_data *data)
{
	int	y;
	int	x;
	int	i;

	y = 0;
	x = 0;
	i = 0;
	while (y < data->map->height)
	{
		while (x < data->map->width)
		{
			ft_printf(" %d,%d,%d,c%d ",
			 data->points[i].x, data->points[i].y, data->points[i].z, data->points[i].color);
			x++;
			i++;
			if (x == data->map->width)
				ft_printf("\n");
		}
		x = 0;
		y++;
	}
	ft_printf("\ntotal nbr of points -> %d\n", data->map->points_total);
	ft_printf("total nbr of coordinates set -> %d\n", i);
}

