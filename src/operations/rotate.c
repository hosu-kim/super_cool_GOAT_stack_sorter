/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoskim <hoskim@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 03:33:34 by hoskim            #+#    #+#             */
/*   Updated: 2025/02/18 21:02:58 by hoskim           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rotate(t_stack *stack)
{
	t_node	*head;
	t_node	*tail;

	if (stack->total_nodes < 2)
		return ;
	head = stack->top_node;
	tail = head;
	while (tail->next_node)
		tail = tail ->next_node;
	stack->top_node = head->next_node;
	head->next_node = NULL;
	tail->next_node = head;
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
