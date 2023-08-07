/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhagiwar <hhagiwar@student.42Tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 16:19:26 by hhagiwar          #+#    #+#             */
/*   Updated: 2023/07/18 11:58:02 by hhagiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_space(int c)
{
	if ((9 <= c && c <= 13) || c == 32)
	{
		return (1);
	}
	return (0);
}

long	convert_int(const char *str, int minus)
{
	long int	num;
	long int	longmax_div;
	long int	longmax_mod;

	num = 0;
	longmax_div = LONG_MAX / 10;
	longmax_mod = LONG_MAX % 10;
	while (*str != '\0' && '0' <= *str && *str <= '9')
	{
		if (num > longmax_div || (longmax_div == num && longmax_mod < *str
				- '0'))
		{
			if (minus == 1)
				return ((int)LONG_MAX);
			else
				return ((int)LONG_MIN);
		}
		num = num * 10 + (*str - '0');
		str++;
	}
	return ((int)num * minus);
}

int	ft_atoi(const char *str)
{
	int	minus;

	minus = 1;
	while (*str != '\0' && is_space(*str) == 1)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			minus = (-1);
		str++;
		if (*str == '-' || *str == '+')
			return (0);
	}
	return (convert_int(str, minus));
}
