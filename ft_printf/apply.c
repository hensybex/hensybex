/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medesmon <medesmon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 03:42:43 by medesmon          #+#    #+#             */
/*   Updated: 2019/09/20 03:44:32 by medesmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
#include <stdio.h>
#include <stdarg.h>

int	apply_width(int width, int num, int zero)
{
	int temp;
	int counter;

	counter = 0;
	temp = width - ft_count_num(num) - 1;
	while (temp-- > 0)
	{
		if (zero == 0)
			ft_putchar(' ');
		else
			ft_putchar('0');
		counter++;
	}
	return (counter);
}

int	apply_pres(int pres, int num)
{
	int temp;
	int counter;

	counter = 0;
	temp = pres - ft_count_num(num) - 1;
	while (temp-- > 0)
	{
		ft_putchar('0');
		counter++;
	}
	return (counter);
}

int	apply_pres_16(int pres, int num)
{
	int temp;
	int counter;

	counter = 0;
	temp = pres - ft_count_num_16(num) - 1;
	while (temp-- > 0)
	{
		ft_putchar('0');
		counter++;
	}
	return (counter);
}
