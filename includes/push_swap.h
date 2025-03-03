/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoskim <hoskim@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 15:40:26 by hoskim            #+#    #+#             */
/*   Updated: 2025/03/03 21:35:58 by hoskim           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h> /* For memory allocation functions (malloc, free) */
# include <stdio.h> /* For input/output functions */
# include <unistd.h> /* For write function */
# include <limits.h> /* For INT_MAX constant to check integer overflow */

/*
** ========================= STRUCTURES =========================
*/

/**
 * @struct s_node
 * @brief Structure representing a single node in a stack
 * 
 * @param stored_number The integer value stored in this node
 * @param next_node Pointer to the next node in the stack
 */

typedef struct s_node
{
	int				stored_number;
	struct s_node	*next_node;
}	t_node;

/**
 * @struct t_stack
 * @brief Structure representing an entire stack
 * 
 * @param top_node Pointer to the top node of the stack
 * @param total_nodes The current number of nodes in the stack
 */
typedef struct s_stack
{
	t_node	*top_node;
	int		total_nodes;
}	t_stack;

/**
 * @struct t_range
 * @brief Structure to store the minimum and maximum values of a range
 * 
 * @param min The minimum value in the range
 * @param max The maximum value in the range
 */
typedef struct s_range
{
	int	min;
	int	max;
}	t_range;

/*
** ========================= STACK OPERATIONS =========================
 */

/**
 * @brief Basic Stack Management Functions
 */

/**
 * @brief Creates a new empty stack
 * @return Pointer to the newly created stack
 */
t_stack	*create_stack(void);

/**
 * @brief Inserts a new number at the top of the stack
 * @param stack The stack to insert into
 * @param number The integer value to insert
 */
void	insert_number_into_stack(t_stack *stack, int number);

/**
 * @brief Removes the top node from the stack and returns its value
 * @param stack The stack to extract from
 * @return The integer value stored in the removed top node
 */
int		extract_top_node_and_remove(t_stack *stack);

/**
 * brief Frees all memory allocated for both stacks
 * @param stack_a The first stack to free
 * @param stack_b The second stack to free
 */
void	free_stacks(t_stack *stack_a, t_stack *stack_b);

/**
 * @brief Stack Operation Commands
 */

/**
 * @brief Pushes the top node from stack B to stack A (pb)
 * @param stack_a Destination stack
 * @param stack_b Source stack
 */
void	push_top_a_to_b(t_stack *stack_a, t_stack *stack_b);

/**
 * @brief Pushes the top node from stack B to stack A (pa)
 * @param stack_a Destination stack
 * @param stack_b Source stack
 */
void	push_top_b_to_a(t_stack *stack_a, t_stack *stack_b);

/**
 * @brief Swaps the first two nodes of a stack
 * @param stack The stack to perform the swap on
 */
void	swap_head_and_second_node(t_stack *stack);

/**
 * @brief Swaps the first two nodes of stack A (sa)
 * @param stack_a The stack to swap
 */
void	swap_in_a(t_stack *stack_a);

/**
 * @brief Swaps the frist two nodes of stack B (sb)
 * @param stack_b The stack to swap
 */
void	swap_in_b(t_stack *stack_b);

/**
 * @brief Swaps the first two nodes of both stacks (ss)
 * @param stack_a The first stack to swap
 * @param stack_b The second stack to swap
 */
void	swap_both(t_stack *stack_a, t_stack *stack_b);

/**
 * @brief Moves the top node to the bottom of the stack
 * @param stack The stack to rotate
 */
void	rotate_head_to_tail(t_stack *stack);

/**
 * @brief Rotates stack A - moves top node to bottom (ra)
 * @param stack_a The stack to rotate
 */
void	rotate_in_a(t_stack *stack_a);

/**
 * @brief Rotates stack B - moves top node to bottom (rb)
 * @param stack_b The stack to rotate
 */
void	rotate_in_b(t_stack *stack_b);

/**
 * brief Rotates both stacks - moves top nodes to bottom (rr)
 * @param stack_a The first stack to rotate
 * @param stack_b The second stack to rotate
 */
void	rotate_both(t_stack *stack_a, t_stack *stack_b);

