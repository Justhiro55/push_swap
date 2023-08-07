/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhagiwar <hhagiwar@student.42Tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 17:00:38 by hhagiwar          #+#    #+#             */
/*   Updated: 2023/07/26 17:22:15 by hhagiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(struct stack *stack)
{
	int	tmp;

	if (stack->name == 'a')
		ft_printf("sa\n");
	else if (stack->name == 'b')
		ft_printf("sb\n");
	if (stack->tail == -1)
		return ;
	tmp = stack->data[stack->tail];
	stack->data[stack->tail] = stack->data[stack->tail - 1];
	stack->data[stack->tail - 1] = tmp;
}

void	push_a(struct stack *stack_a, struct stack *stack_b)
{
	ft_printf("pa\n");
	push_stack(stack_a, pop_stack(stack_b));
}

void	push_b(struct stack *stack_a, struct stack *stack_b)
{
	ft_printf("pb\n");
	push_stack(stack_b, pop_stack(stack_a));
}

void	rotate(struct stack *stack)
{
	int	last;
	int	i;

	if (stack->name == 'a')
		ft_printf("ra\n");
	else if (stack->name == 'b')
		ft_printf("rb\n");
	i = 0;
	if (stack->tail == -1)
		return ;
	last = stack->data[stack->tail];
	while (i <= stack->tail)
	{
		stack->data[stack->tail - i] = stack->data[stack->tail - i - 1];
		i++;
	}
	stack->data[0] = last;
}

void	reverse_rotate(struct stack *stack)
{
	int	first;
	int	i;

	if (stack->name == 'a')
		ft_printf("rra\n");
	else if (stack->name == 'b')
		ft_printf("rrb\n");
	i = 0;
	if (stack->tail == -1)
		return ;
	first = stack->data[0];
	while (i <= stack->tail)
	{
		stack->data[i] = stack->data[i + 1];
		i++;
	}
	stack->data[stack->tail] = first;
}
