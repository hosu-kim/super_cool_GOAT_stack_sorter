/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoskim <hoskim@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 03:33:34 by hoskim            #+#    #+#             */
/*   Updated: 2025/02/09 03:34:08 by hoskim           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rotate(t_stack *stack)
{
	t_node	*first_node;
	t_node	*last_node;

	if (stack->num_of_nodes < 2)
		return ;
	first_node = stack->top_node;
	last_node = first_node;
	while (last_node->next)
		last_node = last_node ->next;
	stack->top_node = first_node->next;
	first_node->next = NULL;
	last_node->next = first_node;
}

void	ra(t_stack *stack_a)
{
	rotate(stack_a);
	write(1, "ra used.\n", 10);
}

void	rb(t_stack *stack_b)
{
	rotate(stack_b);
	write(1, "rb used.\n", 10);
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	write(1, "rr used.\n", 10);
}
