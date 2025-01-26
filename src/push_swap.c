/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoskim <hoskim@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 22:12:24 by hoskim            #+#    #+#             */
/*   Updated: 2025/01/26 23:09:39 by hoskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

typedef struct	s_node
{
	int	value;
	struct s_node	*next;
}	t_node;

t_node	*init_stack(int argc, char **argv)
{
	t_node	*stack;
	t_node	*another_node;
	int		i;

	stack = NULL;
	i = 1;
	while (i < argc)
	{
		another_node = (t_node *)malloc(sizeof(t_node));
		if (!anoter_node)
			return (NULL);
		another_node->value = atoi(argv[i]);
		another_node->next = stack;
		stack = another_node;
		i++;
	}
	return (stack);
}

void	print_stack(t_node *stack)
{
	while (stack)
	{
		printf("%d\n", stack->value);
		stack = stack->next;
	}
}

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
		printf("Stack initialization fail.\n");
		return (1);
	}
	printf("Stack-A initialized.\n");
	print_stack(stack_a);
}
