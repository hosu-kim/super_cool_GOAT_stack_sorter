/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoskim <hoskim@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 00:52:29 by hoskim            #+#    #+#             */
/*   Updated: 2025/02/28 20:16:27 by hoskim           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Sorts a stack containing exactly two numbers
 * 
 * This functio checks if the two numbers in the stack are in ascending order.
 * If they are not (i.e., first_number > second_number), it performs a swap
 * operation to place them in the correct order.
 * 
 * Example: If stack_a = {2, 1}, after sorting it becomes {1. 2}
 * 
 * @param stack_a The stack containing two numbers to be sorted
 * @return void
 */
void	sort_two_numbers(t_stack *stack_a)
{
	int	first_number;
	int	second_number;

	first_number = stack_a->top_node->stored_number;
	second_number = stack_a->top_node->next_node->stored_number;
	if (first_number > second_number)
		swap_in_a(stack_a);
}

/**
 * @breif Sorts a stack containing exactly three numbers
 * 
 * This function handles all posiible permutations fo three numbers by
 * identifying the pattern and applying the appropriate sequence of operations.
 * 
 * The five possible unsorted cases and their solutions:
 * - Case 1: {2, 1, 3} -> swap_in_a
 * - Case 2: {3, 1, 2} -> rotate_in_a
 * - Case 3: {2, 3, 1} -> reverse_in_a
 * - Case 4: {1, 3, 2} -> swap_in_a + rotate_in_a
 * - Case 5: {3, 2, 1} -> swap_in_a + reverse_in_a
 * 
 * @param stack_a The stack containing three numbers to be sorted
 * @return void
 */
void	sort_three_numbers(t_stack *stack_a)
{
	int	first;
	int	second;
	int	third;

	first = stack_a->top_node->stored_number;
	second = stack_a->top_node->next_node->stored_number;
	third = stack_a->top_node->next_node->next_node->stored_number;
	if (first > second && second < third && first < third)
		swap_in_a(stack_a);
	else if (first > second && second < third && first > third)
		rotate_in_a(stack_a);
	else if (first < second && second > third && first > third)
		reverse_in_a(stack_a);
	else if (first < second && second > third && first < third)
	{
		swap_in_a(stack_a);
		rotate_in_a(stack_a);
	}
	else if (first > second && second > third)
	{
		swap_in_a(stack_a);
		reverse_in_a(stack_a);
	}
}

/**
 * @brief Sorts a stack containing four or five numbers
 * 
 * This function implements an optimized algorithm for sorting small arrays:
 * -# Repeatedly finds the minimum value and moves it to the top of stack A
 * -# Pushes the minimum value to stack B until only three elements remain in
 *    Stack A
 * -# Sorts the three remaining elements in stack A using sort_three_numbers
 * -# Pushes all elements from stack B back to stack A
 * 
 * @note Uses find_position_of_minimum() from sort_utils.c to locate
 *       the minimum value
 * 
 * @param stack_a The main stack containing unsorted elements (4 or 5 numbers)
 * @param stack_b the auxiliary stack used for temporary storage
 * @return void
 */
void	sort_four_or_five(t_stack *stack_a, t_stack *stack_b)
{
	int	target_position;

	while (stack_a->total_nodes > 3)
	{
		target_position = find_position_of_minimum(stack_a);
		while (target_position != 1)
		{
			move_target_node_to_top(stack_a, target_position);
			target_position = find_position_of_minimum(stack_a);
		}
		push_top_a_to_b(stack_a, stack_b);
	}
	sort_three_numbers(stack_a);
	while (stack_b->total_nodes > 0)
		push_top_b_to_a(stack_a, stack_b);
}
