/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_10_to_8.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medesmon <medesmon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 07:53:21 by medesmon          #+#    #+#             */
/*   Updated: 2019/07/20 18:33:28 by medesmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long    ft_10_to_8(long n)
{
    long    num;
    long    tsel;
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
