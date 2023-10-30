/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhagiwar <hhagiwar@student.42Tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 16:27:00 by hhagiwar          #+#    #+#             */
/*   Updated: 2023/10/30 16:11:55 by hhagiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	compress_data(struct stack *stack)
{
	int	compressed[1000];
	int	i;
	int	j;

	i = 0;
	while (i <= stack->tail)
	{
		compressed[i] = 0;
		j = 0;
		while (j <= stack->tail)
		{
			if (stack->data[j] < stack->data[i])
				compressed[i]++;
			j++;
		}
		i++;
	}
	i = -1;
	while (i++ <= stack->tail)
		stack->data[i] = compressed[i];
}
