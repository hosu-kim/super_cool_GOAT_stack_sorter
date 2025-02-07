/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoskim <hoskim@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 23:21:49 by hoskim            #+#    #+#             */
/*   Updated: 2025/02/07 02:52:20 by hoskim           ###   ########.fr       */
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

	write(1, "\nThe provided numbers are sorted in ascending order: ", 52);
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

/**
 * @brief Safely clears and frees memory for two stacks
 * 
 * @note This function performs the following steps:
 * -# Checks for NULL pointers
 * -# Frees all nodes in each stack
 * -# Frees the stack structures themselves
 */
void	clear_stacks(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*current;
	t_node	*next;

	if (!stack_a || !stack_b)
		return ;

	current = stack_a->top_node;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	current = stack_b->top_node;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(stack_a);
	free(stack_b);
}
