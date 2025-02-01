/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoskim <hoskim@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 23:21:49 by hoskim            #+#    #+#             */
/*   Updated: 2025/02/01 16:27:08 by hoskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		error_exit();
	stack->first_node = NULL;
	stack->num_of_nodes = 0;
	return (stack);
}

void	push(t_stack *stack, int number)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		error_exit();
	new->number = number;
	new->next = stack->first_node;
	stack->first_node = new;
	stack->num_of_nodes++;
}

int	pop(t_stack *stack)
{
	t_node	*temp;
	int		number;

	if (stack->num_of_nodes == 0)
		error_exit();
	temp = stack->first_node;
	number = temp->number;
	stack->first_node = temp->next;
	free(temp);
	stack->num_of_nodes--;
	return (number);
}

void	clear_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*next;

	current = stack->first_node;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(stack);
}
