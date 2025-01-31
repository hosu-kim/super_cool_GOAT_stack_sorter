/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sorter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoskim <hoskim@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 19:25:30 by hoskim            #+#    #+#             */
/*   Updated: 2025/01/31 19:57:54 by hoskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_three(t_stack *stack_a)
{
	int	first_num;
	int	second_num;
	int	third_num;

	if (stack_a->num_of_elements <= 1)
		return ;
	first_num = stack_a->top->number;
	second_num = stack_a->top->next->number;
	third_num = stack_a->top->next->next->number;

	if (stack_a->num_of_elements == 2)
	{
		if (first_num > second_num)
	}

void	sort_stack(t_stack *stack_a, t_stack *stack_b)
{

}
