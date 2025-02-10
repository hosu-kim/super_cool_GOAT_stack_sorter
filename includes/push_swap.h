/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoskim <hoskim@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 22:12:21 by hoskim            #+#    #+#             */
/*   Updated: 2025/02/10 22:15:40 by hoskim           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h> // INT_MAX

// Structure representing a stack.
typedef struct s_stack
{
	t_node	*top_node;
	int		total_nodes;
}	t_stack;

// Structure for a single node in a linked list.
typedef struct s_node
{
	int				stored_number;
	struct s_node	*next_node;
}	t_node;

typedef struct s_range
{
	int	min;
	int	max;
}	t_range;

// operations_swap.c
// Push the top_node element of one stack to another.
void	pa(t_stack *stack_a, t_stack *stack_b);
void	pb(t_stack *stack_a, t_stack *stack_b);
// Swap the top_node two elements of one stack or both.
void	swap(t_stack *stack);
void	sa(t_stack *stack_a);
void	sb(t_stack *stack_b);
void	ss(t_stack *stack_a, t_stack *stack_b);
// Rotate the top_node element of one stack or both to the bottom.
void	ra(t_stack *stack_a);
void	rb(t_stack *stack_b);
void	rr(t_stack *stack_a, t_stack *stack_b);
// Reverse rotate the bottom element of one stack or both to the top_node.
void	reverse(t_stack *stack);
void	rra(t_stack *stack_a);
void	rrb(t_stack *stack_b);
void	rrr(t_stack *stack_a, t_stack *stack_b);

// stack_manager.c
t_stack	*stack_setup(void);
void	insert_number_into_stack(t_stack *stack, int number);
int		pop(t_stack *stack);
void	print_stack(t_stack *stack_a);
void	clear_stacks(t_stack *stack_a, t_stack *stack_b);

// sort_large.c
void	sort_large(t_stack *stack_a, t_stack *stack_b);

// sort_manager.c
void	sort_stacks(t_stack *stack_a, t_stack *stack_b);

// sort_small.c
void	sort_two(t_stack *stack_a);
void	sort_three(t_stack *stack_a);
void	sort_small(t_stack *stack_a, t_stack *stack_b);

// sort_utils.c
t_range	get_stack_range(t_stack *stack);
int		find_min_position(t_stack *stack);
int		find_max_position(t_stack *stack);
int		get_target_position(t_stack *stack, int target_num);

// general_utils.c
void	error_exit(void);
int		ft_atoi(const char *str);
void	ft_putnbr(int n);
//general_utils2.c
void	same_number_checker(t_stack *stack);
int		is_sorted(t_stack *stack);

#endif
