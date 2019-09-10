/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medesmon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 07:06:57 by medesmon          #+#    #+#             */
/*   Updated: 2019/01/19 15:28:53 by medesmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char			*ptr1;
	char			*ptr2;
	unsigned int	i;

	ptr1 = (char*)dst;
	ptr2 = (char*)src;
	if (dst == src)
		return (dst);
	i = 0;
	if (ptr1 > ptr2)
		while (i < n)
		{
			ptr1[n - i - 1] = ptr2[n - i - 1];
			i++;
		}
	else
	{
		i = 0;
		while (i < n)
		{
			ptr1[i] = ptr2[i];
			i++;
		}
	}
	return (dst);
}
