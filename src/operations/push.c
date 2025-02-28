/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoskim <hoskim@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 20:42:41 by hoskim            #+#    #+#             */
/*   Updated: 2025/02/28 17:42:05 by hoskim           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Pushes the top element from A to stack B
 * 
 * This function implements the 'pb' operation. It removes the top element
 * from stack A and places it at the top of stack B. If stack A is empty,
 * the function returns without performing any operation.
 * 
 * @param stack_a Pointer to the source stack (stack A)
 * @param stack_b Pointer to the destination stack (stack B)
 * 
 * @note After successful execution, the operation 'pb' is printed to stdout
 * @note The function silently returns if stack A is empty
 * 
 * @see extract_top_node_and_remove
 * @see intert_number_into_stack
 */
void	push_top_a_to_b(t_stack *stack_a, t_stack *stack_b)
{
	int	number;

	if (stack_a->total_nodes == 0)
		return ;
	number = extract_top_node_and_remove(stack_a);
	insert_number_into_stack(stack_b, number);
	write(1, "pb\n", 3);
}

/**
 * @brief Pushes the top element from stack B to stack A
 * 
 * This function implements the 'pa' operation. It removes the top element
 * from stack B and places it at the top of stack A. If stack B is empty,
 * the function returns without performing any operation.
 * 
 * @param stack_a Pointer to the destination stack (stack A)
 * @param stack_b Pointer to the source stack (stack B)
 * 
 * @note After successful execution, the operation 'pa' is printed to stdout
 * @note The function silently returns if stack B is empty
 * 
 * @see extract_top_node_and_remove
 * @see insert_number_into_stack
 */
void	push_top_b_to_a(t_stack *stack_a, t_stack *stack_b)
{
	int	number;

	if (stack_b->total_nodes == 0)
		return ;
	number = extract_top_node_and_remove(stack_b);
	insert_number_into_stack(stack_a, number);
	write(1, "pa\n", 3);
}
