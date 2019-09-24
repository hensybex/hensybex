/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medesmon <medesmon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 06:21:30 by medesmon          #+#    #+#             */
/*   Updated: 2019/09/24 21:10:21 by medesmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"
#include <stdarg.h>
#include "get_next_line.h"
#include "fcntl.h"

int	ko()
{
	ft_putendl("KO");
	return (0);
}

int	is_valid(char *line)
{
	if (ft_strnequ(line, "sa", 3))
		return (1);
	else if (ft_strnequ(line, "sb", 3))
		return (1);
	else if (ft_strnequ(line, "ss", 3))
		return (1);
	else if (ft_strnequ(line, "pa", 3))
		return (1);
	else if (ft_strnequ(line, "pb", 3))
		return (1);
	else if (ft_strnequ(line, "ra", 3))
		return (1);
	else if (ft_strnequ(line, "rb", 3))
		return (1);
	else if (ft_strnequ(line, "rr", 3))
		return (1);
	else if (ft_strnequ(line, "rra", 4))
		return (1);
	else if (ft_strnequ(line, "rrb", 4))
		return (1);
	else if (ft_strnequ(line, "rrr", 4))
		return (1);
	else
		return (0);
}

int main(int argc, char **argv)
{
	char	*line;
	char	**line_1;
	int		i;
	int		k;
	Stack_t	stack1;
	Stack_t	stack2;
	int		fl;

	stack1.size = 0;
	stack2.size = 0;
	stack2.stack_num = 2;
	stack1.stack_num = 1;
	line = 0;
	//цифры
	if (argc < 2)
		return (0);
	if (argc == 2)
	{
		line_1 = ft_strsplit(argv[1], ' ');
		i = 0;
		while (line_1[i] != NULL)
		{
			if (!(ft_isnumber(line_1[i]) || (line_1[i][0] == '-' && ft_strcmp("-", line_1[i]) != 0)))
				return (end());
			if ((ft_atoi(line_1[i]) == -1 && ft_strcmp("-1", line_1[i]) != 0) || (ft_atoi(line_1[i]) == 0 && ft_strcmp("0", line_1[i]) != 0))
				return (end());
			push_rev(&stack1, ft_atoi(line_1[i]));
			i++;
		}
	}
	else
	{
		i = 1;
		while (argv[i])
		{
			if (!ft_isnumber(argv[i]) || (argv[i][0] == '-' && ft_strcmp("-", argv[i]) == 0))
				return (end());
			push_rev(&stack1, ft_atoi(argv[i]));
			i++;
		}
	}
	//check_duplicate
	i = 0;
	while (i < stack1.size)
	{
		k = 0;
		while (k < i)
		{
			if (stack1.data[i] == stack1.data[k])
				return (end());
			k++;
		}
		i++;
	}
	i = stack1.size - 1;
	//операции
	while (get_next_line(0, &line))
	{
		if (!is_valid(line))
		{
			ft_putendl("Error");
			free(line);
			return (0);
		}
		if (ft_strcmp(line, "sa") == 0)
			sa(&stack1, 0);
		else if (ft_strcmp(line, "sb") == 0)
			sb(&stack2, 0);
		else if (ft_strcmp(line, "ss") == 0)
			ss(&stack1, &stack2, 0);
		else if (ft_strcmp(line, "pa") == 0)
			pa(&stack1, &stack2, 0);
		else if (ft_strcmp(line, "pb") == 0)
			pb(&stack2, &stack1, 0);
		else if (ft_strcmp(line, "ra") == 0)
			ra(&stack1, 0);
		else if (ft_strcmp(line, "rb") == 0)
			rb(&stack2, 0);
		else if (ft_strcmp(line, "rr") == 0)
			rr(&stack1, &stack2, 0);
		else if (ft_strcmp(line, "rra") == 0)
			rra(&stack1, 0);
		else if (ft_strcmp(line, "rrb") == 0)
			rrb(&stack2, 0);
		else if (ft_strcmp(line, "rrr") == 0)
			rrr(&stack1, &stack2, 0);
		else 
			return (end());
		free(line);
	}
	//проверка
	//КОСТЯЖИВИ
	if (stack2.size != 0)
		return (ko());
	while (i > 1)
	{
		if (stack1.data[i] > stack1.data[i - 1])
			return (ko());
		i--;
	}
	ft_putendl("OK");
	return (0);
}