/**
 * @brief Reverse rotates a stack - moves bottom node to top
 * @param stack The stack to reverse rotate
 */
void	reverse_tail_to_head(t_stack *stack);

/**
 * Reverse rotates stack A - moves bottom node to top (rra)
 * @param stack_a The stack to reverse rotate
 */
void	reverse_in_a(t_stack *stack_a);

/**
 * @brief Reverse rotates stack B - moves bottom node to top (rrb)
 * @param stack_b The stack to reverse rotate
 */
void	reverse_in_b(t_stack *stack_b);

/**
 * @brief Reverse rotates both stacks - moves bottom nodes to top (rrr)
 * @param stack_a The first stack to reverse rotate
 * @param stack_b The second stack to reverse rotate
 */
void	reverse_both(t_stack *stack_a, t_stack *stack_b);

/*
** ========================= SORTING ALGORITHMS =========================
*/

/**
 * @brief Main sorting function that selects 
 * 		  appropriate algorithm based on stack size
 * @param stack_a The primary stack containing numbers to sort
 * @param stack_b The auxiliary stack used in sorting
 */
void	sort_stacks(t_stack *stack_a, t_stack *stack_b);

/**
 * brief Sorts a stack with exactly 2 numbers
 * @param stack_a The stack to sort
 */
void	sort_two_numbers(t_stack *stack_a);

/**
 * @brief Sorts a stack with exactly 3 numbers
 * @param stack_a The stack to sort
 */
void	sort_three_numbers(t_stack *stack_a);

/**
 * @brief Sorts a stack with 4 or 5 numbers
 * @param stack_a The primary stack to sort
 * @param stack_b The auxiliary stack
 */
void	sort_four_or_five(t_stack *stack_a, t_stack *stack_b);

/**
 * @brief Sorts a stack with more than 5 numbers using an optimized algorithm
 * @param stack_a The primary stack to sort
 * @param stack_b The auxiliary stack
 */
void	sort_large(t_stack *stack_a, t_stack *stack_b);

/*
** ========================= UTILITY FUNCTIONS =========================
*/

int		find_min_moves_to_top(int position_of_node, int stack_size);

/**
 * @brief Moves a node a given position to the top of the stack
 * @param stack_a The stack to modify
 * @param position_of_node The position of the node to move
 */

/**
 * @brief Normalizes stack values to sequential ranks (1 to n)
 * @param stack The stack to normalize
 */
void	move_target_node_to_top(t_stack *stack_a, int position_of_node);

void	normalize_stack_values(t_stack *stack);

/**
 * brief Finds the position of the node with the minimum value
 * @param stack The stack to search
 * @return The position of the minimum value node
 */
int		find_position_of_minimum(t_stack *stack);

/**
 * @brief Finds the position of the node with the maximum value
 * @param stack The stack to search
 * @return The position of the maximum value node
 */
int		find_position_of_maximum(t_stack *stack);

/**
 * @brief Finds the position of a node with a specific value
 * @param stack The stack to search
 * @param target_num The value to find
 * @return The position of the node with the target value
 */
int		find_position_of_num_in_chunk_range(t_stack *stack, t_range chunk);

/**
 * @brief Finds the minimum and maxmum values in a stack
 * @param stack The stack to analyze
 * @return A t_range structure containing the min and max values
 */
t_range	find_number_range(t_stack *stack);

/**
 * @breif Prints an error message and exits the program
 */
void	error_exit(void);

/**
 * @breif cleans up memory and executes error_exit()
 */
void	cleanup_and_error_exit(t_stack *stack_a, t_stack *stack_b);

/**
 * @brief Converts a string to an integer, with error handling
 * @param str The string to convert
 * @return The converted integer value
 */

int		ft_atoi(const char *str, t_stack *stack_a, t_stack *stack_b);

/**
 * @brief Checks if there are duplicate numbers in the stack
 * @param stack The stack to check
 */
int		same_number_checker(t_stack *stack);

/**
 * @brief Checks if the stack is already sorted
 * @param stack The stack to check
 * @return 1 if sorted, 0 otherwise
 */
int		is_sorted(t_stack *stack);

#endif
