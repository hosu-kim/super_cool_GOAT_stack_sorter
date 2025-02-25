/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoskim <hoskim@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 02:12:57 by hoskim            #+#    #+#             */
/*   Updated: 2025/02/25 18:55:34 by hoskim           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


static void	push_numbers_to_b(t_stack *stack_a, t_stack *stack_b, t_range chunk)
{
	int	target_num;
	int	position_of_target_num;

	while (stack_a->total_nodes > 0)
	{
		target_num = stack_a->top_node->stored_number;
		if (target_num >= chunk.min && target_num <= chunk.max)
		{
			push_head_from_a_to_b(stack_a, stack_b);
			if (stack_b->top_node->stored_number < (chunk.min + chunk.max) / 2)
				rotate_in_b(stack_b);
		}
		else
		{
			position_of_target_num = get_position_of_target_num(stack_a, chunk.min);
			if (position_of_target_num > stack_a->total_nodes)
				position_of_target_num = stack_a->total_nodes;
			move_node_to_top(stack_a, position_of_target_num);
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
		min_moves_to_top = find_min_moves_to_get_node(position_of_maximum, stack_b->total_nodes);
		while (min_moves_to_top > 0)
		{
			if (position_of_maximum <= stack_b->total_nodes / 2)
				rotate_in_b(stack_b);
			else
				reverse_tail_to_head_b(stack_b);
			min_moves_to_top--;
		}
		push_node_from_b_to_a(stack_a, stack_b);
	}
}

void	sort_large(t_stack *stack_a, t_stack *stack_b)
{
	t_range	range;
	t_range	chunk;
	int		chunk_size;
	int		chunks;
	int		i;

	range = find_number_range(stack_a);
	if (stack_a->total_nodes <= 100)
		chunks = 5;
	else
		chunks = 11;
	chunk_size = (range.max - range.min + 1) / chunks + 1;
	i = 0;
	while (i < chunks)
	{
		chunk.min = range.min + (i * chunk_size);
		chunk.max = chunk.min + chunk_size - 1;
		if (i == chunks - 1)
			chunk.max = range.max;
		push_numbers_to_b(stack_a, stack_b, chunk);
		i++;
	}
	sort_back_to_a(stack_a, stack_b);
}
