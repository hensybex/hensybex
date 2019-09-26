/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgilwood <bgilwood@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 03:43:45 by medesmon          #+#    #+#             */
/*   Updated: 2019/09/26 20:03:47 by bgilwood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	apply_width_long_long(int width, unsigned long long num, int zero)
{
	int temp;
	int counter;

	counter = 0;
	temp = width - ft_count_num_long_long(num) - 1;
	while (temp-- > 0)
	{
		if (zero == 0)
			ft_putchar(' ');
		else
			ft_putchar('0');
		counter++;
	}
	if (num == 0)
		counter = 1;
	return (counter);
}

int	apply_width_long(int width, long long num, int zero)
{
	int temp;
	int counter;

	counter = 0;
	temp = width - ft_count_num_long(num) - 1;
	while (temp-- > 0)
	{
		if (zero == 0)
			ft_putchar(' ');
		else
			ft_putchar('0');
		counter++;
	}
	if (num == 0)
		counter = 1;
	return (counter);
}

int	apply_width_16(int width, unsigned long long num, int zero)
{
	int temp;
	int counter;

	counter = 0;
	temp = width - ft_count_num_16(num) - 1;
	while (temp-- > 0)
	{
		if (zero == 0)
			ft_putchar(' ');
		else
			ft_putchar('0');
		counter++;
	}
	if (num == 0)
		counter = 1;
	return (counter);
}

int	apply_width_8(int width, unsigned long long num, int zero)
{
	int temp;
	int counter;

	counter = 0;
	temp = width - ft_count_num_8(num) - 1;
	while (temp-- > 0)
	{
		if (zero == 0)
			ft_putchar(' ');
		else
			ft_putchar('0');
		counter++;
	}
	if (num == 0)
		counter = 1;
	return (counter);
}
