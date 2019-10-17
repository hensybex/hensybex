//
//  lemin.h
//  lem-in
//
//  Created by Joshuah Stonehand on 25/04/2019.
//  Copyright © 2019 Joshuah Stonehand. All rights reserved.
//

#ifndef lemin_h
# define lemin_h

# include "libft/libft.h"

typedef struct		s_room
{
	char			*name;
	int				num;
	struct s_room 	*next;
	int				min_len;
	int				is_vis;
    char			*prev;
	int				exist;
	int				table_num;
}					t_room;

typedef struct		s_sol
{
	char			*solution;
	struct s_sol	*next;
}					t_sol;


typedef struct		s_lemin
{
	int 			fd;
	int				ant_amount;
	int				room_amount;
	int				**linktable;
	char			*flink;
	char			*slink;
	t_room			*start_room;
	t_room			*end_room;
	t_room			*froom;
	t_room			*room;
}					t_lemin;

void	struct_init(t_lemin *lemin);
int		skip_comment(t_lemin *lemin, char **line);
void	gnl(t_lemin *lemin, char **line);

int		read_map(t_lemin *lemin);

void	rooms(t_lemin *lemin, char **line);

void	linktable(t_lemin *lemin, char **line);

void	print_final(t_lemin *lemin);

void	relink(t_lemin *lemin);

char	*dijkstra(t_room *rooms, int **linktable, int len);

int		**copy_linktable(int **linktable, t_room *rooms, int len);

void	print_table(int **linktable, int len, t_room *rooms);

t_room	init(t_room *rooms, int **linktable);

t_room	*rmc(t_lemin lemin);

char	*suurballe(int **linktable, t_room *rooms, int len, char *solution1);

void	break_link(int	numi, int numj, int **linktable);

char	**work_sols(char** solutions, int len);

# endif /* lemin_h */
