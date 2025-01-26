/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoskim <hoskim@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 23:37:53 by hoskim            #+#    #+#             */
/*   Updated: 2025/01/26 23:46:56 by hoskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*stack_a;

	if (argc < 2)
	{
		printf("Usage: ./push_swap [number1] [number2] ... [numberN]\n");
		return (1);
	}

	stack_a = init_stack(argc, argv);
	if (!stack_a)
	{
		printf("Stakc initialization failed\n");
		return (1);
	}
	printf("Initial stack a:\n");
	printf_stack(stack_a);

	return (0);
}
