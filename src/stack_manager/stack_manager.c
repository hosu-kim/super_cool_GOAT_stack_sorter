/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoskim <hoskim@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 23:21:49 by hoskim            #+#    #+#             */
/*   Updated: 2025/02/25 18:55:23 by hoskim           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Initializes a structure(stack) with its members.
 * @note size of t_stack: 12 bytes {pointer(8 bytes in x64) and int}
 */
t_stack	*create_stack(void)
{
	t_stack	*new_stack;

	new_stack = (t_stack *)malloc(sizeof(t_stack));
	if (!new_stack)
		error_exit();
	new_stack->top_node = NULL;
	new_stack->total_nodes = 0;
	return (new_stack);
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

int	extract_top_node_and_number(t_stack *stack)
{
	t_node	*temp_top_node;
	int		temp_top_node_number;

	if (stack->total_nodes == 0)
		error_exit();
	temp_top_node = stack->top_node;
	temp_top_node_number = temp_top_node->stored_number;
	stack->top_node = temp_top_node->next_node;
	free(temp_top_node);
	stack->total_nodes--;
	return (temp_top_node_number);
}

// void	print_stack_a(t_stack *stack_a)
// {
// 	t_node	*current_node;
//
// 	write(1, "\nThe provided numbers are sorted in ascending order: ", 52);
// 	current_node = stack_a->top_node;
// 	while (current_node)
// 	{
// 		ft_putnbr(current_node->stored_number);
// 		if (current_node->next_node)
// 			write(1, " ", 1);
// 		current_node = current_node->next_node;
// 	}
// 	write(1, "\n\n", 2);
// }

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
	t_node	*current_node;
	t_node	*next_node;

	if (!stack_a || !stack_b)
		return ;
	current_node = stack_a->top_node;
	while (current_node)
	{
		next_node = current_node->next_node;
		free(current_node);
		current_node = next_node;
	}
	current_node = stack_b->top_node;
	while (current_node)
	{
		next_node = current_node->next_node;
		free(current_node);
		current_node = next_node;
	}
	free(stack_a);
	free(stack_b);
}
