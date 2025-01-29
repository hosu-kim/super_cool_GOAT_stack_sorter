/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoskim <hoskim@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 20:42:41 by hoskim            #+#    #+#             */
/*   Updated: 2025/01/28 20:48:09 by hoskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	int	num;

	if (stack_b->size == 0)
		return ;
	num = pop(stack_b);
	push(stack_a, num);
	write(1, "pa\n", 3);
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	int	num;

	if (stack_a->size == 0)
		return ;
	num = pop(stack_a);
	push(stack_b, num);
	write(1, "pb\n", 3);
}
