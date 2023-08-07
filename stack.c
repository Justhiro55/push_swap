/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhagiwar <hhagiwar@student.42Tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 13:21:29 by hhagiwar          #+#    #+#             */
/*   Updated: 2023/08/07 15:12:18 by hhagiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pop_stack(struct stack *stack)
{
	int	ret;

	ret = 0;
	if (stack->tail == -1)
	{
		ft_printf("empty stack\n");
	}
	ret = stack->data[stack->tail];
	stack->tail = stack->tail - 1;
	return (ret);
}

void	init_stack(struct stack *stack, char name)
{
	stack->tail = -1;
	stack->name = name;
}

void	push_stack(struct stack *stack, int input)
{
	if (stack->tail >= 1000)
	{
		ft_printf("full stack\n");
		return ;
	}
	stack->tail = stack->tail + 1;
	stack->data[stack->tail] = input;
}
