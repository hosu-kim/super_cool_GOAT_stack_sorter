/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sorter_final.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoskim <hoskim@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 22:43:07 by hoskim            #+#    #+#             */
/*   Updated: 2025/02/07 22:43:42 by hoskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/**
 * @brief Ensures the final order of stack_a is sorted.
 *
 * This function performs any final adjustments to ensure stack_a is sorted.
 * 
 * @param stack_a Pointer to the primary stack.
 */
void	final_sort(t_stack *stack_a)
{
	int	min;
	int	pos;
	int	size;

	min = get_min(stack_a);
	pos = get_position(stack_a, min);
	size = stack_a->num_of_nodes;
	if (pos <= size / 2)
	{
		while (pos-- > 0)
			ra(stack_a);
	}
	else
	{
		pos = size - pos;
		while (pos-- > 0)
			rra(stack_a);
	}
}
