/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medesmon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 16:59:45 by medesmon          #+#    #+#             */
/*   Updated: 2019/04/16 02:30:39 by medesmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dst, const char *ptr)
{
	int		i;
	int		j;
	char	*new;

	if (!(new = malloc(sizeof(char) * (ft_strlen(dst) + ft_strlen(ptr) + 1))))
		return (NULL);
	j = 0;
	i = 0;
	while (dst[i])
		i++;
	while (ptr[j])
	{
		dst[i] = ptr[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (ft_strcpy(new, dst));
}
