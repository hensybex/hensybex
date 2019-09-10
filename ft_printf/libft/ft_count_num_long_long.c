/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_num_long_long.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medesmon <medesmon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 18:05:23 by medesmon          #+#    #+#             */
/*   Updated: 2019/09/04 12:06:51 by medesmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_num_long_long(unsigned long long n)
{
	long			    i;
	unsigned long long	neg;

	i = 0;
		neg = n;
	while (neg > 0)
	{
		neg /= 10;
		i++;
	}
	return (i);
}