/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoskim <hoskim@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 03:33:34 by hoskim            #+#    #+#             */
/*   Updated: 2025/02/19 18:07:59 by hoskim           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rotate_head_to_tail(t_stack *stack)
{
	t_node	*head;
	t_node	*tail;

	if (stack->total_nodes < 2)
		return ;
	head = stack->top_node;
	tail = head;
	while (tail->next_node)
		tail = tail->next_node;
	stack->top_node = head->next_node;
	head->next_node = NULL;
	tail->next_node = head;
}

void	rotate_in_a(t_stack *stack_a)
{
	rotate_head_to_tail(stack_a);
	write(1, "ra\n", 3);
}

void	rotate_in_b(t_stack *stack_b)
{
	rotate_head_to_tail(stack_b);
	write(1, "rb\n", 3);
}

void	rotate_both(t_stack *stack_a, t_stack *stack_b)
{
	rotate_head_to_tail(stack_a);
	rotate_head_to_tail(stack_b);
	write(1, "rr\n", 3);
}
