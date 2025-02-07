/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sorter_big.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoskim <hoskim@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 19:53:53 by hoskim            #+#    #+#             */
/*   Updated: 2025/02/07 22:10:59 by hoskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/**
 * @brief contains functions to srt large stacks using partition logic.
 * -# Repeately determines a pivot from stack_a ad partition stack_a into
 *    stack_b until only 3 elements remain in stack_a.
 * -# Sorts the remaining 3 elements remain in stack_a.
 * -# Moves all elements from stack_b back to stack_a in an ordder that
 *    minimizes the total operations required.
 * -# Perform a final sort if necessary.
 */
void	sort_big(t_stack *stack_a, t_stack *stack_b)
{
	int	pivot;
	int	stack_size_total;
	int	best_num;

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
		best_num = find_best_number_from_b(stack_a, stack_b);
		move_number_to_a(stack_a, stack_a, best_num);
	}
	final_sort(stack_a);
}

/**
 * @briedf partition stack_a into stack_b using the pivot.
 * 
 * Values less than or equal to @p pivot are pushed to stack_b,
 * and larger values are rorated within stack_a.
 */
void	partition_stack(t_stack *stack_a, t_stack *stack_b, int pivot)
{
	int	size;

	size = stack_a->num_of_nodes;
	while (size--)
	{
		if (stack_a->top_node->number <= pivot)
			pb(stack_a, stack_a);
		else
			ra(stack_a);
	}
}
