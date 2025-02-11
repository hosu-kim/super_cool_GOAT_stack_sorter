/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoskim <hoskim@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 00:52:29 by hoskim            #+#    #+#             */
/*   Updated: 2025/02/11 17:45:20 by hoskim           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// ex. stack_a = {2, 1}
void	sort_two(t_stack *stack_a)
{
	int	first;
	int	second;

	first = stack_a->top_node->stored_number;
	second = stack_a->top_node->next_node->stored_number;
	if (first > second)
		sa(stack_a);
}

/* ex.
	case 1. stack_a = {2, 1, 3}
	case 2. stack_a = {3, 2, 1}
	case 3. stack_a = {1, 3, 2}
	case 4. stack_a = {2, 3, 1}
	case 5. stack_a = {1, 3, 2}
*/
void	sort_three(t_stack *stack_a)
{
	int	first;
	int	second;
	int	third;

	first = stack_a->top_node->stored_number;
	second = stack_a->top_node->next_node->stored_number;
	third = stack_a->top_node->next_node->next_node->stored_number;
	if (first > second && second < third && first < third)
		sa(stack_a);
	else if (first > second && second > third)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (first > second && second < third && first > third)
		ra(stack_a);
	else if (first < second && second > third && first < third)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (first < second && second > third && first > third)
		rra(stack_a);
}

void	sort_small(t_stack *stack_a, t_stack *stack_b)
{
	int	target_position;

	while (stack_a->total_nodes > 3)
	{
		target_position = find_min_position(stack_a);
		while (target_position != 1)
		{
			if (target_position <= stack_a->total_nodes / 2)
				ra(stack_a);
			else
				rra(stack_a);
			target_position = find_min_position(stack_a);
		}
		pb(stack_a, stack_b);
	}
	sort_three(stack_a);
	while (stack_b->total_nodes > 0)
		pa(stack_a, stack_b);
}
