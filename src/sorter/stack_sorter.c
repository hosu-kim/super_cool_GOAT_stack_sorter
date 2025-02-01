/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sorter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoskim <hoskim@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 19:25:30 by hoskim            #+#    #+#             */
/*   Updated: 2025/02/01 18:55:54 by hoskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_three_helper(t_stack *stack_a, int first, int second, int third)
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
	sort_three_helper(stack_a, first_num, second_num, third_num);
}

void	sort_stack(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->num_of_nodes <= 3)
		sort_three_nums(stack_a);
	else
		sort_big(stack_a, stack_b);
}
