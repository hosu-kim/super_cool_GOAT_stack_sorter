/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoskim <hoskim@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 22:12:21 by hoskim            #+#    #+#             */
/*   Updated: 2025/01/28 20:04:43 by hoskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				num;
	struct s_node	*next;
}	t_node;

typedef struct s_node
{
	t_node	*top;
	int		size;
}	t_stack;

// operations.c
void	sa(t_stack *stack_a);
void	sb(t_stack *stack_b);
void	ss(t_stack *stack_a, t_stack *stack_b);
void	pa(t_stack *stack_a, t_stack *stack_b);
void	pb(t_stack *stack_a, t_stack *stack_b);
void	ra(t_stack *stack_a);
void	rb(t_stack *stack_b);
void	rr(t_stack *stack_a, t_stack *stack_b);
void	rra(t_stack *stack_a);
void	rrb(t_stack *stack_b);
void	rrr(t_stack *stack_a, t_stack *stack_b);

// stack.c
t_stack	*init_stack(void);
void	push(t_stack *stack, int num);
int		pop(t_stack *stack);
void	clear_stack(t_stack *stack);

// utils.c
void	error_exit(void);
int		ft_atoi(const char *str);
void	check_duplicate(t_stack *stack);
int		is_sorted(t_stack *stack);

// sort.c
void	sort_three(t_stack *stack_a);
void	sort_stack(t_stack *stack_a, t_stack *stack_b);

#endif
