/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sorter_big.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoskim <hoskim@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 18:38:19 by hoskim            #+#    #+#             */
/*   Updated: 2025/02/05 22:48:50 by hoskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	move_to_b(t_stack *stack_a, t_stack *stack_b)
{
	int	min_num;
	int	max_num;
	int	mid_num;
	int	pushed_count;
	int	total_to_push;

	while (stack_a->num_of_nodes > 3)
	{
		min_num = get_min(stack_a);
		max_num = get_max(stack_a);
		mid_num = min_num + ((max_num - min_num) / 2);
		pushed_count = 0;
		total_to_push = stack_a->num_of_nodes - 3;
		while (pushed_count < total_to_push && stack_a->num_of_nodes > 3)
		{
			if (stack_a->top_node->number <= mid_num)
			{
				pb(stack_a, stack_b);
				pushed_count++;
			}
			else
				ra(stack_a);
		}
	}
}

static void	move_best_number(t_stack *stack_a, t_stack *stack_b, int best_num)
{
	int	current_position;
	
	while (stack_b->top_node->number != best_num)
	{
		if (get_position(stack_b, best_num) <= stack_b->num_of_nodes / 2)
			rb(stack_b);
		else
			rrb(stack_b);
	}
	while (find_)
}