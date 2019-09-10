/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medesmon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 23:05:48 by medesmon          #+#    #+#             */
/*   Updated: 2019/01/13 04:25:08 by medesmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dst, int c, size_t n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		((char*)dst)[i] = (unsigned char)c;
		i++;
	}
	return (dst);
}
