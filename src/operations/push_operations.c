/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoskim <hoskim@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 20:42:41 by hoskim            #+#    #+#             */
/*   Updated: 2025/02/10 01:48:14 by hoskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// push 1st element of stack A to 1st place of stack B
void	pa(t_stack *stack_a, t_stack *stack_b)
{
	int	number;

	if (stack_b->num_of_nodes == 0)
		return ;
	number = pop(stack_b);
	push_into_stack(stack_a, number);
	write(1, "pa used.\n", 9);
}

// push 1st element of stack B to 1st place of stack A
void	pb(t_stack *stack_a, t_stack *stack_b)
{
	int	number;

	if (stack_a->num_of_nodes == 0)
		return ;
	number = pop(stack_a);
	push_into_stack(stack_b, number);
	write(1, "pb used.\n", 9);
}
