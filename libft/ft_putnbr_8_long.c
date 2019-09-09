/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_8_long.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medesmon <medesmon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 16:15:37 by medesmon          #+#    #+#             */
/*   Updated: 2019/08/27 20:59:46 by medesmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_putnbr_8_long(unsigned long long int n)
{
    if (n < 8)
            ft_putchar('0' + n);
    else
    {
        ft_putnbr_8_long(n / 8);
        n = n % 8;
        ft_putchar('0' + n);
    }    
}