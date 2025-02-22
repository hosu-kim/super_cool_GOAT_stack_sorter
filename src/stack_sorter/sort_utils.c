/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoskim <hoskim@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 02:30:03 by hoskim            #+#    #+#             */
/*   Updated: 2025/02/22 17:57:27 by hoskim           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_range	get_stack_range(t_stack *stack)
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
		if (number_range.min > current_node->stored_number)
			number_range.min = current_node->stored_number;
		if (number_range.max < current_node->stored_number)
			number_range.max = current_node->stored_number;
		current_node = current_node->next_node;
	}
	return (number_range);
}

int	find_position_of_minimum(t_stack *stack)
{
	t_node	*current_node;
	int		minimum_number;
	int		current_node_position;
	int		position_of_minumum;

	if (!stack || !stack->top_node)
		return (0);
	minimum_number = stack->top_node->stored_number;
	current_node = stack->top_node->next_node;
	current_node_position = 2;
	position_of_minumum = 1;
	while (current_node)
	{
		if (current_node->stored_number < minimum_number)
		{
			minimum_number = current_node->stored_number;
			position_of_minumum = current_node_position;
		}
		current_node = current_node->next_node;
		current_node_position++;
	}
	return (position_of_minumum);
}

int	find_position_of_maximum(t_stack *stack)
{
	t_node	*current_node;
	int		maximum_number;
	int		current_node_position;
	int		position_of_maximum;

	if (!stack || !stack->top_node)
		return (0);
	maximum_number = stack->top_node->stored_number;
	current_node = stack->top_node->next_node;
	current_node_position = 2;
	position_of_maximum = 1;
	while (current_node)
	{
		if (current_node->stored_number > maximum_number)
		{
			maximum_number = current_node->stored_number;
			position_of_maximum = current_node_position;
		}
		current_node = current_node->next_node;
		current_node_position++;
	}
	return (position_of_maximum);
}

int	get_target_position(t_stack *stack, int target_number)
{
	t_node	*current_node;
	int		current_node_position;

	current_node = stack->top_node;
	current_node_position = 1;
	if (!stack || !current_node)
		return (0);
	while (current_node)
	{
		if (current_node->stored_number >= target_number)
			return (current_node_position);
		current_node_position++;
		current_node = current_node->next_node;
		if (current_node_position > stack->total_nodes)
			return (1);
	}
	return (1);
}
