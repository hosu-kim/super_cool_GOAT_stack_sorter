/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_range_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoskim <hoskim@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 18:56:40 by hoskim            #+#    #+#             */
/*   Updated: 2025/02/25 18:56:40 by hoskim           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Finds the minimum and maximum values in a stack
 * 
 * This function traverses the entire stack once to determine both the
 * smallest and largest values stored in any nodes. These values are returned
 * as a t_range structure containing the min and max fields.
 * 
 * @param stack The stack to analyze
 * @return t_range A structure containing:
 *                 - min: The minimum value found in the stack
 *                 - max: The maximum value found in the stack
 *                 If the stack is empty or NULL, both min and max are set to 0
 */
t_range	find_number_range(t_stack *stack)
{
	t_range	number_range;
	t_node	*current_node;

	if (!stack || !stack->top_node)
	{
		number_range.min = 0;
		number_range.max = 0;
		return (number_range);
	}
	number_range.min = stack->top_node->stored_number;
	number_range.max = stack->top_node->stored_number;
	current_node = stack->top_node->next_node;
	while (current_node)
	{
		if (current_node->stored_number < number_range.min)
			number_range.min = current_node->stored_number;
		if (current_node->stored_number > number_range.max)
			number_range.max = current_node->stored_number;
		current_node = current_node->next_node;
	}
	return (number_range);
}
