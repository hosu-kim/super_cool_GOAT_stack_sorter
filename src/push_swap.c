/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoskim <hoskim@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 22:12:24 by hoskim            #+#    #+#             */
/*   Updated: 2025/01/28 18:52:33 by hoskim           ###   ########.fr       */
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
	check_duplicate(stack_a);
	if (!is_sorted(stack_a))
		sort_stack(stack_a, stack_b);
	clear_stack(stack_a);
	clear_stack(stack_b);
	return (0);
}
