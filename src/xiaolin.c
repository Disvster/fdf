/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xiaolin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 16:50:09 by manmaria          #+#    #+#             */
/*   Updated: 2025/11/03 05:25:55 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf.h"

float	ft_abs_fl(float nb)
{
	if (nb >= 0)
		return (nb);
	else
		return (nb * -1);
}

int	i_partof_number(float nb)
{
	return ((int)nb);
}

float	f_partof_number(float nb)
{
	return (ft_abs_fl(nb - i_partof_number(nb)));
}

float	rf_partof_number(float nb)
{
	return (1 - f_partof_number(nb));
}

float	interpl(int n, int start, int end)
{
	return ((float)(n - start) / (float)(end - start));
}
