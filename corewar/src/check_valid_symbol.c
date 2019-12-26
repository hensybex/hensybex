/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_symbol.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medesmon <medesmon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 03:44:52 by medesmon          #+#    #+#             */
/*   Updated: 2019/12/20 03:53:18 by medesmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int	check_valid_string(char *str)
{
	int		i;
	int		j;
	char	*check_str;

	check_str = malloc(sizeof(char) * 38);
	check_str = ft_strdup(LABEL_CHARS);
	i = 0;
	while (i < 38)
	{
		if (symbol == check_str[i])
			return (1);
	}
	return (0);
}