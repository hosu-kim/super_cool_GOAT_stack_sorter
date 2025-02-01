/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoskim <hoskim@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 22:12:21 by hoskim            #+#    #+#             */
/*   Updated: 2025/02/01 18:55:54 by hoskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

// Structure for a single node in a linked list.
typedef struct s_node
{
	int				number;
	struct s_node	*next;
}	t_node;

// Structure representing a stack.
typedef struct s_stack
{
	t_node	*top_node;
	int		num_of_nodes;
}	t_stack;

// operations_swap.c
// Swap the top_node two elements of one stack or both.
void	sa(t_stack *stack_a);
void	sb(t_stack *stack_b);
void	ss(t_stack *stack_a, t_stack *stack_b);
// Push the top_node element of one stack to another.
void	pa(t_stack *stack_a, t_stack *stack_b);
void	pb(t_stack *stack_a, t_stack *stack_b);
// Rotate the top_node element of one stack or both to the bottom.
void	ra(t_stack *stack_a);
void	rb(t_stack *stack_b);
void	rr(t_stack *stack_a, t_stack *stack_b);
// Rotate the bottom element of one stack or both to the top_node.
void	rra(t_stack *stack_a);
void	rrb(t_stack *stack_b);
void	rrr(t_stack *stack_a, t_stack *stack_b);

// stack_sorter_utils.c
int		get_min_num(t_stack *stack);
int		get_max_num(t_stack *stack);
void	sort_big(t_stack *stack_a, t_stack *stack_b);

// stack_sorter.c
t_stack	*init_stack(void);
void	push(t_stack *stack, int number);
int		pop(t_stack *stack);
void	clear_stack(t_stack *stack);

// utils.c
void	error_exit(void);
int		ft_atoi(const char *str);
void	same_number_checker(t_stack *stack);
int		is_sorted(t_stack *stack);

// sort.c
void	sort_three_nums(t_stack *stack_a);
void	sort_stack(t_stack *stack_a, t_stack *stack_b);

#endif
