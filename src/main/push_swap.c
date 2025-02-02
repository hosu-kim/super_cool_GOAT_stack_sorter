/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoskim <hoskim@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 22:12:24 by hoskim            #+#    #+#             */
/*   Updated: 2025/02/02 21:51:52 by hoskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		i;

	if (argc < 2)
		return (0);
	stack_a = init_stack();
	stack_b = init_stack();
	i = argc - 1;
	while (i > 0)
	{
		push(stack_a, ft_atoi(argv[i]));
		i--;
	}
	same_number_checker(stack_a);
	if (!is_sorted(stack_a))
		sort_stack(stack_a, stack_b);
	print_stack(stack_a);
	clear_stack(stack_a);
	clear_stack(stack_b);
	return (0);
}
/* @note 
	- function usage
		1. init_stack()			 | stack_manager.c
		2. push() 				 | stack_manager.c
		3. ft_atoi() 			 | utils.c
		4. same_number_checker() | utils.c
		5. is_sorted()			 | utils.c
		6. sort_stack()-CORE	 | stack_sorter.c
		7. clear_stack()		 | stackmanager.c
*/
