/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sorter_utils2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoskim <hoskim@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 19:03:31 by hoskim            #+#    #+#             */
/*   Updated: 2025/02/07 22:23:39 by hoskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * @brief Retrieves the minimum value in the given stack.
 * 
 * @return int The minimum value in the stack.
 */
int	get_min(t_stack *stack)
{
	t_node	*current_node;
	int		min;

	current_node = stack->top_node;
	min = current_node->number;
	while (current_node)
	{
		if (current_node->number < min)
			min = current_node->number;
		current_node = current_node->next;
	}
	return (min);
}

/**
 * @brief Retrieves the maximum value in the given stack.
 * 
 * @return int The maximum value in the stack.
 */
int	get_max(t_stack *stack)
{
	t_node	*current_node;
	int		max;

	current_node = stack->top_node;
	max = current_node->number;
	while (current_node)
	{
		if (current_node->number > max)
			max = current_node->number;
		current_node = current_node->next;
	}
	return (max);
}
