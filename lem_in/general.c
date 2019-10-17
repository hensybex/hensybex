//
//  general.c
//  lem-in
//
//  Created by Joshuah Stonehand on 25/04/2019.
//  Copyright © 2019 Joshuah Stonehand. All rights reserved.
//

#include "lemin.h"

void	struct_init(t_lemin *lemin)
{
	
	lemin->fd = 0;
	lemin->ant_amount = 0;
	lemin->room_amount = 0;
	lemin->linktable = NULL;
	lemin->start_room = NULL;
	lemin->end_room = NULL;
	lemin->froom = NULL;
	lemin->room = NULL;
}

void	gnl(t_lemin *lemin, char **line)
{
	free(*line);
	get_next_line(lemin->fd, line);
}

int	skip_comment(t_lemin *lemin, char **line)
{
	if (!ft_strcmp("##start", *line))
		return (1);
	if (!ft_strcmp("##end", *line))
		return (2);
	if (*line[0] == '#')
	{
		get_next_line(lemin->fd, line);
		return (0);
	}
	return (0);
}

