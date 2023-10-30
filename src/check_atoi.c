/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_atoi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhagiwar <hhagiwar@student.42Tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 16:19:26 by hhagiwar          #+#    #+#             */
/*   Updated: 2023/10/30 16:11:51 by hhagiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	is_space_check(int c)
{
	if ((9 <= c && c <= 13) || c == 32)
	{
		return (1);
	}
	return (0);
}

static long	convert_int(const char *str, int minus)
{
	long int	num;

	num = 0;
	while (*str != '\0')
	{
		if ('0' <= *str && *str <= '9')
		{
			if ((-1) * (num) < INT_MIN && minus == 1)
				return (1);
			if (num > INT_MAX && minus == 0)
				return (1);
			num = num * 10 + (*str - '0');
		}
		else if (!('0' <= *str && *str <= '9'))
			return (1);
		str++;
	}
	if (minus == 1 && (-1) * num < INT_MIN)
		return (1);
	if (num > INT_MAX && minus == 0)
		return (1);
	return (0);
}

int	check_atoi(char *str)
{
	int	minus;

	minus = 0;
	while (*str != '\0' && is_space_check(*str) == 1)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			minus = 1;
		str++;
		if (*str == '\0')
			return (1);
		if (*str == '-' || *str == '+')
			return (1);
	}
	return (convert_int(str, minus));
}
