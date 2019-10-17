/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   relink.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medesmon <medesmon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 19:02:00 by medesmon          #+#    #+#             */
/*   Updated: 2019/10/09 06:33:50 by medesmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	relink(t_lemin *lemin)
{
	int	i;
	int	j;
	int	room_num;

	i = 0;
	while (i < lemin->room_amount)
	{
		j = 0;
		while (j < lemin->room_amount)
		{
			if (lemin->linktable[i][j] == 1)
				lemin->linktable[j][i] = 1;
			j++;
		}
		i++;
	}
}

void	print_final(t_lemin *lemin)
{
	int	i;
	int	j;
	int	room_num;
	
	
	i = -2;
	j = -1;
	room_num = 1;
	while (++i < lemin->room_amount)
	{
		j = -1;
		if (i == 0)
			printf("%c", '\n');
		printf("%d ", room_num++ - 1);
		while (++j < lemin->room_amount)
		{
			if (i == -1)
				printf("%d", j + 1);
			else
				printf("%d", lemin->linktable[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}