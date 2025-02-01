/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoskim <hoskim@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 19:59:20 by hoskim            #+#    #+#             */
/*   Updated: 2025/02/01 18:56:14 by hoskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// Swap 1st and 2nd elements of a stack
// ex.) 1 2 3 4 => 2 1 3 4
void	swap(t_stack *stack)
{
	t_node	*first_node;
	t_node	*second_node;
	int		temp;

	if (stack->num_of_nodes < 2)
		return ;
	first_node = stack->top_node;
	second_node = first_node->next;
	temp = first_node->number;
	first_node->number = second_node->number;
	second_node->number = temp;
}

void	sa(t_stack *stack_a)
{
	swap(stack_a);
	write(1, "sa used.\n", 10);
}

void	sb(t_stack *stack_b)
{
	swap(stack_b);
	write(1, "sb used.\n", 10);
}

// Swap 1st and 2nd elements of both stacks
void	ss(t_stack *stack_a, t_stack *stack_b)
{
	swap(stack_a);
	swap(stack_b);
	write(1, "ss used.\n", 10);
}
