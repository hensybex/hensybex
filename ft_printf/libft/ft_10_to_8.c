/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_10_to_8.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medesmon <medesmon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 07:53:21 by medesmon          #+#    #+#             */
/*   Updated: 2019/08/27 20:57:08 by medesmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int     ft_10_to_8(long n)
{
    int             *num;
    unsigned int    tsel;
    long            por;
    int             i;

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
