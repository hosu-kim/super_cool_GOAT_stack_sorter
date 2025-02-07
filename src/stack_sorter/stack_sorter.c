/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sorter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoskim <hoskim@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 19:25:30 by hoskim            #+#    #+#             */
/*   Updated: 2025/02/07 22:33:57 by hoskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * @brief Sorts exactly three elements in stack_a
 * 
 * Uses a minimal set of operations to order the top three nodes of stack_a.
 */
void	sort_three_nums(t_stack *stack_a)
{
	int	top;
	int	middle;
	int	bottom;

	if (stack_a->num_of_nodes < 3)
		return ;
	top = stack_a->top_node->number;
	middle = stack_a->top_node->next->number;
	bottom = stack_a->top_node->next->next->number;
	if (top > middle && middle < bottom && top < bottom)
		sa(stack_a);
	else if (top > middle && middle > bottom)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (top < middle && middle > bottom && top > bottom)
		rra(stack_a);
}

/**
 * @brief Sorts a small stack (usually up to 5 elements.)
 * 
 * Pushes elements to stack_b until only three remain, sorts those three,
 * then pushes elements back from stack_b to stack_a.
 */
void	sort_small_stack(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_a->num_of_nodes > 3)
		pb(stack_a, stack_b);
	sort_three_nums(stack_a);
	while (stack_b->num_of_nodes > 0)
		pa(stack_a, stack_b);
}

/**
 * @brief Main dispatcher function to sort a stack.
 * 
 * Chooses between sort_three_nums, sort_small_stack, and sort_big
 * depending on the size of stack_a.
 */

void	sort_stack(t_stack *stack_a, t_stack *stack_b)
{
	int	size;

	size = stack_a->num_of_nodes;
	if (size <= 3)
		sort_three_nums(stack_a);
	else if (size <= 5)
		sort_small_stack(stack_a, stack_b);
	else
		sort_big(stack_a, stack_b);
}
