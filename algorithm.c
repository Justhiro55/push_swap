/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhagiwar <hhagiwar@student.42Tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 16:16:26 by hhagiwar          #+#    #+#             */
/*   Updated: 2023/08/07 15:27:41 by hhagiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	two_cases_alg(struct stack *stack, int argc)
{
	if (argc == 2)
		return ;
	if (stack->data[0] < stack->data[1])
		swap(stack);
}

void	three_cases_alg(struct stack *stack)
{
	if (stack->data[0] > stack->data[2] && stack->data[2] > stack->data[1])
		swap(stack);
	else if (stack->data[2] > stack->data[1] && stack->data[1] > stack->data[0])
	{
		swap(stack);
		reverse_rotate(stack);
	}
	else if (stack->data[2] > stack->data[0] && stack->data[0] > stack->data[1])
		rotate(stack);
	else if (stack->data[1] > stack->data[0] && stack->data[0] > stack->data[2])
	{
		swap(stack);
		rotate(stack);
	}
	else if (stack->data[1] > stack->data[2] && stack->data[2] > stack->data[0])
		reverse_rotate(stack);
}

void	five_cases_alg(struct stack *stack_a, struct stack *stack_b)
{
	int	pointer;

	pointer = 0;
	while (stack_a->tail > 2)
	{
		while (stack_a->data[stack_a->tail] != pointer)
		{
			if (stack_a->data[0] == pointer)
				reverse_rotate(stack_a);
			else if (stack_a->data[1] == pointer)
			{
				reverse_rotate(stack_a);
				reverse_rotate(stack_a);
			}
			else
				rotate(stack_a);
		}
		push_b(stack_a, stack_b);
		pointer++;
	}
	three_cases_alg(stack_a);
	while (stack_b->tail != -1)
		push_a(stack_a, stack_b);
	return ;
}

void	other_cases_alg(struct stack *stack_a, struct stack *stack_b)
{
	int	min;
	int	chunk;

	min = 0;
	if (stack_a->tail >= 500)
		chunk = stack_a->tail / 18;
	else if ((stack_a->tail) / 9 >= 6)
		chunk = stack_a->tail / 9;
	else
		chunk = stack_a->tail;
	push_chunk(stack_a, stack_b, chunk, min);
	restore_chunk(stack_a, stack_b, min);
}
