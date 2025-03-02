/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoskim <hoskim@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 23:21:49 by hoskim            #+#    #+#             */
/*   Updated: 2025/03/02 15:38:20 by hoskim           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Initializes a structure(stack) with its members.
 * @note size of t_stack: 12 bytes {pointer(8 bytes in x64) an int}
 * 
 * Creates a new stack structure, allocates memory for it, initializes
 * its members to default values, and returns a pointer to it.
 * Exits with an error if memory allocation fails.
 * 
 * @return t_stack* Pointer to the newly created stack
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
 * @breif adds a new node into the stack
 *        and allocates the provided number to stored_number.
 * 
 * Creates a new node with the given number, places it at the top of the stack,
 * and updates the stack's total node count. Exits with an error if memory
 * allocation fails.
 * 
 * @param stack The stack to which the new node will be added
 * @param new_number The integer value to be stored in the new node
 * @return void
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

/**
 * @brief Removes the top node from the stack and returns its value
 * 
 * This function removes the top node from the stack, decrements the stack's
 * total node count, frees the memory allocated for the removed node,
 * and returns the iteger value that was stored in it.
 * Exits with an error if the stack is empty.
 * 
 * @param stack The stack form which to remove the top node
 * @return int The value stored in the removed top node
 */
int	extract_top_node_and_remove(t_stack *stack)
{
	t_node	*temp_top_node;
	int		temp_top_node_number;

	temp_top_node = stack->top_node;
	temp_top_node_number = temp_top_node->stored_number;
	stack->top_node = temp_top_node->next_node;
	free(temp_top_node);
	stack->total_nodes--;
	return (temp_top_node_number);
}

/**
 * @brief Safely clears and frees memory for two stacks
 * 
 * @note This function performs the following steps:
 * -# Checks for NULL pointers
 * -# Frees all nodes in each stack
 * -# Frees the stack structures themselves
 * 
 * interates through all nodes in both stacks, freeing each node,
 * and then frees the stack structures themselves. If either stack
 * pointer is NULL, the function returns without attempting to free.
 * 
 * @param stack_a The first stack to be freed
 * @param stack_b The second stack to be freed
 * @return void
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
