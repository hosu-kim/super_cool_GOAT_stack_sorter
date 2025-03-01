/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoskim <hoskim@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 02:12:57 by hoskim            #+#    #+#             */
/*   Updated: 2025/03/01 21:48:49 by hoskim           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Moves numbers within a specific range (chunk) from stack A to B
 * 
 * This function transfers elements from stack A to stack B that fall within
 * the specified chunk range. Additionally, it optimizes stack B by rotating
 * smaller elements within the chunk to the bottom, preparing for later sorting.
 * 
 * @param a The source stack A from which elements are transferred
 * @param b The destination stack B to which elements are transferred
 * @param chunk The range defining the minimum and maximum values to be moved
 * @return void
 */
static void	push_chunk_and_presort_b(t_stack *a, t_stack *b, t_range chunk)
{
	int	current_number;
	int	position_of_num_in_chunk;

	while (a->total_nodes > 0)
	{
		current_number = a->top_node->stored_number;
		if (chunk.min <= current_number && current_number <= chunk.max)
		{
			push_top_a_to_b(a, b);
			if (b->top_node->stored_number < (chunk.min + chunk.max) / 2)
				rotate_in_b(b);
		}
		else
		{
			position_of_num_in_chunk = \
								find_position_of_num_in_chunk_range(a, chunk);
			if (position_of_num_in_chunk == -1)
				break ;
			move_target_node_to_top(a, position_of_num_in_chunk);
		}
	}
}

/**
 * @brief Sorts elements from stack B back into stack A in order
 * 
 * this function transfers elements from stack B back to stack A in
 * descending order by repeatedly finding the maximum value in stack B,
 * moving it to the top position with minimal operations, and pushing
 * it to stack A.
 * 
 * @param stack_a The destination stack for the sorted elements
 * @param stack_b The source stack containing elements to be sorted
 * @return void
 */
static void	sort_back_to_a(t_stack *stack_a, t_stack *stack_b)
{
	int	position_of_maximum;
	int	min_moves_to_top;

	while (stack_b->total_nodes > 0)
	{
		position_of_maximum = find_position_of_maximum(stack_b);
		min_moves_to_top = \
			find_min_moves_to_top(position_of_maximum, stack_b->total_nodes);
		while (min_moves_to_top > 0)
		{
			if (position_of_maximum <= stack_b->total_nodes / 2)
				rotate_in_b(stack_b);
			else
				reverse_in_b(stack_b);
			min_moves_to_top--;
		}
		push_top_b_to_a(stack_a, stack_b);
	}
}

/**
 * @brief Main function for sorting large arrays using a chunk-bassed approach
 * 
 * This function implements a sorting algorithm optimized for large data sets:
 * -# Divides the number range into chunks
 * (5 chunks for <= 100 elements, 11 chunks for >100)
 * -# Transfers elements from stack A to stack B by chunks,
 *    partial pre-sorting
 * -# Sorts all elements back form stack B to stack A in the correct order
 * 
 * @param stack_a The main stack containing unsorted elements
 * @param stack_b The auxiliary stack used for sorting
 * @return void
 */
void	sort_large(t_stack *stack_a, t_stack *stack_b)
{
	t_range	range;
	t_range	chunk;
	int		how_many_nums_in_chunk;
	int		num_of_chunks;
	int		i;

	range = find_number_range(stack_a);
	if (stack_a->total_nodes <= 100)
		num_of_chunks = 5;
	else
		num_of_chunks = 11;
	how_many_nums_in_chunk = (range.max - range.min + 1) / num_of_chunks + 1;
	i = 0;
	while (i < num_of_chunks)
	{
		chunk.min = range.min + (i * how_many_nums_in_chunk);
		chunk.max = chunk.min + how_many_nums_in_chunk - 1;
		if (i == num_of_chunks - 1)
			chunk.max = range.max;
		push_chunk_and_presort_b(stack_a, stack_b, chunk);
		i++;
	}
	sort_back_to_a(stack_a, stack_b);
}
