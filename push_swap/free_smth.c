/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_smth.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medesmon <medesmon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 17:20:28 by medesmon          #+#    #+#             */
/*   Updated: 2019/10/17 18:35:49 by medesmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		free_ret(char **line)
{
	int	i;

	i = 0;
	while (line[i] != NULL)
		free(line[i++]);
	free(line);
	return (0);
}

int		free_itoa(char **line, char *new, char **origin)
{
	int	i;

	i = 1;
	new = ft_itoa(ft_atoi(origin[i]));
	if (ft_strcmp(new, origin[i]) != 0)
	{
		i = 0;
		while (line[i] != NULL)
			free(line[i++]);
		free(line);
		free(new);
		return (0);
	}
	free(new);
	return (1);
}

int		free_ret_1(char **line)
{
	int	i;

	i = 0;
	while (line[i] != NULL)
		free(line[i++]);
	free(line);
	return (1);
}

int		free_new(char **origin, int i)
{
	char	*new;

	new = ft_itoa(ft_atoi(origin[i]));
	if (ft_strcmp(new, origin[i]) != 0)
	{
		free(new);
		return (0);
	}
	free(new);
	return (1);
}
