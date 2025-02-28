/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_position_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoskim <hoskim@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 02:30:03 by hoskim            #+#    #+#             */
/*   Updated: 2025/02/26 19:32:14 by hoskim           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
