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

int	find_min_moves_to_top(int position_of_node, int stack_size)
{
	if (position_of_node <= stack_size / 2)
		return (position_of_node - 1);
	return (stack_size - position_of_node + 1);
}

void	move_target_node_to_top(t_stack *stack_a, int position_of_node)
{
	if (position_of_node <= stack_a->total_nodes / 2)
		rotate_in_a(stack_a);
	else
		reverse_in_a(stack_a);
}
