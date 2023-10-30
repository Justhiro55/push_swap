/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_alg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhagiwar <hhagiwar@student.42Tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 15:43:16 by hhagiwar          #+#    #+#             */
/*   Updated: 2023/10/30 16:12:09 by hhagiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	search_num(struct stack *stack_a, int start, int chunk, int i)
{
	if (start <= stack_a->data[stack_a->tail - i]
		&& stack_a->data[stack_a->tail - i] < start + chunk)
	{
		if (stack_a->data[stack_a->tail - i] == start)
			return (3);
		return (1);
	}
	if (start <= stack_a->data[i] && stack_a->data[i] < start + chunk)
		return (2);
	return (0);
}

void	push_chunk_util(struct stack *stack_a, struct stack *stack_b, int chunk,
		int start)
{
	int	i;

	i = 0;
	while (1)
	{
		if (search_num(stack_a, start, chunk, i) == 1)
		{
			while (!(start <= stack_a->data[stack_a->tail]
					&& stack_a->data[stack_a->tail] < start + chunk))
				rotate(stack_a);
			break ;
		}
		i++;
	}
	push_b(stack_a, stack_b);
}

int	push_chunk(struct stack *stack_a, struct stack *stack_b, int chunk,
		int start)
{
	int	chunk_top_10;
	int	j;

	j = 0;
	while (stack_a->tail != -1)
	{
		chunk_top_10 = chunk * 0.85;
		push_chunk_util(stack_a, stack_b, chunk, start);
		if (chunk_top_10 <= stack_b->data[stack_b->tail])
			rotate(stack_b);
		if (stack_a->tail == 0)
			push_b(stack_a, stack_b);
		chunk++;
		j++;
	}
	return (j);
}

int	restore_chunk_util(struct stack *stack_a, struct stack *stack_b)
{
	push_a(stack_a, stack_b);
	if (stack_a->tail != 0)
	{
		while (stack_a->data[stack_a->tail] != 0)
			rotate(stack_a);
	}
	return (-1);
}

void	restore_chunk(struct stack *stack_a, struct stack *stack_b, int min)
{
	int	i;

	i = 0;
	while (stack_b->tail != -1)
	{
		if (stack_b->data[stack_b->tail - i] == min)
		{
			while (stack_b->data[stack_b->tail] != min)
				rotate(stack_b);
			min++;
			i = restore_chunk_util(stack_a, stack_b);
		}
		else if (stack_b->data[i] == min)
		{
			while (stack_b->data[stack_b->tail] != min)
				reverse_rotate(stack_b);
			min++;
			i = restore_chunk_util(stack_a, stack_b);
		}
		i++;
	}
}
