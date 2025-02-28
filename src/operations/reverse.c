/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoskim <hoskim@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 20:03:36 by hoskim            #+#    #+#             */
/*   Updated: 2025/02/28 17:57:41 by hoskim           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Performs a reverse rotation on a stack
 * 
 * This function moves the bottom element of the stack to the top position.
 * The operation is eqivalent to a counter-clockwise rotation of the stack.
 * If the stack has fewer than 2 elements, the function returns without
 * performing any operation.
 * 
 * @param stack Pointer to the stack to be rotated
 * 
 * @note This is the core implementation used by rra, rrb and rrr operations
 */
void	reverse_tail_to_head(t_stack *stack)
{
	t_node	*before_tail;
	t_node	*tail;

	if (stack->total_nodes < 2)
		return ;
	before_tail = stack->top_node;
	while (before_tail->next_node->next_node)
		before_tail = before_tail->next_node;
	tail = before_tail->next_node;
	before_tail->next_node = NULL;
	tail->next_node = stack->top_node;
	stack->top_node = tail;
}

/**
 * brief Performs reverse rotation on stack A
 * 
 * This function implements the 'rra' operation. It moves the bottom element
 * of stack A to the top position. If stack A has fewer than 2 elements,
 * no operation is performed.
 * 
 * @param stack_a Pointer to stack A
 * 
 * @note After successful execution, the operation 'rra' is printed to stdout
 * 
 * @see reverse_tail_to_head
 */
void	reverse_in_a(t_stack *stack_a)
{
	reverse_tail_to_head(stack_a);
	write(1, "rra\n", 4);
}

/**
 * @brief Performs reverse rotation on stack B
 * 
 * This function implements the 'rrb' operation. It moves the bottom element
 * of stack B to the top position. If stack B has fewer than 2 elements,
 * no operation is performed.abort
 * 
 * @param stack_b Pointer to stack B
 * 
 * @note After successful execution, the operation 'rrb' is printed to stdout
 * 
 * @see reverse_tail_to_head
 */
void	reverse_in_b(t_stack *stack_b)
{
	reverse_tail_to_head(stack_b);
	write(1, "rrb\n", 4);
}

/**
 * @brief Performs reverse rotation on both stack A and stack B simultaneously
 * 
 * This function implements the 'rrr' operation. It moves the bottom element
 * of both stack A and stack B to their respective top positions 
 * in a single operation.
 * The operation is performed only if both stacks have at least 2 elements.
 * 
 * @param stack_a Pointer to stack A
 * @param stack_b Pointer to stack B
 * 
 * @note After successful execution, the operation 'rrr' is printed to stdout
 * @note If either stack has fewer than 2 elements, no operation is performed
 *       on either stack
 * 
 * @see reverse_tail_to_head
 */
void	reverse_both(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->total_nodes >= 2 && stack_b->total_nodes >= 2)
	{
		reverse_tail_to_head(stack_a);
		reverse_tail_to_head(stack_b);
		write(1, "rrr\n", 4);
	}
}
