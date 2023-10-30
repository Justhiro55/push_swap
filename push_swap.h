/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhagiwar <hhagiwar@student.42Tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 16:07:02 by hhagiwar          #+#    #+#             */
/*   Updated: 2023/10/30 16:11:37 by hhagiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./func/ft_printf/ft_printf.h"
# include "./func/libft/libft.h"

typedef struct stack
{
	int		size;
	int		data[1000];
	int		tail;
	char	name;
}			t_stack;

int			error_message(void);
int			error_handling(int argc, char *argv[]);
int			is_sorted(struct stack *stack_a, int argc);
int			*compress_stack(int *stack, int size, int *stack_compression);
int			pop_stack(struct stack *stack);
void		push_stack(struct stack *stack, int input);
void		init_stack(struct stack *stack, char name);
void		print_stack(struct stack *stack_a, struct stack *stack_b);
void		compress_data(struct stack *stack);
void		swap(struct stack *stack);
void		rotate(struct stack *stack);
void		reverse_rotate(struct stack *stack);
void		push_a(struct stack *stack_a, struct stack *stack_b);
void		push_b(struct stack *stack_a, struct stack *stack_b);
void		two_cases_alg(struct stack *stack, int argc);
void		three_cases_alg(struct stack *stack);
void		five_cases_alg(struct stack *stack_a, struct stack *stack_b);
void		other_cases_alg(struct stack *stack_a, struct stack *stack_b);

int			push_chunk(struct stack *stack_a, struct stack *stack_b,
				int chunk_num, int start);
void		restore_chunk(struct stack *stack_a, struct stack *stack_b,
				int min);
int			error_dup_num(struct stack *stack);
int			check_atoi(char *str);
int			free_stack(struct stack *stack);
void		free_stacks(struct stack **stack_a, struct stack **stack_b);
int			free_array(char **str);
void		free_all(struct stack **stack_a, struct stack **stack_b,
				char **str);
int			free_array_error(char **str);

#endif