//
//  rooms.c
//  lem-in
//
//  Created by Joshuah Stonehand on 26/04/2019.
//  Copyright © 2019 Joshuah Stonehand. All rights reserved.
//

#include "lemin.h"

void	add_start_end(t_lemin *lemin, int num)
{
	while (lemin->room->num != 1)
		lemin->room = lemin->room->next;
	lemin->room->next = lemin->start_room;
	lemin->room = lemin->froom;
	lemin->room = (t_room *)malloc(sizeof(t_room));
	lemin->room->name = ft_strdup(lemin->end_room->name);
	lemin->room->num = num;
	lemin->room->next = lemin->froom;
	lemin->froom = lemin->room;
}

void	room_init(t_lemin *lemin, char **line, int num)
{
	int i;
	
	i = 0;
	while ((*line)[i] && (*line)[i] != ' ')
		i++;
	(*line)[i] = '\0';
	lemin->room = (t_room *)malloc(sizeof(t_room));
	lemin->room->name = ft_strdup(*line);
	lemin->room->num = num;
	lemin->room->next = lemin->froom;
	lemin->froom = lemin->room;
}


void	start_room(t_lemin *lemin, char **line)
{
	int i;
	
	i = 0;
	get_next_line(lemin->fd, line);
	while ((*line)[i] && (*line)[i] != ' ')
		i++;
	(*line)[i] = '\0';
	lemin->start_room = (t_room *)malloc(sizeof(t_room));
	lemin->start_room->name = ft_strdup(*line);
	lemin->start_room->num = 0;
	lemin->start_room->next = NULL;
}

void	end_room(t_lemin *lemin, char **line)
{
	int i;
	
	i = 0;
	get_next_line(lemin->fd, line);
	while ((*line)[i] && (*line)[i] != ' ')
		i++;
	(*line)[i] = '\0';
	lemin->end_room = (t_room *)malloc(sizeof(t_room));
	lemin->end_room->name = ft_strdup(*line);
	lemin->end_room->num = -1;
}

void	rooms(t_lemin *lemin, char **line)
{
	int i;
	int	num;

	i = 0;
	num = 1;
	if (ft_strchr(*line, '-'))
		return ;
	while ((*line)[i] && (*line)[i] != ' ')
		i++;
	(*line)[i] = '\0';

	if (!lemin->room)
	{
		lemin->room = (t_room *)malloc(sizeof(t_room));
		lemin->room->name = NULL;
		lemin->room->num = 0;
		lemin->room->next = NULL;
		lemin->froom = lemin->room;
	}
	while (!ft_strchr(*line, '-'))
	{
		if (skip_comment(lemin, line) == 1)
			start_room(lemin, line);
		else if (skip_comment(lemin, line) == 2)
			end_room(lemin, line);
		else
		{
			room_init(lemin, line, num);
			num++;
		}
		gnl(lemin, line);
	}
	add_start_end(lemin, num);
	lemin->room_amount = num + 1;
}
