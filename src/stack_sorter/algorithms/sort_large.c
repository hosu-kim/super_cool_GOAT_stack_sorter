/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoskim <hoskim@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 02:12:57 by hoskim            #+#    #+#             */
/*   Updated: 2025/02/28 17:51:35 by hoskim           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	move_chunk_with_pivot_to_b(t_stack *a, t_stack *b, t_range chunk)
{
	int	current_number;
	int	position_of_num_in_chunk;
	int	performed_rotations;

	performed_rotations = 0;
	while (a->total_nodes > 0 && performed_rotations < a->total_nodes)
	{
		current_number = a->top_node->stored_number;
		if (current_number >= chunk.min && current_number <= chunk.max)
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
			performed_rotations++;
		}
	}
}

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
		move_chunk_with_pivot_to_b(stack_a, stack_b, chunk);
		i++;
	}
	sort_back_to_a(stack_a, stack_b);
}
