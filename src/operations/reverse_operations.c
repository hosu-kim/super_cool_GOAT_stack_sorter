/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoskim <hoskim@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 20:03:36 by hoskim            #+#    #+#             */
/*   Updated: 2025/02/10 19:18:35 by hoskim           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	reverse(t_stack *stack)
{
	t_node	*prev;
	t_node	*last;

	if (stack->total_nodes < 2)
		return ;
	prev = stack->top_node;
	while (prev->next_node->next_node)
		prev = prev->next_node;
	last = prev->next_node;
	prev->next_node = NULL;
	last->next_node = stack->top_node;
	stack->top_node = last;
}

void	rra(t_stack *stack_a)
{
	reverse(stack_a);
	write(1, "rra used.\n", 11);
}

void	rrb(t_stack *stack_b)
{
	reverse(stack_b);
	write(1, "rrb used.\n", 11);
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->total_nodes >= 2 && stack_b->total_nodes >= 2)
	{
		reverse(stack_a);
		reverse(stack_b);
		write(1, "rrr used.\n", 11);
	}
}
