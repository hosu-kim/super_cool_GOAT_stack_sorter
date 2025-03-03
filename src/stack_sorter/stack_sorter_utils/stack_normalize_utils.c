/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_normalize_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoskim <hoskim@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 21:12:55 by hoskim            #+#    #+#             */
/*   Updated: 2025/03/03 21:31:15 by hoskim           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Calculates the rank of a specific node in the stack
 * 
 * @param stack The stack containing all nodes
 * @param node The node whose rank to calculate
 * @return int The rank of the node (1 to n)
 */
static int	calculate_node_rank(t_stack *stack, t_node *node)
{
	t_node	*compare;
	int		rank;

	rank = 1;
	compare = stack->top_node;
	while (compare)
	{
		if (node->stored_number > compare->stored_number)
			rank++;
		compare = compare->next_node;
	}
	return (rank);
}

static void	update_stack_with_normalized(t_stack *stack, int *normalized)
{
	t_node	*current;
	int		i;

	current = stack->top_node;
	i = 0;
	while (current)
	{
		current->stored_number = normalized[i++];
		current = current->next_node;
	}
}

/**
 * @breif Normalizes all values in stack to their stored positons (1 to n)
 * 
 * This function replaces each value in the stack with its rank/position
 * in sorted order, which ensures the algorithm works with a continous
 * range of small integers regardless of the original values' magnitude.
 * 
 * @param stack The stack to normalize
 */
void	normalize_stack_values(t_stack *stack)
{
	t_node	*current;
	int		*normalized_values;
	int		i;

	normalized_values = (int *)malloc(sizeof(int) * stack->total_nodes);
	if (!normalized_values)
		return ;
	current = stack->top_node;
	i = 0;
	while (current)
	{
		normalized_values[i++] = calculate_node_rank(stack, current);
		current = current->next_node;
	}
	update_stack_with_normalized(stack, normalized_values);
	free(normalize_stack_values);
}
