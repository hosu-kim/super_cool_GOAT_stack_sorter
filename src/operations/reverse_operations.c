/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoskim <hoskim@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 20:03:36 by hoskim            #+#    #+#             */
/*   Updated: 2025/02/01 18:55:54 by hoskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rra(t_stack *stack_a)
{
	t_node	*prev;
	t_node	*last;

	if (stack_a->num_of_nodes < 2)
		return ;
	prev = stack_a->top_node;
	while (prev->next->next)
		prev = prev->next;
	last = prev->next;
	prev->next = NULL;
	last->next = stack_a->top_node;
	stack_a->top_node = last;
	write(1, "rra used.\n", 11);
}

void	rrb(t_stack *stack_b)
{
	t_node	*prev;
	t_node	*last;

	if (stack_b->num_of_nodes < 2)
		return ;
	prev = stack_b->top_node;
	while (prev->next->next)
		prev = prev->next;
	last = prev->next;
	prev->next = NULL;
	last->next = stack_b->top_node;
	stack_b->top_node = last;
	write(1, "rrb used.\n", 11);
}

void	rra_slient(t_stack *stack_a)
{
	t_node	*prev;
	t_node	*last;

	if (stack_a->num_of_nodes < 2)
		return ;
	prev = stack_a->top_node;
	while (prev->next->next)
		prev = prev->next;
	last = prev->next;
	prev->next = NULL;
	last->next = stack_a->top_node;
	stack_a->top_node = last;
}

void	rrb_slient(t_stack *stack_b)
{
	t_node	*prev;
	t_node	*last;

	if (stack_b->num_of_nodes < 2)
		return ;
	prev = stack_b->top_node;
	while (prev->next->next)
		prev = prev->next;
	last = prev->next;
	prev->next = NULL;
	last->next = stack_b->top_node;
	stack_b->top_node = last;
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->num_of_nodes >= 2 && stack_b->num_of_nodes >= 2)
	{
		rra_slient(stack_a);
		rrb_slient(stack_b);
		write(1, "rrr used.\n", 11);
	}
}
