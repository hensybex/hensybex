/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_10_to_8_long.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medesmon <medesmon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 18:32:53 by medesmon          #+#    #+#             */
/*   Updated: 2019/07/31 16:28:08 by medesmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int     ft_10_to_8_long(unsigned long long n)
{
    int     *num;
    unsigned long long    tsel;
    long    por;
    int     i;

    i = 0;
    num = 0;
    tsel = n;
    por = 1;
    while (tsel >= 1)
    {
        num = (tsel % 8 * por + num);
        por = por * 10;
        tsel = tsel / 8;
        i++;
    }
    num = tsel * por + num;
    return (i);
}