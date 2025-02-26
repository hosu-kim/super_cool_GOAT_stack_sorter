/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoskim <hoskim@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 20:42:41 by hoskim            #+#    #+#             */
/*   Updated: 2025/02/26 16:17:41 by hoskim           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// push 1st element of stack A to 1st place of stack B
void	push_node_from_b_to_a(t_stack *stack_a, t_stack *stack_b)
{
	int	number;

	if (stack_b->total_nodes == 0)
		return ;
	number = extract_top_node_and_number(stack_b);
	insert_number_into_stack(stack_a, number);
	write(1, "pa\n", 3);
}

// push 1st elemeEEEEnt of stack B to 1st place of stack A
void	push_top_from_a_to_b(t_stack *stack_a, t_stack *stack_b)
{
	int	number;

	if (stack_a->total_nodes == 0)
		return ;
	number = extract_top_node_and_number(stack_a);
	insert_number_into_stack(stack_b, number);
	write(1, "pb\n", 3);
}
