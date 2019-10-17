/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medesmon <medesmon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 04:37:17 by medesmon          #+#    #+#             */
/*   Updated: 2019/10/01 12:28:58 by medesmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dst, char *ptr)
{
	int		i;
	int		j;
	char	*new;

	if (!(new = malloc(sizeof(char) * (ft_strlen(dst) + ft_strlen(ptr) + 1))))
		return (NULL);
	j = 0;
	i = 0;
	while (dst[i])
	{
		new[i] = dst[i];
		i++;
	}
	while (ptr[j])
	{
		new[i + j] = ptr[j];
		j++;
	}
	new[i + j] = '\0';
	free(dst);
	return (new);
}
