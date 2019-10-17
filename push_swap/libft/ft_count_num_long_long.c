/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_num_long_long.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medesmon <medesmon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 04:32:21 by medesmon          #+#    #+#             */
/*   Updated: 2019/10/17 16:28:42 by medesmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_num_long_long(int n)
{
	int	i;
	int	neg;

	i = 0;
	neg = n;
	while (neg > 0)
	{
		neg /= 10;
		i++;
	}
	return (i);
}
