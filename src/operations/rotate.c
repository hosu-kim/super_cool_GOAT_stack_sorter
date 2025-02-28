/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoskim <hoskim@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 03:33:34 by hoskim            #+#    #+#             */
/*   Updated: 2025/02/28 19:31:18 by hoskim           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @breif Performs a rotation on a stack
 * 
 * This fucntion moves the top element of the stack to the bottom position.
 * If the stack has fewer than 2 elements, the functino does nothing.
 * 
 * @param stack The stack to rotate
 * @return void
 */
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

/**
 * @brief Rotates stack A and outputs the operation
 * 
 * Performs a rotation on stack A and writes the 'ra' operation
 * to the standard output.
 * 
 * @param stack_a The stack A to rotate
 * @return void
 */
void	rotate_in_a(t_stack *stack_a)
{
	rotate_head_to_tail(stack_a);
	write(1, "ra\n", 3);
}

/**
 * @breif Rotates stack B and outputs the operation
 * 
 * Performs a rotation on stack B and writs the 'rb' operation
 * to the standard ouput
 * 
 * @param stack_b The stack B to rotate
 * @return void
 */
void	rotate_in_b(t_stack *stack_b)
{
	rotate_head_to_tail(stack_b);
	write(1, "rb\n", 3);
}

/**
 * @breif Rotates both stacks A and B and outputs the operation
 * 
 * Performs a rotation on both stack A and stack B simultaneously,
 * and writes the 'rr' operation to the standard output.
 * 
 * @param stack_a The stack A to rotate
 * @param stack_b the stack B to rotate
 * @return void
 */
void	rotate_both(t_stack *stack_a, t_stack *stack_b)
{
	rotate_head_to_tail(stack_a);
	rotate_head_to_tail(stack_b);
	write(1, "rr\n", 3);
}
