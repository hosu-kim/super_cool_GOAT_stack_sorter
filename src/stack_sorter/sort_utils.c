/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoskim <hoskim@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 02:30:03 by hoskim            #+#    #+#             */
/*   Updated: 2025/02/17 17:15:37 by hoskim           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_range	get_stack_range(t_stack *stack)
{
	t_range	range;
	t_node	*current_node;

	if (!stack || !stack->head_node)
	{
		range.min = 0;
		range.max = 0;
		return (range);
	}
	range.min = stack->head_node->stored_number;
	range.max = stack->head_node->stored_number;
	current_node = stack->head_node->next_node;
	while (current_node)
	{
		if (current_node->stored_number < range.min)
			range.min = current_node->stored_number;
		if (current_node->stored_number > range.max)
			range.max = current_node->stored_number;
		current_node = current_node->next_node;
	}
	return (range);
}

int	find_min_position(t_stack *stack)
{
	t_node	*current_node;
	int		min;
	int		position;
	int		min_position;

	if (!stack || !stack->head_node)
		return (0);
	min = stack->head_node->stored_number;
	current_node = stack->head_node->next_node;
	position = 2;
	min_position = 1;
	while (current_node)
	{
		if (current_node->stored_number < min)
		{
			min = current_node->stored_number;
			min_position = position;
		}
		current_node = current_node->next_node;
		position++;
	}
	return (min_position);
}

int	find_max_position(t_stack *stack)
{
	t_node	*current_node;
	int		max;
	int		position;
	int		max_position;

	if (!stack || !stack->head_node)
		return (0);
	max = stack->head_node->stored_number;
	current_node = stack->head_node->next_node;
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

	current_node = stack->head_node;
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
