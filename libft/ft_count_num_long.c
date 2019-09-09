/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_num_long.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medesmon <medesmon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 18:04:51 by medesmon          #+#    #+#             */
/*   Updated: 2019/09/04 12:06:55 by medesmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_num_long(long long n)
{
	long			i;
	long			neg;

	i = 0;
	if (n < 0)
	{
		neg = -n;
		i++;
	}
	else
		neg = n;
	while (neg > 0)
	{
		neg /= 10;
		i++;
	}
	return (i);
}