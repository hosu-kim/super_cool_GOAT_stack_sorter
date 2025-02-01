/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoskim <hoskim@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 19:59:20 by hoskim            #+#    #+#             */
/*   Updated: 2025/02/01 15:59:34 by hoskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// Swap 1st and 2nd elements of Stack A
// ex.) 1 2 3 4 => 2 1 3 4
void	sa(t_stack *stack_a)
{
	t_node	*first;
	t_node	*second;
	int		temp;

	if (stack_a->num_of_nodes < 2)
		return ;
	first = stack_a->first_node;
	second = first->next;
	temp = first->number;
	first->number = second->number;
	second->number = temp;
	write(1, "sa\n", 3);
}

// Swap 1st and 2nd elements of Stack B
void	sb(t_stack *stack_b)
{
	t_node	*first;
	t_node	*second;
	int		temp;

	if (stack_b->num_of_nodes < 2)
		return ;
	first = stack_b->first_node;
	second = first->next;
	temp = first->number;
	first->number = second->number;
	second->number = temp;
	write(1, "sb\n", 3);
}

// Swap 1st and 2nd elements of both stacks
void	ss(t_stack *stack_a, t_stack *stack_b)
{
	sa(stack_a);
	sb(stack_b);
	write(1, "ss\n", 3);
}
