/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoskim <hoskim@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 00:54:50 by hoskim            #+#    #+#             */
/*   Updated: 2025/02/08 20:42:54 by hoskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	find_min_value(t_stack *stack, int size)
{
	int		min;
	int		i;
	t_node	*current_node;

	min = INT_MAX;
	current_node = stack->top_node;
	i = 0;
	while (i < size)
	{
		if (current_node->number < min)
			min = current_node->number;
		current_node = current_node->next;
		i++;
	}
	return (min);
}

void	sort_four(t_stack *stack_a, t_stack *stack_b)
{
	int	min;

	min = find_min_value(stack_a, 4);
	while (stack_a->top_node->number != min)
		ra(stack_a);
	pb(stack_a, stack_b);
	sort_three(stack_a);
	pa(stack_a, stack_b);
}

void	sort_five(t_stack *stack_a, t_stack *stack_b)
{
	int	min;

	min = find_min_value(stack_a, 5);
	while (stack_a->top_node->number != min)
		ra(stack_a);
	pb(stack_a, stack_b);
	sort_four(stack_a, stack_b);
	pa(stack_a, stack_b);
}

void	sort_small_stack(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->num_of_nodes == 2)
		sort_two(stack_a);
	else if (stack_a->num_of_nodes == 3)
		sort_three(stack_a);
	else if (stack_a->num_of_nodes == 4)
		sort_four(stack_a, stack_a);
	else if (stack_a->num_of_nodes == 5)
		sort_five(stack_a, stack_b);
}
