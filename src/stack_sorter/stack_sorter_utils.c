/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sorter_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoskim <hoskim@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 18:44:33 by hoskim            #+#    #+#             */
/*   Updated: 2025/02/06 21:05:57 by hoskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

#include "push_swap.h"

int get_position(t_stack *stack, int num)
{
	t_node *current;
	int position;

	current = stack->top_node;
	position = 0;
	while (current)
	{
		if (current->number == num)
			return (position);
		current = current->next;
		position++;
	}
	return (-1);
}

int find_best_number_from_b(t_stack *stack_a, t_stack *stack_b)
{
	t_node *current;
	int best_num;
	int min_ops;
	int ops;

	current = stack_b->top_node;
	best_num = current->number;
	min_ops = calculate_operations(stack_a, stack_b, best_num);
	while (current)
	{
		ops = calculate_operations(stack_a, stack_b, current->number);
		if (ops < min_ops)
		{
			min_ops = ops;
			best_num = current->number;
		}
		current = current->next;
	}
	return (best_num);
}

int find_insert_position(t_stack *stack_a, int num)
{
	t_node *current;
	int position;

	current = stack_a->top_node;
	position = 0;
	while (current)
	{
		if (num < current->number)
			return (position);
		current = current->next;
		position++;
	}
	return (position);
}

int calculate_operations(t_stack *stack_a, t_stack *stack_b, int num)
{
	int pos_a;
	int pos_b;

	pos_a = find_insert_position(stack_a, num);
	pos_b = get_position(stack_b, num);
	return (pos_a + pos_b);
}