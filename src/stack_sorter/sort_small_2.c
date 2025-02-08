/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoskim <hoskim@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 00:54:50 by hoskim            #+#    #+#             */
/*   Updated: 2025/02/08 00:57:49 by hoskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	find_min_value(t_stack *stack, int size)
{
	int		min;
	int		i;
	t_node	*current_node;

	min = INT_MAX;
	current_node = stack->top_node;
	i = 0;
	while (i < size)
	{
		if (current_node->number < min)
			min = current_node->number;
		current_node = current_node->next;
		i++;
	}
	return (min);
}