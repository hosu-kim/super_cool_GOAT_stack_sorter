/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operatioins.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoskim <hoskim@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 20:48:19 by hoskim            #+#    #+#             */
/*   Updated: 2025/01/31 22:38:02 by hoskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ra(t_stack *stack_a)
{
	t_node	*first;
	t_node	*last;

	if (stack_a->num_of_nodes < 2)
		return ;
	first = stack_a->first_node;
	last = first;
	while (last->next)
		last = last->next;
	stack_a->first_node = first->next;
	first->next = NULL;
	last->next = first;
	write(1, "ra\n", 3);
}

void	rb(t_stack *stack_b)
{
	t_node	*first;
	t_node	*last;

	if (stack_b->num_of_nodes < 2)
		return ;
	first = stack_b->first_node;
	last = first;
	while (last->next)
		last = last ->next;
	stack_b->first_node = first->next;
	first->next = NULL;
	last->next = first;
	write(1, "rb\n", 3);
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	ra(stack_a);
	rb(stack_b);
	wrtie(1, "rr\n", 3);
}
