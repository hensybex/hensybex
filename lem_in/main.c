//
//  main.c
//  lem-in
//
//  Created by Joshuah Stonehand on 25/04/2019.
//  Copyright © 2019 Joshuah Stonehand. All rights reserved.
//

#include "libft/libft.h"
#include "lemin.h"

void	break_half_link(int numi, int numj, int **linktable)
{
	linktable[numj][numi] = 0;
}

void	remake_linktable(int **linktable, t_room *rooms, int len)
{
	int	i;
	int	j;

	i = 0;
	while (rooms[i].prev)
	{
		j = 0;
		while (ft_strcmp(rooms[i].prev, rooms[j].name) != 0)
			j++;
		break_half_link(len - i - 1, len - j - 1, linktable);
		i = j;
	}
}

int main()
{
	t_lemin lemin;
	t_room	*rooms;
	char	**solutions;
	char	**final_solutions;
	int		**tmp_linktable;
	char	*solution1;
	char	*solution2;

	struct_init(&lemin);
	read_map(&lemin);
	//print_final(&lemin);
	int i = 0;
	int	j = 0;
	i = -1;
	solutions = (char **)malloc(sizeof(char *) * 10);
	while (++i < 10)
		solutions[i] = (char *)malloc(sizeof(char) * 10);
	i = -1;
	final_solutions = (char **)malloc(sizeof(char *) * 10);
	while (++i < 10)
		final_solutions[i] = (char *)malloc(sizeof(char) * 10);
	i = 0;
	rooms = rmc(lemin);
	/* solution1 = ft_strdup(dijkstra(rooms, lemin.linktable, lemin.room_amount));
	ft_putendl(solution1);
	tmp_linktable = (copy_linktable(lemin.linktable, rooms, lemin.room_amount));
	solution2 = ft_strdup(suurballe(tmp_linktable, rooms, lemin.room_amount, solution1));
	ft_putendl(solution2); */



	solution1 = ft_strdup("START");
	tmp_linktable = (copy_linktable(lemin.linktable, rooms, lemin.room_amount));
	while (ft_strcmp(solution1, "END") != 0)
	{
		solution1 = ft_strdup(dijkstra(rooms, tmp_linktable, lemin.room_amount));
		solutions[j] = ft_strdup(solution1);
		j++;
		if (ft_strcmp(solution1, "END") != 0)
			remake_linktable(tmp_linktable, rooms, lemin.room_amount);
	}
	int	sol_amount = j;
	final_solutions = work_sols(solutions, sol_amount);
	i = 0;
	while (ft_strcmp(final_solutions[i], "") != 0)
		i++;
	j = 0;
	while (ft_strcmp(solutions[j], "END") != 0)
	{
		final_solutions[i] = ft_strdup(solutions[j]);
		j++;
		i++;
	}
	i = 0;
	while (i < sol_amount - 1)
	{
		ft_putendl(final_solutions[i]);
		i++;
	}
	/* while (i < sol_amount - 1)
	{
		j = i - 1;
		while (j < sol_amount)
		{
			if (suurballe(sol[i], sol[j] == 0))
			{
				final_solutions[k] = 
			}
		}
	} */
	
	
	
	//если убрать строчку #pipes step из карты long_Chloe, ввод работает. Иначе ввод считывает первую связь линктаблицы за комнату (в нашем случае у него появляется комната "2325-2523")
	return (0);
}
