/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medesmon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 16:41:40 by medesmon          #+#    #+#             */
/*   Updated: 2019/02/06 04:10:23 by medesmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		len;
	char	*new;

	len = ft_strlen(src);
	if (!(new = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	return (ft_strcpy(new, src));
}
