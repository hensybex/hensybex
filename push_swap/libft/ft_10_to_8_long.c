/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_10_to_8_long.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medesmon <medesmon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 18:32:53 by medesmon          #+#    #+#             */
/*   Updated: 2019/07/20 18:33:15 by medesmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long    ft_10_to_8_long(unsigned long long n)
{
    long    num;
    unsigned long long    tsel;
    long    por;

    num = 0;
    tsel = n;
    por = 1;
    while (tsel > 1)
    {
        num = (tsel % 8 * por + num);
        por = por * 10;
        tsel = tsel / 8;
    }
    num = tsel * por + num;
    return (num);
}