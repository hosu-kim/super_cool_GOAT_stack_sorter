/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoskim <hoskim@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 22:12:21 by hoskim            #+#    #+#             */
/*   Updated: 2025/02/24 23:09:06 by hoskim           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h> // INT_MAX

/*
** ========================= STRUCTURES =========================
 */

// Structure for a single node in a stack
typedef struct s_stack
{
	t_node	*top_node;
	int		total_nodes;
}	t_stack;

// Structure representing a stack
typedef struct s_node
{
	int				stored_number;
	struct s_node	*next_node;
}	t_node;

// Structure for range values
typedef struct s_range
{
	int	min;
	int	max;
}	t_range;

/*
** ========================= STACK OPERATIONS =========================
 */

/* Basic Stack Management */
t_stack	*create_stack(void);
void	insert_number_into_stack(t_stack *stack, int number);
int		extract_top_node_and_number(t_stack *stack);
void	free_stacks(t_stack *stack_a, t_stack *stack_b);

/* Stack Operation Commands */
// Push the head node to another stack.
void	push_node_from_b_to_a(t_stack *stack_a, t_stack *stack_b);
void	push_node_from_a_to_b(t_stack *stack_a, t_stack *stack_b);

// Swap the head node and the second node of the body 
// (ss: done in the both stacks)
void	swap_head_and_second_node(t_stack *stack);
void	swap_in_a(t_stack *stack_a);
void	swap_in_b(t_stack *stack_b);
void	swap_both(t_stack *stack_a, t_stack *stack_b);

// Rotate the top_node element of one stack or both to the bottom.
void	rotate_head_to_tail(t_stack *stack);
void	rotate_in_a(t_stack *stack_a);
void	rotate_in_b(t_stack *stack_b);
void	rotate_both(t_stack *stack_a, t_stack *stack_b);

// Reverse rotate the bottom element of one stack or both to the top_node.
void	reverse(t_stack *stack);
void	reverse_in_a(t_stack *stack_a);
void	reverse_tail_to_head_b(t_stack *stack_b);
void	reverse_both(t_stack *stack_a, t_stack *stack_b);

/*
** ========================= SORTING ALGORITHMS =========================
*/
/* Main Sorting Functions */
void	sort_stacks(t_stack *stack_a, t_stack *stack_b);

/* Size-specific Sorting */
void	sort_two_numbers(t_stack *stack_a);
void	sort_three_numbers(t_stack *stack_a);
void	sort_four_five(t_stack *stack_a, t_stack *stack_b);
void	sort_large(t_stack *stack_a, t_stack *stack_b);

/*
** ========================= UTILITY FUNCTIONS =========================
*/

/* Stack Analysis Utils */
t_range	get_number_range(t_stack *stack);
int		find_position_of_minimum(t_stack *stack);
int		find_position_of_maximum(t_stack *stack);
int		get_target_position(t_stack *stack, int target_num);

/* General Utils*/
void	error_exit(void);
int		ft_atoi(const char *str);
void	same_number_checker(t_stack *stack);
int		is_sorted(t_stack *stack);

#endif
