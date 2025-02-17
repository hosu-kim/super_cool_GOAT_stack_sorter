/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sorter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoskim <hoskim@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 18:09:58 by hoskim            #+#    #+#             */
/*   Updated: 2025/02/11 18:18:05 by hoskim           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sort_stacks(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->total_nodes == 2)
		sort_two(stack_a);
	else if (stack_a->total_nodes == 3)
		sort_three(stack_a);
	else if (stack_a->total_nodes <= 5)
		sort_four_five(stack_a, stack_b);
	else
		sort_large(stack_a, stack_b);
}
