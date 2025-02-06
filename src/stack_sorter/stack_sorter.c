/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sorter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoskim <hoskim@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 19:25:30 by hoskim            #+#    #+#             */
/*   Updated: 2025/02/06 21:04:57 by hoskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_three_nums(t_stack *stack_a)
{
	int	top;
	int	mid;
	int	bottom;

	top = stack_a->top_node->number;
	mid = stack_a->top_node->next->number;
	bottom = stack_a->top_node->next->next->number;
	if (top > mid && mid < bottom && top < bottom)
	{
		sa(stack_a);
	}
	else if (top > mid && mid > bottom)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (top < mid && mid > bottom && top > bottom)
		rra(stack_a);
}

void	sort_stack(t_stack *stack_a, t_stack *stack_b)
{
	int	size;

	size = stack_a->num_of_nodes;
	if (size <= 3)
		sort_three_nums(stack_a);
	else if (size <= 5)
		sort_small_stack(stack_a, stack_b);
	else
		sort_bit(stack_a, stack_b);
}