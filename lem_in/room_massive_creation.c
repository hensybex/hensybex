//
//  room_massive_creation.c
//  lemin_one_week
//
//  Created by Joshuah Stonehand on 03/10/2019.
//  Copyright © 2019 Joshuah Stonehand. All rights reserved.
//

#include "lemin.h"

t_room	*rmc(t_lemin lemin)
{
	int len;
	int i;
	t_room *room;
	t_room *tmp;
	
	len = 0;
	tmp = lemin.room;
	while (tmp)
	{
		len++;
		tmp = tmp->next;
	}
	tmp = lemin.room;
	room = malloc(sizeof(t_room) * len);
	i = 0;
	while (i < len)
	{
		room[i].name = ft_strdup(tmp->name);
		room[i].num = tmp->num;
		room[i].is_vis = tmp->is_vis;
		room[i].min_len = tmp->min_len;
		tmp = tmp->next;
		room[i].exist = 1;
		i++;
	}
	return (room);
}
