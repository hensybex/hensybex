/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   suurballe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timofeykamenetskiy <timofeykamenetskiy@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 02:54:51 by medesmon          #+#    #+#             */
/*   Updated: 2019/10/17 00:25:42 by timofeykame      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int	**change_linktable(int i, int j, int **linktable)
{
	linktable[i][j] = 2;
	return (0);
}

char	*suurballe(int **linktable, t_room *rooms, int len, char *solution1)
{
	int		i;
	int		j;
	char	*solution2;
	char	*new_sol1;
	char	*new_sol2;

	//change_linktable
	ft_putendl("Suurballe start");
	i = 0;
	while (ft_strcmp(rooms[0].prev, rooms[i].name) != 0)
		i++;
	linktable[0][i] = 0;
	while (ft_strcmp(rooms[i].prev, rooms[len - 1].name) != 0)
	{
		j = 0;
		while (ft_strcmp(rooms[i].prev, rooms[j].name) != 0)
			j++;
		linktable[i][j] = 0;
		i = j;
	}
	linktable[i][len - 1] = 0;

	//dijkstra second time
	solution2 = dijkstra(rooms, linktable, len);
	
	
	ft_putendl("Suurballe end");
	//solution2 = dijkstra(lemin)
	return (solution2);
}