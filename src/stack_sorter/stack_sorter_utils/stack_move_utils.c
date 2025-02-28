/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_move_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoskim <hoskim@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 18:56:25 by hoskim            #+#    #+#             */
/*   Updated: 2025/02/25 18:56:25 by hoskim           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Calculates the minimum number of moves needed to bring a node
 *        to the top
 * 
 * This function determines whether it's more efficient to rotate forward (ra)
 * or backward (rra) to bring a node at a given position to the top of the stack.
 * If the node is in the first half of the stack, rotating forward is
 * more efficient.
 * If the node is in the second half of the stack, rotating backward is
 * more efficient.
 * 
 * @param position_of_node The position of the target node
 *        in the stack (1-indexed)
 * @param stack_size The total number of nodes in the stack
 * @return int The minimum number of moves required to bring the node to the top
 */
int	find_min_moves_to_top(int position_of_node, int stack_size)
{
	if (position_of_node <= stack_size / 2)
		return (position_of_node - 1);
	return (stack_size - position_of_node + 1);
}

/**
 * @brief Moves a node at the specified position to the top of stack A
 * 
 * this function applies either forward rotation (ra) or backward rotation (rra)
 * based on which method requires fewer operations to bring the target node to
 * the top of stack A. If the node is in the first half of the stack, forward
 * rotation is used. If the node is in the second half, backward rotation
 * is used.
 * 
 * @param stack_a The stack on which the rotation operations will be performed
 * @param position_of_node The position of the node to move 
 *        to the top (1-indexed)
 * @return void
 */
void	move_target_node_to_top(t_stack *stack_a, int position_of_node)
{
	if (position_of_node <= stack_a->total_nodes / 2)
		rotate_in_a(stack_a);
	else
		reverse_in_a(stack_a);
}
