/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medesmon <medesmon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 14:32:46 by medesmon          #+#    #+#             */
/*   Updated: 2019/08/27 20:54:59 by medesmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(unsigned long long int n)
{
	char					*mem;
	unsigned int			len;
	unsigned long long int	neg;

	if (!(len = ft_count_num_long_long(n)))
		return (ft_strdup("0"));
	//if (n < 0)
	//	neg = -n;
	//else
		neg = n;
	if (!(mem = ft_strnew(len)))
		return (NULL);
	while (neg)
	{
		mem[len - 1] = neg % 10 + '0';
		neg /= 10;
		len--;
	}
	//if (n < 0)
	//	mem[0] = '-';
	return (mem);
}
