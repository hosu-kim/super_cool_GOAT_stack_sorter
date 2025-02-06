/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sorter_big.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoskim <hoskim@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 20:44:40 by hoskim            #+#    #+#             */
/*   Updated: 2025/02/06 21:05:32 by hoskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

#include "push_swap.h"

void sort_big(t_stack *stack_a, t_stack *stack_b)
{
	int pivot;
	int stack_size_total;

	stack_size_total = stack_a->num_of_nodes;
	while (stack_size_total > 3)
	{
		pivot = find_pivot(stack_a);
		partition_stack(stack_a, stack_b, pivot);
		stack_size_total = stack_a->num_of_nodes;
	}
	sort_three_nums(stack_a);
	while (stack_b->num_of_nodes > 0)
	{
		int best_num;
		
		best_num = find_best_number_from_b(stack_a, stack_b);
		move_number_to_a(stack_a, stack_b, best_num);
	}
	final_sort(stack_a);
}

void partition_stack(t_stack *stack_a, t_stack *stack_b, int pivot)
{
	int size;

	size = stack_a->num_of_nodes;
	while (size--)
	{
		if (stack_a->top_node->number <= pivot)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
	}
}