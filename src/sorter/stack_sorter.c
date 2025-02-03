/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sorter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoskim <hoskim@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 19:25:30 by hoskim            #+#    #+#             */
/*   Updated: 2025/02/03 20:42:06 by hoskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	sort_three_help(t_stack *stack_a, int first, int second, int third)
{
	if (first > second && second > third)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (first > second && first > third)
		ra(stack_a);
	else if (first > second)
		sa(stack_a);
	else if (second > third && first > third)
		rra(stack_a);
	else if (second > third)
	{
		sa(stack_a);
		ra(stack_a);
	}
}

void	sort_three_nums(t_stack *stack_a)
{
	int	first_num;
	int	second_num;
	int	third_num;

	if (stack_a->num_of_nodes <= 1)
		return ;
	first_num = stack_a->top_node->number;
	second_num = stack_a->top_node->next->number;
	if (stack_a->num_of_nodes == 2)
	{
		if (first_num > second_num)
			sa(stack_a);
		return ;
	}
	third_num = stack_a->top_node->next->next->number;
	sort_three_help(stack_a, first_num, second_num, third_num);
}

void	sort_big(t_stack *stack_a, t_stack *stack_b)
{
	int	min_num;
	int	max_num;
	int	mid_num;
	int	best_num;
	int	target_position;

	while (stack_a->num_of_nodes > 3)
	{
		min_num = get_min_num(stack_a);
		max_num = get_max_num(stack_a);
		mid_num = (min_num + max_num) / 2;
		if (stack_a->top_node->number <= mid_num)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
	}
	sort_three_nums(stack_a);
	while (stack_b->num_of_nodes > 0)
	{
		best_num = find_best_number_from_b(stack_a, stack_b);
		target_position = find_insert_position(stack_a, best_num);
		while (stack_b)
	}
}

void	sort_stack(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->num_of_nodes <= 3)
		sort_three_nums(stack_a);
	else
		sort_big(stack_a, stack_b);
}
