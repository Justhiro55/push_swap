/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhagiwar <hhagiwar@student.42Tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 13:59:33 by hhagiwar          #+#    #+#             */
/*   Updated: 2023/10/30 16:11:58 by hhagiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	error_handling(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	// if (argc <= 2)
	// 	return (1);
	if (argc == 2 && argv[1][0] == '\0')
		return (1);
	return (0);
}

int	error_message(void)
{
	ft_printf("Error\n");
	return (1);
}

int	is_sorted(struct stack *stack_a, int argc)
{
	int	i;
	int	tmp;
	int	sorted_flag;

	i = 1;
	tmp = 0;
	sorted_flag = 1;
	while (i < argc - 1)
	{
		tmp = stack_a->data[i];
		if (stack_a->data[i - 1] < stack_a->data[i])
		{
			sorted_flag = 0;
			break ;
		}
		i++;
	}
	if (sorted_flag == 1)
		return (0);
	return (1);
}

int	error_dup_num(struct stack *stack)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i <= stack->tail)
	{
		while (i + j <= stack->tail)
		{
			if (stack->data[i] == stack->data[i + j])
				return (1);
			j++;
		}
		j = 1;
		i++;
	}
	return (0);
}
