/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoskim <hoskim@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 23:21:49 by hoskim            #+#    #+#             */
/*   Updated: 2025/01/28 19:25:24 by hoskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		erorr_exit();
	stack->top = NULL;
	stack->size = 0;
	return (stack);
}

void	push(t_stack *stack, int num)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		erorr_exit();
	new->num = num;
	new->next = stack->top;
	stack->top = new;
	stack->size++;
}

void	pop(void)
{
	return ;
}

void	clear_stack(void)
{
	return ;
}
