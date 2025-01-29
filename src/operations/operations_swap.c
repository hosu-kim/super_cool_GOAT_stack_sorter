/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoskim <hoskim@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 19:59:20 by hoskim            #+#    #+#             */
/*   Updated: 2025/01/28 20:42:27 by hoskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sa(t_stack *stack_a)
{
	t_node	*first;
	t_node	*second;
	int		temp;

	if (stack_a->size < 2)
		return ;
	first = stack_a->top;
	second = first->next;
	temp = first->num;
	first->num = second->num;
	second->num = temp;
	write(1, "sa\n", 3);
}

void	sb(t_stack *stack_b)
{
	t_node	*first;
	t_node	*second;
	int		temp;

	if (stack_b->size < 2)
		return ;
	first = stack_b->top;
	second = first->next;
	temp = first->num;
	write(1, "sb\n", 3);
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	sa(stack_a);
	sb(stack_b);
	write(1, "ss\n", 3);
}
