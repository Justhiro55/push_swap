/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhagiwar <hhagiwar@student.42Tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 16:15:53 by hhagiwar          #+#    #+#             */
/*   Updated: 2023/08/07 15:29:59 by hhagiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <string.h>

struct stack	*get_stack(int size, char *num[])
{
	int				sorted_flag;
	int				count;
	struct stack	*stack;
	int				i;

	i = 0;
	count = 0;
	sorted_flag = 0;
	stack = (struct stack *)malloc(sizeof(struct stack));
	if (stack == NULL)
		return (NULL);
	init_stack(stack, 'a');
	i = size;
	while (i-- > 1)
	{
		if (check_atoi(num[i]))
		{
			free(stack);
			return (NULL);
		}
		push_stack(stack, ft_atoi(num[i]));
	}
	return (stack);
}

int	push_swap(struct stack *stack_a, struct stack **stack_b, int argc)
{
	*stack_b = (struct stack *)malloc(sizeof(struct stack));
	if (*stack_b == NULL)
		return (1);
	init_stack(*stack_b, 'b');
	compress_data(stack_a);
	if (error_dup_num(stack_a))
	{
		printf("test\n");
		return (1);
	}
	if (!is_sorted(stack_a, argc))
		return (0);
	if (argc == 3)
		two_cases_alg(stack_a, argc);
	else if (argc == 4)
		three_cases_alg(stack_a);
	else if (argc <= 6)
		five_cases_alg(stack_a, *stack_b);
	else
		other_cases_alg(stack_a, *stack_b);
	return (0);
}

int	case_double_quote(char ***str, char *argv[])
{
	int		count;
	char	**new_str;
	int		i;

	count = 0;
	*str = ft_split(argv[1], ' ');
	while ((*str)[count] != NULL)
		count++;
	count++;
	new_str = (char **)malloc((count + 1) * sizeof(char *));
	if (new_str == NULL)
		return (-1);
	new_str[0] = ft_strdup("a.out");
	i = 0;
	while (i < count - 1)
	{
		new_str[i + 1] = ft_strdup((*str)[i]);
		i++;
	}
	new_str[count] = NULL;
	free_array(*str);
	*str = new_str;
	return (count);
}

int	main(int argc, char *argv[])
{
	struct stack	*stack_a;
	struct stack	*stack_b;
	char			**str;

	if (argc == 1)
		return (0);
	if (argc == 2)
	{
		argc = case_double_quote(&str, argv);
		argv = str;
	}
	if (error_handling(argc, argv))
		return (free_array_error(str));
	stack_a = get_stack(argc, argv);
	if (stack_a == NULL)
		return (free_array_error(str));
	if (push_swap(stack_a, &stack_b, argc))
	{
		free_all(&stack_a, &stack_b, str);
		return (error_message());
	}
	free_all(&stack_a, &stack_b, str);
	return (0);
}

// void	print_stack(struct stack *stack_a, struct stack *stack_b)
// {
// 	char	*char_a;
// 	char	*char_b;
// 	int		i;
// 	int		j;

// 	i = stack_a->tail;
// 	j = stack_b->tail;
// 	ft_printf("-----\n%d   %d\n-----\n", i + 1, j + 1);
// 	while (i >= 0 || j >= 0)
// 	{
// 		if (i >= 0)
// 			char_a = ft_itoa(stack_a->data[i]);
// 		else
// 			char_a = " ";
// 		if (j >= 0)
// 			char_b = ft_itoa(stack_b->data[j]);
// 		else
// 			char_b = "  ";
// 		ft_printf("%s   %s\n", char_a, char_b);
// 		i--;
// 		j--;
// 	}
// 	ft_printf("-   -\na   b\n");
// }

// __attribute__((destructor)) static void destructor()
// {
// 	system("leaks -q push_swap");
// }
