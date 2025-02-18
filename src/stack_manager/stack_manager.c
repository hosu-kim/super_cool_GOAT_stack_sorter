/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoskim <hoskim@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 23:21:49 by hoskim            #+#    #+#             */
/*   Updated: 2025/02/18 21:02:58 by hoskim           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * @brief Initializes a structure(stack) with its members.
 * @note size of t_stack: 12 bytes {pointer(8 bytes in x64) and int}
 */
t_stack	*create_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		error_exit();
	stack->top_node = NULL;
	stack->total_nodes = 0;
	return (stack);
}

/**
 * @brief adds a new node into the stack
 * 		  and allocates the provided number to stored_number.
 */
void	insert_number_into_stack(t_stack *stack, int new_number)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		error_exit();
	new_node->stored_number = new_number;
	new_node->next_node = stack->top_node;
	stack->top_node = new_node;
	stack->total_nodes++;
}

int	extract_head_number(t_stack *stack)
{
	t_node	*temp;
	int		number;

	if (stack->total_nodes == 0)
		error_exit();
	temp = stack->top_node;
	number = temp->stored_number;
	stack->top_node = temp->next_node;
	free(temp);
	stack->total_nodes--;
	return (number);
}

void	print_stack_a(t_stack *stack_a)
{
	t_node	*current_node;

	write(1, "\nThe provided numbers are sorted in ascending order: ", 52);
	current_node = stack_a->top_node;
	while (current_node)
	{
		ft_putnbr(current_node->stored_number);
		if (current_node->next_node)
			write(1, " ", 1);
		current_node = current_node->next_node;
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
void	free_stacks(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*current;
	t_node	*next;

	if (!stack_a || !stack_b)
		return ;
	current = stack_a->top_node;
	while (current)
	{
		next = current->next_node;
		free(current);
		current = next;
	}
	current = stack_b->top_node;
	while (current)
	{
		next = current->next_node;
		free(current);
		current = next;
	}
	free(stack_a);
	free(stack_b);
}
