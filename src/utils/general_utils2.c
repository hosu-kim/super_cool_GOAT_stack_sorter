/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoskim <hoskim@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 19:24:36 by hoskim            #+#    #+#             */
/*   Updated: 2025/02/04 19:24:51 by hoskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	same_number_checker(t_stack *stack)
{
	t_node	*current;
	t_node	*check;

	current = stack->top_node;
	while (current)
	{
		check = current->next;
		while (check)
		{
			if (current->number == check->number)
				error_exit();
			check = check->next;
		}
		current = current->next;
	}
}

int	is_sorted(t_stack *stack)
{
	t_node	*current;

	if (stack->num_of_nodes <= 1)
		return (1);
	current = stack->top_node;
	while (current->next)
	{
		if (current->number > current->next->number)
		{
			return (0);
		}
		current = current->next;
	}
	return (1);
}
