/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sorter_utils2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoskim <hoskim@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 19:03:31 by hoskim            #+#    #+#             */
/*   Updated: 2025/02/06 21:06:11 by hoskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

#include "push_swap.h"

int get_min(t_stack *stack)
{
	t_node *current;
	int min;

	current = stack->top_node;
	min = current->number;
	while (current)
	{
		if (current->number < min)
			min = current->number;
		current = current->next;
	}
	return (min);
}

int get_max(t_stack *stack)
{
	t_node *current;
	int max;

	current = stack->top_node;
	max = current->number;
	while (current)
	{
		if (current->number > max)
			max = current->number;
		current = current->next;
	}
	return (max);
}
