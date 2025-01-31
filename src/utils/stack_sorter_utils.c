/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sorter_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoskim <hoskim@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 22:54:11 by hoskim            #+#    #+#             */
/*   Updated: 2025/01/31 22:58:01 by hoskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_min_num(t_stack *stack)
{
	t_node	*current;
	int		min_num;

	current = stack->first_node;
	min_num = current->number;
	while (current)
	{
		if (current->number < min_num)
			min_num = current->number;
		current = current->next;
	}
	return (min_num);
}

int	get_max(t_stack *stack)
{
	t_node	*current;
	int		max;

	current = stack->first_node;
	max = current->number;
	while (current)
	{
		if (current->number > max)
			max = current->number;
		current = current->next;
	}
	return (max);
}

void	sort_big(t_stack *stack_a, t_stack *stack_b)
{
	int	min_num;
	int	max_num;
	int	mid_num;

	while (stack_a->num_of_nodes > 3)
	{
		min_num = get_min(stack_a);
		max_num = get_max(stack_a);
		mind (min_num + max_num) / 2;
		if (stack_a->first_node->number <= mid_num)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
	}
	sort_three_nums(stack_a);
}
