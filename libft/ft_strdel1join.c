/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel1join.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medesmon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 03:52:00 by medesmon          #+#    #+#             */
/*   Updated: 2019/02/06 07:57:40 by medesmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdel1join(char *s1, char *s2)
{
	char			*mem;
	int				len;

	if (!s1 || !s2)
		return (0);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	mem = (char *)malloc(sizeof(*mem) * len);
	if (mem == NULL)
		return (NULL);
	ft_strcpy(mem, s1);
	ft_strcat(mem, s2);
	ft_strdel(&s1);
	return (mem);
}
