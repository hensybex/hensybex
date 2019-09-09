/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_BIG.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medesmon <medesmon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 17:51:14 by medesmon          #+#    #+#             */
/*   Updated: 2019/08/10 21:43:09 by medesmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_BIG(unsigned long long n)
{
	if (n < 10)
		ft_putchar('0' + n);
	else
	{
		ft_putnbr_BIG(n / 10);
		ft_putchar('0' + n % 10);
	}
}