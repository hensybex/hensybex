/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex_upper.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medesmon <medesmon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 03:31:32 by medesmon          #+#    #+#             */
/*   Updated: 2019/06/25 20:54:37 by medesmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_putnbr_hex_upper(long n)
{
    n = (unsigned int)n;
    if (n < 16)
    {
        if (n < 10)
            ft_putchar('0' + n);
        else
            ft_putchar('A' + (n % 10));
    }
    else
        {
            ft_putnbr_hex_upper(n / 16);
            n = n % 16;
            if (n < 10)
                ft_putchar('0' + n);
            else
                ft_putchar('A' + (n % 10));
        }
}