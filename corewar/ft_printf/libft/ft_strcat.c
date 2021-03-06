/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smanhack <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 14:23:51 by smanhack          #+#    #+#             */
/*   Updated: 2019/04/05 14:23:54 by smanhack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strcat(char *s1, const char *s2)
{
	char *s1b;

	s1b = (char *)s1;
	while (*s1b != '\0')
		s1b++;
	while (*s2 != '\0')
	{
		*s1b = *s2;
		s1b++;
		s2++;
	}
	*s1b = '\0';
	return (s1);
}
