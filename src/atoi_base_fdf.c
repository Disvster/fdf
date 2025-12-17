/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_base_fdf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 00:40:25 by manmaria          #+#    #+#             */
/*   Updated: 2025/11/26 01:08:38 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf.h"

static int	verify_base(char *base, char *str)
{
	int	i;
	int	c;
	int	*verify;

	i = 0;
	c = 0;
	while (str && *str)
		if (!check_sep_fdf(*str++, base))
			return (0);
	verify = malloc(sizeof(int) * 128);
	while (c < 128)
		verify[c++] = 0;
	while (base[i])
	{
		c = (int)base[i];
		if (base[i] == ' ' || base[i] == '+' || verify[c] == 1
			|| (base[i] >= 9 && base[i] <= 13) || base[i] == ' ')
			return (0);
		if (!verify[c])
			verify[c]++;
		i++;
	}
	free (verify);
	return (i);
}

static int	nb_base(char base_char, char *base)
{
	int	ib;

	ib = 0;
	while (base[ib])
	{
		if (base_char == base[ib])
			return (ib);
		ib++;
	}
	return (-1);
}

static int	is_negative(char *str, int *ptr_i)
{
	int	ni;
	int	sign;

	ni = 0;
	sign = 1;
	while ((str[ni] >= 9 && str[ni] <= 14) || str[ni] == 32)
		ni++;
	while (str[ni] == '+' || str[ni] == '-')
	{
		if (str[ni] == '-')
			sign *= -1;
		ni++;
	}
	*ptr_i = ni;
	return (sign);
}

int	atoi_base_fdf(char *str, char *base)
{
	int	i;
	int	res;
	int	sign;
	int	base_len;
	int	ib2;

	sign = 1;
	i = 0;
	res = 0;
	base_len = ft_strlen(base);
	if (base_len == 1 || base_len == 0 || !verify_base(base, str))
		return (0);
	sign = is_negative(str, &i);
	ib2 = nb_base(str[i], base);
	while (str[i] && ib2 != -1)
	{
		res = (res * base_len) + ib2;
		i++;
		ib2 = nb_base(str[i], base);
	}
	return (res * sign);
}
