/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoskim <hoskim@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 19:13:51 by hoskim            #+#    #+#             */
/*   Updated: 2025/02/04 21:42:25 by hoskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	error_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

/// @brief converts a number in a string to integer.
/// @note Ascii: 9: '\t', 10: '\n', 11: '\v' 12: '\f', 13: '\r
int	ft_atoi(const char *str)
{
	int		sign;
	long	result;

	sign = 1;
	result = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		if (result * sign > 2147483647 || result * sign < -2147483648)
			error_exit();
		str++;
	}
	if (*str != '\0')
		error_exit();
	return (sign * result);
}

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	long	num;

	num = n;
	if (num < 0)
	{
		ft_putchar('-');
		num = -num;
	}
	if (num >= 10)
	{
		ft_putnbr(num / 10);
		ft_putnbr(num % 10);
	}
	else
		ft_putchar(num + '0');
}
