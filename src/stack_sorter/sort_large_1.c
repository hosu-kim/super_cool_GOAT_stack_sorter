/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoskim <hoskim@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 20:43:34 by hoskim            #+#    #+#             */
/*   Updated: 2025/02/08 20:50:24 by hoskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	get_max_bits(t_stack *stack)
{
	t_node	*current_node;
	int		max_num;
	int		max_bits;

	current_node = stack->top_node;
	max_num = current_node->number;
	while (current_node)
	{
		if (current_node->number > max_num)
			max_num = current_node->number;
		current_node = current_node->next;
	}
	max_bits = 0;
	while ((max_num >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

static void	get_positions(t_stack *stack, int *normalized)
{
	t_node	*i;
	t_node	*j;
	int		position;

	i = stack->top_node;
	while (i)
	{
		position = 0;
		j = stack->top_node;
		while (j)
		{
			if (i->number > j->number)
				position++;
			j = j->next;
		}
		normalized[position] = i->number;
		i = i->next;
	}
}