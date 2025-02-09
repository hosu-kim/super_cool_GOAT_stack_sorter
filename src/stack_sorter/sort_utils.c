/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoskim <hoskim@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 02:30:03 by hoskim            #+#    #+#             */
/*   Updated: 2025/02/09 21:42:03 by hoskim           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_range	get_stack_range(t_stack *stack)
{
	t_range	range;
	t_node	*current_node;

	if (!stack || !stack->top_node)
	{
		range.min = 0;
		range.max = 0;
		return (range);
	}
	range.min = stack->top_node->number;
	range.max = stack->top_node->number;
	current_node = stack->top_node->next;
	while (current_node)
	{
		if (current_node->number < range.min)
			range.min = current_node->number;
		if (current_node->number > range.max)
			range.max = current_node->number;
		current_node = current_node->next;
	}
	return (range);
}

int	find_min_position(t_stack *stack)
{
	t_node	*current_node;
	int		min;
	int		position;
	int		min_position;

	if (!stack || !stack->top_node)
		return (0);
	min = stack->top_node->number;
	current_node = stack->top_node->next;
	position = 2;
	min_position = 1;
	while (current_node)
	{
		if (current_node->number < min)
		{
			min = current_node->number;
			min_position = position;
		}
		current_node = current_node->next;
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

	if (!stack || !stack->top_node)
		return (0);
	max = stack->top_node->number;
	current_node = stack->top_node->next;
	position = 2;
	max_position = 1;
	while (current_node)
	{
		if (current_node->number > max)
		{
			max = current_node->number;
			max_position = position;
		}
		current_node = current_node->next;
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
		if (current_node->number >= target_num)
			return (position);
		position++;
		current_node = current_node->next;
		if (position > stack->num_of_nodes)
			return (1);
	}
	return (1);
}
