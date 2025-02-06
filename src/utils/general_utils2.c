/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoskim <hoskim@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 19:24:36 by hoskim            #+#    #+#             */
/*   Updated: 2025/02/06 21:06:53 by hoskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

#include "push_swap.h"

void same_number_checker(t_stack *stack)
{
	t_node *outer;
	t_node *inner;

	outer = stack->top_node;
	while (outer)
	{
		inner = outer->next;
		while (inner)
		{
			if (outer->number == inner->number)
				error_exit();
			inner = inner->next;
		}
		outer = outer->next;
	}
}

int is_sorted(t_stack *stack)
{
	t_node *current;

	current = stack->top_node;
	while (current && current->next)
	{
		if (current->number > current->next->number)
			return (0);
		current = current->next;
	}
	return (1);
}