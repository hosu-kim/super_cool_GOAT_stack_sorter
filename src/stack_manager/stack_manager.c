/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoskim <hoskim@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 23:21:49 by hoskim            #+#    #+#             */
/*   Updated: 2025/02/04 22:52:19 by hoskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
	{
		perror("Error: Memory allocation failed in init_stack().\n");
		exit(1);
	}
	stack->top_node = NULL;
	stack->num_of_nodes = 0;
	return (stack);
}

void	push(t_stack *stack, int number)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
	{
		perror("Error: Memory allocation failed in push().\n");
		exit(1);
	}
	new->number = number;
	new->next = stack->top_node;
	stack->top_node = new;
	stack->num_of_nodes++;
}

int	pop(t_stack *stack)
{
	t_node	*temp;
	int		number;

	if (stack->num_of_nodes == 0)
		error_exit();
	temp = stack->top_node;
	number = temp->number;
	stack->top_node = temp->next;
	free(temp);
	stack->num_of_nodes--;
	return (number);
}

void	print_stack(t_stack *stack_a)
{
	t_node	*current_node;

	write(1, "\nThe provided numbers are sorted in ascending order: \n", 52);
	current_node = stack_a->top_node;
	while (current_node)
	{
		ft_putnbr(current_node->number);
		if (current_node->next)
			write(1, " ", 1);
		current_node = current_node->next;
	}
	write(1, "\n\n", 2);
}

void	clear_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*next;

	current = stack->top_node;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(stack);
}
