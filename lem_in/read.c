//
//  read_map.c
//  lem-in
//
//  Created by Joshuah Stonehand on 25/04/2019.
//  Copyright © 2019 Joshuah Stonehand. All rights reserved.
//

#include "lemin.h"

int		read_map(t_lemin *lemin)
{
	char	*line;
	int		fd;
	t_room	*room;
	
	fd = open("/Users/timofeykamenetskiy/Desktop/github/lemin_one_week/lemin_one_week/maps/test-3.map", O_RDWR);
	lemin->fd = fd;
	get_next_line(fd, &line);
	if((lemin->ant_amount = ft_atoi(line)) == 0) // check if valid
		return (0);
	while (get_next_line(fd, &line))
	{
		// skip comments in end		✓
		skip_comment(lemin, &line);
		// save rooms				✓
		rooms(lemin, &line);
		// save chains				✓
		linktable(lemin, &line);
		relink(lemin);
	}
    room = rmc(*lemin);
    int i = 0;
    /* while (i < lemin->room_amount)
    {
        printf("%s%d%s\n", "room[", i, "]");
        printf("%s ", room[i].name);
        printf("%d ", room[i].num);
        printf("%d ", room[i].is_vis);
        printf("%d ", room[i].min_len);
        printf("\n");
        i++;
    } */
	//printf("\n");
	return (1);
}
