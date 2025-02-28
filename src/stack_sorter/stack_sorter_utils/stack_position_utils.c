/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_position_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoskim <hoskim@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 02:30:03 by hoskim            #+#    #+#             */
/*   Updated: 2025/02/28 20:33:20 by hoskim           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @breif Finds the position of the minimum value in the stack
 * 
 * This function traverses the entire stack to find the node with
 * the smallest stared number value and returns its position.
 * Position counting starts at 1 for the top node.
 * 
 * @param stack The stack to search in
 * @return int The position of the node with the minimum value (1-idexed),
 *             or 0 if the stack is empty or NULL
 */
int	find_position_of_minimum(t_stack *stack)
{
	t_node	*current_node;
	int		minimum_number;
	int		current_position;
	int		position_of_minimum;

	if (!stack || !stack->top_node)
		return (0);
	minimum_number = stack->top_node->stored_number;
	current_node = stack->top_node->next_node;
	current_position = 2;
	position_of_minimum = 1;
	while (current_node)
	{
		if (current_node->stored_number < minimum_number)
		{
			minimum_number = current_node->stored_number;
			position_of_minimum = current_position;
		}
		current_node = current_node->next_node;
		current_position++;
	}
	return (position_of_minimum);
}

/**
 * @brief Finds the position of the maximum value in the stack
 * 
 * This function traverses the entire stack to find the node with
 * the largest stored number value and returns its position.
 * Position counting starts at 1 for the top node.
 * 
 * @param stack The stack to search in
 * @return int The position of the node with the maximum value (1-indexed),
 *             or 0 if the stack is empty or NULL
 */
int	find_position_of_maximum(t_stack *stack)
{
	t_node	*current_node;
	int		maximum_number;
	int		current_position;
	int		position_of_maximum;

	if (!stack || !stack->top_node)
		return (0);
	maximum_number = stack->top_node->stored_number;
	current_node = stack->top_node->next_node;
	current_position = 2;
	position_of_maximum = 1;
	while (current_node)
	{
		if (current_node->stored_number > maximum_number)
		{
			maximum_number = current_node->stored_number;
			position_of_maximum = current_position;
		}
		current_node = current_node->next_node;
		current_position++;
	}
	return (position_of_maximum);
}

/**
 * @brief Finds the position of the first node with a value within a given range
 * the specified chunk range (inclusive of min and max values) and returns
 * its position.
 * Position counting starts at 1 for the top node.
 * 
 * @param stack The stack to search in
 * @param chunk A range structure containing the minimum and maximum values
 *              to match
 * @return int The position of the first node with a value in the specified
 *             range (1-indexed), -1 if no matching node is found,
 *             or 0 if the stack is empty or NULL
 */
int	find_position_of_num_in_chunk_range(t_stack *stack, t_range chunk)
{
	t_node	*current_node;
	int		position_of_current_node;

	current_node = stack->top_node;
	position_of_current_node = 1;
	if (!stack || !current_node)
		return (0);
	while (current_node)
	{
		if (current_node->stored_number >= chunk.min && \
			current_node->stored_number <= chunk.max)
			return (position_of_current_node);
		position_of_current_node++;
		current_node = current_node->next_node;
	}
	return (-1);
}
