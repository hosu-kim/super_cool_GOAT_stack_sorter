/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoskim <hoskim@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 19:59:20 by hoskim            #+#    #+#             */
/*   Updated: 2025/02/28 19:41:55 by hoskim           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Swaps the first and second elements of a stack
 * 
 * This function swaps the values of the first and second nodes of the stack.
 * For example, if stack has elements [1, 2, 3, 4], after swap it becomes
 * [2, 1, 3, 4].
 * If the stack has fewer than 2 elements, the function deos nothing.
 * 
 * @param stack The stack whose elements will be swapped
 * @return void
 */
void	swap_head_and_second_node(t_stack *stack)
{
	t_node	*head;
	t_node	*second_node;
	int		temp_head;

	if (stack->total_nodes < 2)
		return ;
	head = stack->top_node;
	second_node = head->next_node;
	temp_head = head->stored_number;
	head->stored_number = second_node->stored_number;
	second_node->stored_number = temp_head;
}

/**
 * @brief Swaps elements in stack A and outputs the operation
 * 
 * Performs a sawp operation on stack A and Writes the 'sa' operation
 * to the standard output.
 * 
 * @param stack_a the stack A to perform the swap on
 * @return void
 */
void	swap_in_a(t_stack *stack_a)
{
	swap_head_and_second_node(stack_a);
	write(1, "sa\n", 3);
}

/**
 * @brief Swaps elements in stack B and outputs the operation
 * 
 * Performs a swap operation on stack B and writes the 'sb' operation
 * to the standard output.
 * 
 * @param stack_b The stack B to perform the swap on
 * @return void
 */
void	swap_in_b(t_stack *stack_b)
{
	swap_head_and_second_node(stack_b);
	write(1, "sb\n", 3);
}

/**
 * @brief Swaps elements in both stacks A and B and outputs the operation
 * 
 * Performs a swap operation on both stack A and stack B simultaneously,
 * and writes the 'ss' operation to the standard output.
 * 
 * @param stack_a The stack A to perform the swap on
 * @param stack_b The stack B to perform the swap on
 * @return void
 */
void	swap_both(t_stack *stack_a, t_stack *stack_b)
{
	swap_head_and_second_node(stack_a);
	swap_head_and_second_node(stack_b);
	write(1, "ss\n", 3);
}
