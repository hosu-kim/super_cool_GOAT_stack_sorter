/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoskim <hoskim@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 20:03:36 by hoskim            #+#    #+#             */
/*   Updated: 2025/02/18 20:18:07 by hoskim           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	reverse(t_stack *stack)
{
	t_node	*before_tail;
	t_node	*tail;

	if (stack->total_nodes < 2)
		return ;
	before_tail = stack->head_node;
	while (before_tail->next_node->next_node)
		before_tail = before_tail->next_node;
	tail = before_tail->next_node;
	before_tail->next_node = NULL;
	tail->next_node = stack->head_node;
	stack->head_node = tail;
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
