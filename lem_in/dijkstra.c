/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dijkstra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medesmon <medesmon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 18:27:45 by medesmon          #+#    #+#             */
/*   Updated: 2019/10/09 08:35:16 by medesmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_room	init(t_room *rooms, int **linktable)
{
	int	i;
	int	len;

	len = 0;
	while (rooms[len].exist)
		len++;
	i = 0;
	while (i < len)
	{
		//связать rooms[i].num со значениями linktable
		rooms[i].min_len = len + 1;
		rooms[i].prev = NULL;
		rooms[i].is_vis = 0;
		i++;
	}
	rooms[len - 1].is_vis = 1;
	rooms[len - 1].min_len = 0;
	return (*rooms);
}

int	next_room(t_room *rooms, int len)
{
	int		fl;
	int		i;
	int		j;
	int		min;
	int		ptr;

	min = len + 1;
	i = 0;
	fl = 0;
	while (i < len)
	{
		if (rooms[i].is_vis == 1 && rooms[i].min_len < min)
		{
			min = rooms[i].min_len;
			ptr = i;
			fl = 1;
		}
		i++;	
	}
	if (fl == 1)
		return (ptr);
	else
		return (-1);
}

int	is_vis(t_room *rooms, int len)
{
	int	i;
	int	min;
	int	ptr;

	min = -1;
	i = 0;
	while (i < len)
	{
		if (rooms[i].is_vis == 1 && min < rooms[i].min_len)
			min = rooms[i].min_len + 1;
		i++;
	}
	i = 0;
	while (i < len)
	{
		if (rooms[i].is_vis == 1 && min > rooms[i].min_len)
		{
			ptr = i;
			min = rooms[i].min_len;
		}
		i++;
	}
	return (ptr);
}

int	choose_room(t_room *rooms, int room_num, int **linktable, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (linktable[rooms[room_num].table_num][i] == 1)
			return (rooms[i].table_num);
		i++;
	}
	return (-1);
}

int		**copy_linktable(int **linktable, t_room *rooms, int len)
{
	int	i;
	int	j;
	int	**new_linktable;

	i = -1;
	new_linktable = (int **)malloc(sizeof(int *) * len);
	while (++i < len)
		new_linktable[i] = (int *)malloc(sizeof(int) * len);
	i = 0;
	while (i < len)
	{
		j = 0;
		rooms[len - i - 1].table_num = i;
		while (j < len)
		{
			new_linktable[i][j] = linktable[i][j];
			j++;
		}
		i++;
	}
	return (new_linktable);
}

void	print_table(int **linktable, int len, t_room *rooms)
{
	int	i;
	int	j;

	i = -1;
	while (i < len)
	{
		j = 0;
		while (j < len)
		{
			if (i == -1)
			{
				ft_putstr(rooms[len - j - 1].name);
				ft_putchar(' ');
			}
			else
				ft_putnbr(linktable[i][j]);
			j++;
		}
		if (i == -1)
			ft_putchar('\n');
		i++;
		ft_putchar('\n');
	}
}

void	break_link(int	numi, int numj, int **linktable)
{
	linktable[numi][numj] = 0;
	linktable[numj][numi] = 0;
}

char	*get_sol(char *str, t_room *rooms, int i)
{
	str = ft_strjoin(str, "-");
	str = ft_strjoin(str, rooms[i].prev);
	return (str);
}

char	*dijkstra(t_room *rooms, int **linktable, int len)
{
	int		i;
	int		j;
	int		**tmp_linktable;
	char	*solution;

	tmp_linktable = (copy_linktable(linktable, rooms, len));
	//print_table(tmp_linktable, len, rooms);
	*rooms = init(rooms, tmp_linktable);
	i = len - 1;
	i = next_room(rooms, len);
	while (i != -1)
	{
		j = choose_room(rooms, i, tmp_linktable, len);
		while ((j != -1))
		{
			if (rooms[j].min_len > rooms[i].min_len + 1)
			{
				rooms[j].min_len = rooms[i].min_len + 1;
				rooms[j].prev = ft_strdup(rooms[i].name);
			}
			break_link(len - i - 1, len - j - 1, tmp_linktable);
			rooms[j].is_vis = 1;
			j = choose_room(rooms, i, tmp_linktable, len);
		}
		rooms[i].is_vis = 2;
		i = next_room(rooms, len);
	}
	i = 0;
	while (rooms[i].prev)
	{
		j = 0;
		while (ft_strcmp(rooms[i].prev, rooms[j].name) != 0)
			j++;
		i = j;
	}
	if (i != len - 1)
		return ("END");
	/* while (i < len)
	{
		ft_putstr(rooms[i].name);
		ft_putstr(" - ");
		ft_putstr(rooms[i].prev);
		ft_putstr(" - ");
		ft_putnbr(rooms[i].min_len);
		ft_putchar('\n');
		i++;
	}
	ft_putchar('\n'); */
	//solution = malloc(sizeof(char) * 2 * (rooms[0].min_len + 1));
	
	//запись решения
	solution = get_sol(rooms[0].name, rooms, 0); //запись первого перехода
	//break_link(rooms[0].table_num, rooms[ft_atoi(rooms[0].prev)].table_num, lemin->linktable); //разрыв линка первого перехода
	i = 0;
	while (ft_strcmp(rooms[0].prev, rooms[i].name) != 0)
		i++;
	if (ft_strcmp(rooms[0].prev, rooms[len - 1].name) ==  0)
		return (solution);
	while (ft_strcmp(rooms[i].prev, rooms[len - 1].name) != 0)
	{
		//break_link(rooms[i]);
		solution = get_sol(solution, rooms, i);
		j = 0;
		while (ft_strcmp(rooms[i].prev, rooms[j].name) != 0)
			j++;
		i = j;
	}
	solution = get_sol(solution, rooms, i);
	//очистка linktable
	/* print_final(lemin);
	break_link(rooms[0].table_num, rooms[ft_atoi(rooms[0].prev)].table_num, lemin->linktable);
	print_final(lemin); */
	return (solution);
}
