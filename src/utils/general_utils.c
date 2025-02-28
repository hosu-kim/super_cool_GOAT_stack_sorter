/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoskim <hoskim@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 19:13:51 by hoskim            #+#    #+#             */
/*   Updated: 2025/02/28 21:02:06 by hoskim           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Prints an error message and exits the program
 * 
 * This function writes the string "Error\n" to standard error
 * (file descriptor 2) and terminates the program with exit code 1
 * to indicate an error condition.
 * 
 * @return void This function does not return as it calls exit(1)
 */
void	error_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

/**
 * @brief Converts a string to an integer with validation
 * 
 * This function parses a string and converts it to an integer value.
 * It handles leading whitespace, positive/negative signs, and digit characters.
 * 
 * @note Characters handled:
 *   - Whitespace: ' ', '\t', '\n', '\v', '\f', '\r' (ASCII 9-13)
 *   - Signs: '-' and '+'
 *   - Digits: '0' throgh '9'
 * 
 * The function performs the following validations:
 *   -# Checks for non-digit characters after processing signs and whitespace
 *   -# Ensures the result is within INT_MIN and INT_MAX range
 *   -# Exits with error if any validation fails
 * 
 * @param str The string to convert to an integer
 * @return int The converted integer value
 */
int	ft_atoi(const char *str)
{
	int		is_minus;
	long	result;

	is_minus = 1;
	result = 0;
	while (*str == ' ' || ('\t' <= *str && *str <= '\r'))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			is_minus = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		if (result * is_minus > INT_MAX || result * is_minus < INT_MIN)
			error_exit();
		str++;
	}
	if (*str != '\0')
		error_exit();
	return (is_minus * result);
}

/**
 * @brief Checks a stack for duplicate numbers
 * 
 * This function examines a stack to ensure that no number appears
 * more than once.
 * It uses a nested loop approach to compare each node with all subsequent node.
 * If any duplicate numbers are found, the function calls error_exit()
 * to terminate the program with an error message.
 * 
 * @param stack The stack to check for dupllicate values
 * @return void
 */
void	same_number_checker(t_stack *stack)
{
	t_node	*base_node;
	t_node	*compare_node;

	base_node = stack->top_node;
	while (base_node)
	{
		compare_node = base_node->next_node;
		while (compare_node)
		{
			if (base_node->stored_number == compare_node->stored_number)
				error_exit();
			compare_node = compare_node->next_node;
		}
		base_node = base_node->next_node;
	}
}

/**
 * @brief Determines if a stack is sorted in ascending order
 * 
 * This function checks if the elements in the stack are arranged
 * in ascending order from top to bottom.
 * It traverses the stack once, comparing each node with its next node.
 * If any node has a greater value than the next node, the function returns 0
 * to indicate that the stack is not sorted.
 * 
 * @param stack The stack to check for sorting
 * @return int 1 if the stack is sorted in ascending order, 0 otherwise
 */
int	is_sorted(t_stack *stack)
{
	t_node	*current_node;

	current_node = stack->top_node;
	while (current_node && current_node->next_node)
	{
		if (current_node->stored_number > \
			current_node->next_node->stored_number)
			return (0);
		current_node = current_node->next_node;
	}
	return (1);
}
