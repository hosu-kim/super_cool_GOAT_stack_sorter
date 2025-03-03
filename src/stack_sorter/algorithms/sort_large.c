/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoskim <hoskim@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 21:41:00 by hoskim            #+#    #+#             */
/*   Updated: 2025/03/03 21:47:20 by hoskim           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @breif Calculates chunk parameters for large sort
 * 
 * @param stack The stack to analyze
 * @param range Pointer to store the min-max range
 * @param num_chunks Pointer to store the number of chunks
 * @return int Size of each chunk
 */
static int	calculate_chunk_params(t_stack *stack, t_range *range, \ 
																int *num_chunks)
{
	int	total;
	int	chunk_size;

	total = stack->total_nodes;
	range->min = 1;
	range->max = total;
	*num_chunks = (total <= )
}
