/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 16:47:27 by manmaria          #+#    #+#             */
/*   Updated: 2025/10/22 16:52:03 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/libft.h"

int	ft_abs(int nb)
{
	if (nb >= 0)
		return (nb);
	else
		return (nb * -1);
}

float ft_abs_float(int nb)
{
	if (nb >= 0)
		return (nb);
	else
		return (nb * -1);
}
