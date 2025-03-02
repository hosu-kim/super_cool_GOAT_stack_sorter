/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoskim <hoskim@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 00:30:06 by hoskim            #+#    #+#             */
/*   Updated: 2025/03/02 15:32:27 by hoskim           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Main function of push_swap program
 * 
 * This program sorts integers using two stacks (A and B)
 * and a limited set of operations as defined by the 42 project requirements.
 * The program takes integers as command line arguments and outputs the
 * sequence of operations needed to sort them in ascending order.
 * 
 * @param argc Number of command line arguments
 * @param argv Array of command line argument strings
 * 
 * @return int Returns 0 on successful execution
 * 
 * @note Algorithm steps:
 * -# Initialize stacks A and B
 * -# Parse command line arguments and insert numbers into stack A 
 *    in reverse order
 * -# check for duplicate numbers and handle errors
 * -# If the stack is not already sorted, apply sorting algorithm
 * -# Clean up allocated memory before program termination
 * 
 * @warning All input numbers must be valid integers within the range of INT_MIN
 *          to INT_MAX
 * @warning No duplicate numbers are allowed in the input
 */
int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		i;

	if (argc < 2)
		return (0);
	stack_a = create_stack();
	stack_b = create_stack();
	i = argc - 1;
	while (i > 0)
	{
		insert_number_into_stack(stack_a, ft_atoi(argv[i], stack_a, stack_b));
		i--;
	}
	if (same_number_checker(stack_a) == 0)
		cleanup_and_error_exit(stack_a, stack_b);
	if (!is_sorted(stack_a))
		sort_stacks(stack_a, stack_b);
	free_stacks(stack_a, stack_b);
	return (0);
}

/**
 * @brief Function execution flow
 * 
 * The main algorithm progresses through the following function calls:
 * -# create_stack() - Allocates and initializes stack structures
 *    (stack_manager.c)
 * -# insert_number_into_stack() - Adds numbers to the stack (stack_manager.c)
 * -# ft_atoi() - Converts string arguments to integers (general_utils.c)
 * -# same_number_checker() - Validates there are no duplicates (general_utils.c)
 * -# is_sorted() - Checks if the stack is already in sorted order
 *    (general_utils.c)
 * -# sort_stacks() - Core sorting algorithm (sort_manager.c)
 * -# free_stacks() - Deallocates memory for both stacks (stack_manager.c)
 */
