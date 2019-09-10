/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_uns.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medesmon <medesmon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 21:16:26 by medesmon          #+#    #+#             */
/*   Updated: 2019/08/27 21:13:00 by medesmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_uns(unsigned int n)
{
	if (n < 10)
		ft_putchar('0' + n);
	else
	{
		ft_putnbr_uns(n / 10);
		ft_putchar('0' + n % 10);
	}
}