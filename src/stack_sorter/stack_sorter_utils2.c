/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sorter_utils2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoskim <hoskim@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 19:03:31 by hoskim            #+#    #+#             */
/*   Updated: 2025/02/04 19:07:16 by hoskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	get_min(t_stack *stack)
{
	t_node	*current_node;
	int		min_num;

	current_node = stack->top_node;
	min_num = current_node->number;
	while (current_node)
	{
		if (current_node->number < min_num)
			min_num = current_node->number;
		current_node = current_node->next;
	}
	return (min_num);
}

int	get_max(t_stack *stack)
{
	t_node	*current_node;
	int		max_num;

	current_node = stack->top_node;
	max_num = current_node->number;
	while (current_node)
	{
		if (current_node->number > max_num)
			max_num = current_node->number;
		current_node = current_node->next;
	}
	return (max_num);
}