/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoskim <hoskim@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 02:12:57 by hoskim            #+#    #+#             */
/*   Updated: 2025/02/09 02:29:32 by hoskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	get_optimal_moves(int position, int stack_size)
{
	if (position <= stack_size / 2)
		return (position - 1);
	return (stack_size - position + 1);
}

static void	push_numbers_to_b(t_stack *stack_a, t_stack *stack_b, t_range chunk)
{
	int	target;
	int	position;

	while (stack_a->num_of_nodes > 0)
	{
		target = stack_a->top_node->number;
		if (target >= chunk.min && target <= chunk.max)
		{
			pb(stack_a, stack_b);
			if (stack_b->top_node->number < (chunk.min + chunk.max) / 2)
				rb(stack_b);
		}
		else
		{
			position = get_target_position(stack_a, chunk.min);
			if (position <= stack_a->num_of_nodes / 2)
				ra(stack_a);
			else
				rra(stack_a);
		}
	}
}

static void	sort_back_to_a(t_stack *stack_a, t_stack *stack_b)
{
	int	max_position;
	int	moves;

	while (stack_b->num_of_nodes > 0)
	{
		max_position = find_max_position(stack_b);
		moves = get_optimal_moves(max_position, stack_b->num_of_nodes);
		while (moves > 0)
		{
			if (max_position <= stack_b->num_of_nodes / 2)
				rb(stack_b);
			else
				rrb(stack_b);
			moves--;
		}
		pa(stack_a, stack_b);
	}
}

void	sort_large(t_stack *stack_a, t_stack *stack_b)
{
	t_range	range;
	t_range	chunk;
	int		chunk_size;
	int		chunks;
	int		i;

	range = get_stack_range(stack_a);
	chunks = (stack_a->num_of_nodes <= 100)
}