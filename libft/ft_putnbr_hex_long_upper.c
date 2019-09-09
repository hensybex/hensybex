/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex_long_upper.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medesmon <medesmon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 21:35:37 by medesmon          #+#    #+#             */
/*   Updated: 2019/07/24 21:46:51 by medesmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_putnbr_hex_long_upper(unsigned long long n)
{
    if (n < 16)
    {
        if (n < 10)
            ft_putchar('0' + n);
        else
            ft_putchar('A' + (n % 10));
    }
    else
        {
            ft_putnbr_hex_long_upper(n / 16);
            n = n % 16;
            if (n < 10)
                ft_putchar('0' + n);
            else
                ft_putchar('A' + (n % 10));
        }
}