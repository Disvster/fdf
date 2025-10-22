/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xiaolin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 16:50:09 by manmaria          #+#    #+#             */
/*   Updated: 2025/10/22 18:26:43 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf.h"

float ft_abs_float(float nb)
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
	if (nb > 0)
		return (nb - i_partof_number(nb));
	else
		return (- nb + i_partof_number(nb));
}

float	rf_partof_number(float nb)
{
	return (1 - f_partof_number(nb));
}

// #include <stdio.h>
// int	main(void)
// {
// 	float i = -0.80;
//
// 	printf("i = %.2f\ni_partof_number(i) = %d\n", i, i_partof_number(i));
// 	printf("f_partof_number(i) = %.2f\n", f_partof_number(i));
// 	printf("rf_partof_number(i) = %.2f\n", rf_partof_number(i));
// 	return (0);
// }
