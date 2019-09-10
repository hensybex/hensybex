/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medesmon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 02:23:28 by medesmon          #+#    #+#             */
/*   Updated: 2019/01/20 19:47:21 by medesmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	isspace(int c)
{
	return ((9 <= c && c <= 13) || c == 32);
}

int			ft_atoi(const char *str)
{
	long	num;
	long	isneg;
	long	temp;

	isneg = 1;
	num = 0;
	while (isspace(*str))
		str++;
	if (*str == '-')
		isneg = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (ft_isdigit(*str))
	{
		temp = num;
		num = num * 10 + isneg * (*str++ - '0');
		if (temp > num && temp > 0)
			return (-1);
		if (temp < num && temp < 0)
			return (0);
	}
	return (num);
}
