/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhagiwar <hhagiwar@student.42Tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 16:59:10 by hhagiwar          #+#    #+#             */
/*   Updated: 2023/10/30 16:12:04 by hhagiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	free_array(char **str)
{
	int	i;

	i = 0;
	if (str != NULL)
	{
		while (str[i] != NULL)
		{
			free(str[i]);
			i++;
		}
		free(str);
	}
	return (0);
}

int	free_array_error(char **str)
{
	int	i;

	i = 0;
	if (str != NULL)
	{
		while (str[i] != NULL)
		{
			free(str[i]);
			i++;
		}
		free(str);
	}
	error_message();
	return (0);
}

void	free_stacks(struct stack **stack_a, struct stack **stack_b)
{
	if (*stack_a != NULL)
	{
		free(*stack_a);
		*stack_a = NULL;
	}
	if (*stack_b != NULL)
	{
		free(*stack_b);
		*stack_b = NULL;
	}
}

int	free_stack(struct stack *stack)
{
	if (stack == NULL)
		return (0);
	free(stack);
	stack = NULL;
	return (0);
}

void	free_all(struct stack **stack_a, struct stack **stack_b, char **str)
{
	int	i;

	if (*stack_a != NULL)
	{
		free(*stack_a);
		*stack_a = NULL;
	}
	if (*stack_b != NULL)
	{
		free(*stack_b);
		*stack_b = NULL;
	}
	i = 0;
	if (str != NULL)
	{
		while (str[i] != NULL)
		{
			free(str[i]);
			i++;
		}
		free(str);
	}
}
