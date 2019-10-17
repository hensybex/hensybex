//
//  linktable.c
//  lem-in
//
//  Created by Joshuah Stonehand on 26/04/2019.
//  Copyright © 2019 Joshuah Stonehand. All rights reserved.
//

#include "lemin.h"

void	zero_linktable(t_lemin *lemin)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (++i < lemin->room_amount)
	{
		j = -1;
		while (++j < lemin->room_amount)
			lemin->linktable[i][j] = 0;
	}
}

void	create_linktable(t_lemin *lemin)
{
	int	i;

	i = -1;
	if (!lemin->linktable)
		lemin->linktable = (int **)malloc(sizeof(int *) * lemin->room_amount);
	else
		return ;
	while (++i < lemin->room_amount)
		lemin->linktable[i] = (int *)malloc(sizeof(int) * lemin->room_amount);
	zero_linktable(lemin);
}

void	read_link(t_lemin *lemin, char **line)
{
	int	i;

	i = 0;
	lemin->slink = ft_strdup(ft_strchr(*line, '-') + 1);
	while ((*line)[i] && (*line)[i] != '-')
		i++;
	(*line)[i] = '\0';
	lemin->flink = ft_strdup(*line);
}

void	insert_link(t_lemin *lemin)
{
	int	y;
	int	x;
	
	y = -1;
	x = -1;
	while (lemin->room)
	{
		if (!ft_strcmp(lemin->room->name, lemin->flink))
		{
			y = lemin->room->num;
			break ;
		}
		lemin->room = lemin->room->next;
	}
	lemin->room = lemin->froom;
	while (lemin->room)
	{
		if (!ft_strcmp(lemin->room->name, lemin->slink))
		{
			x = lemin->room->num;
			break ;
		}
	lemin->room = lemin->room->next;
	}
	lemin->room = lemin->froom;
	lemin->linktable[y][x] = 1;
}

void	print_linktable(t_lemin *lemin)
{
	int	i;
	int	j;
	int	room_num;
	
	
	i = -1;
	j = -1;
	room_num = 1;
	while (++i < lemin->room_amount)
	{
		j = -1;
		printf("%d ", room_num++);
		while (++j < lemin->room_amount)
			printf("%d", lemin->linktable[i][j]);
		printf("\n");
	}
	printf("\n");
}

void	linktable(t_lemin *lemin, char **line)
{
	create_linktable(lemin);
	//printf("\n");
	read_link(lemin, line);
	insert_link(lemin);
	//print_linktable(lemin);
}
