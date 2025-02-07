/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sorter_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoskim <hoskim@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 18:44:33 by hoskim            #+#    #+#             */
/*   Updated: 2025/02/07 22:21:00 by hoskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/**
 * @brief Finds the position of a given number in a stack.
 * 
 * Iterates through the stack from top to bottom and returns the
 * zero-based index of the first node containing @p num.
 * 
 * @return int Index of the node containing @p num, or -1 if not found.
 */
int	get_position(t_stack *stack, int num)
{
	t_node	*current_node;
	int		position;

	current_node = stack->top_node;
	position = 0;
	while (current_node)
	{
		if (current_node->number == num)
			return (position);
		current_node = current_node->next;
		position++;
	}
	return (-1);
}

/**
 * @brief Determines the number from stack_b that can be inserted into
 *        stack_a with the least total operations.
 * @return int The value in stack_b with the minimal insertion cost.
 */
int	find_best_number_from_b(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*current;
	int		best_num;
	int		min_ops;
	int		ops;

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

/**
 * @brief Calculates where a given number should be inserted in stack_a.
 * 
 * compares the given @p num with the numbers in stack_a from top to bottom.
 * Returns the index at which @p num should be placed.
 * 
 * @param num The number to place in the stack.
 * @return int The index at which @p num should be inserted.
 */
int	find_insert_position(t_stack *stack_a, int num)
{
	t_node	*current;
	int		position;

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

/**
 * @brief Estimates the total operations needed to insert @p num from stack_b
 *        into the correct position in stack_a.
 * 
 * The calculation is a simple sum of positions in stack_a and stack_b.
 * 
 * @param num The number to be moved from stack_b into stack_a.
 * @return int Approximate number of operations.
 */
int	calculate_operations(t_stack *stack_a, t_stack *stack_b, int num)
{
	int	pos_a;
	int	pos_b;

	pos_a = find_insert_position(stack_a, num);
	pos_b = get_position(stack_b, num);
	return (pos_a + pos_b);
}
