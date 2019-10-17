/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   returns.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medesmon <medesmon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 20:07:24 by medesmon          #+#    #+#             */
/*   Updated: 2019/10/12 14:14:25 by medesmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	end(void)
{
	ft_putendl("Error");
	return (0);
}

int	ko(t_stack stack1, t_stack stack2)
{
	int	i;

	i = stack1.size - 1;
	if (stack2.size != 0)
		return (0);
	if (i == 1)
	{
		if (stack1.data[1] > stack1.data[0])
			return (0);
		else
			return (1);
	}
	while (i > 1)
	{
		if (stack1.data[i] > stack1.data[i - 1])
			return (0);
		i--;
	}
	return (1);
}

int	print_ko(void)
{
	ft_putendl("KO");
	return (0);
}

int	free_end(char **line)
{
	ft_putendl("Error");
	free(line);
	return (0);
}
