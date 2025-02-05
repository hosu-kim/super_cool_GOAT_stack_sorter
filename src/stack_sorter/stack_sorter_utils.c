/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sorter_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoskim <hoskim@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 18:44:33 by hoskim            #+#    #+#             */
/*   Updated: 2025/02/05 15:26:23 by hoskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	get_position(t_stack *stack, int num)
{
	int		position;
	t_node	*current_node;

	position = 0;
	current_node = stack->top_node;
	while (current_node && current_node->number != num)
	{
		position++;
		current_node = current_node->next;
	}
	return (position);
}

int	find_best_number_from_b(t_stack *stack_a, t_stack *stack_b)
{
	int		best_num;
	int		min_operations;
	int		operations;
	t_node	*current_node;

	best_num = stack_b->top_node->number;
	min_operations = INT_MAX;
	current_node = stack_b->top_node;
	while (current_node)
	{
		operations = calculate_operations(stack_a, stack_b, \
						current_node->number);
		if (operations < min_operations)
		{
			min_operations = operations;
			best_num = current_node->number;
		}
		current_node = current_node->next;
	}
	return (best_num);
}

int	find_insert_position(t_stack *stack_a, int num)
{
	int		position;
	t_node	*current_node;
	int		min_num;
	int		max_num;

	if (!stack_a->top_node)
		return (0);
	min_num = get_min(stack_a);
	max_num = get_max(stack_a);
	if (num < min_num)
		return (get_position(stack_a, min_num));
	if (num > max_num)
		return ((get_position(stack_a, max_num) + 1) % stack_a->num_of_nodes);
	position = 0;
	current_node = stack_a->top_node;
	while (current_node && current_node->next)
	{
		if (num > current_node->number && num < current_node->next->number)
			return (position + 1);
		position++;
		current_node = current_node->next;
	}
	return (0);
}

int	calculate_operations(t_stack *stack_a, t_stack *stack_b, int num)
{
	int	position_in_b;
	int	target_position_in_a;
	int	operations;

	position_in_b = get_position(stack_b, num);
	target_position_in_a = find_insert_position(stack_a, num);
	operations = 0;
	if (position_in_b <= stack_b->num_of_nodes / 2)
		operations += position_in_b;
	else
		operations += stack_b->num_of_nodes - position_in_b;
	if (target_position_in_a <= stack_a->num_of_nodes / 2)
		operations += target_position_in_a;
	else
		operations += stack_a->num_of_nodes - target_position_in_a;
	return (operations + 1);
}
