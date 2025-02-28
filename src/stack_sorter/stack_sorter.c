/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sorter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoskim <hoskim@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 18:09:58 by hoskim            #+#    #+#             */
/*   Updated: 2025/02/28 20:42:02 by hoskim           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Dispatches to the appropriate sorting algorithm based on array size
 * 
 * This function acts as a controller that selects and calls the optimal sorting
 * algorithm based on the number of elements in stack_a:
 * - For 2 elements: Uses a simple two-number sorting algorithm
 * - For 3 elements: Uses an optimized three_number sorting algorithm
 * - For 4-5 elements: Uses a specialized algorithnm for small arrays
 * - For 6+ elements: Uses a chunk-based algorithm optimized for larger arrays
 * 
 * The function ensures that each case is handled with the most efficient
 * algorithm for that specific number of elements, minimizing the number of
 * operations required to sort the stack
 * 
 * @param stack_a The main stack containing unsorted elements
 * @param stack_b The auxiliary stack used in sorting operations
 * @return void
 */
void	sort_stacks(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->total_nodes == 2)
		sort_two_numbers(stack_a);
	else if (stack_a->total_nodes == 3)
		sort_three_numbers(stack_a);
	else if (stack_a->total_nodes <= 5)
		sort_four_or_five(stack_a, stack_b);
	else
		sort_large(stack_a, stack_b);
}
