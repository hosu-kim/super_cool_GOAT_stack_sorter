/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoskim <hoskim@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 19:59:20 by hoskim            #+#    #+#             */
/*   Updated: 2025/02/25 18:55:18 by hoskim           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Swap 1st and 2nd elements of a stack
// ex.) 1 2 3 4 => 2 1 3 4
void	swap_head_and_second_node(t_stack *stack)
{
	t_node	*head;
	t_node	*second_node;
	int		temp_head;

	if (stack->total_nodes < 2)
		return ;
	head = stack->top_node;
	second_node = head->next_node;
	temp_head = head->stored_number;
	head->stored_number = second_node->stored_number;
	second_node->stored_number = temp_head;
}

void	swap_in_a(t_stack *stack_a)
{
	swap_head_and_second_node(stack_a);
	write(1, "sa\n", 3);
}

void	swap_in_b(t_stack *stack_b)
{
	swap_head_and_second_node(stack_b);
	write(1, "sb\n", 3);
}

// Swap 1st and 2nd elements of both stacks
void	swap_both(t_stack *stack_a, t_stack *stack_b)
{
	swap_head_and_second_node(stack_a);
	swap_head_and_second_node(stack_b);
	write(1, "ss\n", 3);
}
