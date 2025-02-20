/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoskim <hoskim@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 02:30:03 by hoskim            #+#    #+#             */
/*   Updated: 2025/02/20 17:47:27 by hoskim           ###   ########seoul.kr  */
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
	int		current_position;
	int		position_of_minumum;

	if (!stack || !stack->top_node)
		return (0);
	minimum_number = stack->top_node->stored_number;
	current_node = stack->top_node->next_node;
	current_position = 2;
	position_of_minumum = 1;
	while (current_node)
	{
		if (current_node->stored_number < minimum_number)
		{
			minimum_number = current_node->stored_number;
			position_of_minumum = current_position;
		}
		current_node = current_node->next_node;
		current_position++;
	}
	return (position_of_minumum);
}

int	find_max_position(t_stack *stack)
{
	t_node	*current_node;
	int		max;
	int		position;
	int		max_position;

	if (!stack || !stack->top_node)
		return (0);
	max = stack->top_node->stored_number;
	current_node = stack->top_node->next_node;
	position = 2;
	max_position = 1;
	while (current_node)
	{
		if (current_node->stored_number > max)
		{
			max = current_node->stored_number;
			max_position = position;
		}
		current_node = current_node->next_node;
		position++;
	}
	return (max_position);
}

int	get_target_position(t_stack *stack, int target_num)
{
	t_node	*current_node;
	int		position;

	current_node = stack->top_node;
	position = 1;
	if (!stack || !current_node)
		return (0);
	while (current_node)
	{
		if (current_node->stored_number >= target_num)
			return (position);
		position++;
		current_node = current_node->next_node;
		if (position > stack->total_nodes)
			return (1);
	}
	return (1);
}
