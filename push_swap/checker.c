/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medesmon <medesmon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 06:21:30 by medesmon          #+#    #+#             */
/*   Updated: 2019/09/23 20:52:20 by medesmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"
#include <stdarg.h>
#include "get_next_line.h"
#include "fcntl.h"

int	end()
{
	ft_putendl("Error");
	return (0);
}

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

int	checker(int argc, char **argv)
{
	char	*line;
	int		i;
	int		k;
	Stack_t	stack1;
	Stack_t	stack2;

	stack1.size = 0;
	stack2.size = 0;
	stack2.stack_num = 2;
	stack1.stack_num = 1;
	line = 0;
	i = 1;
	//цифры
	while (argv[i])
	{
		if (!ft_isnumber(argv[i]))
			return (end());
		push_rev(&stack1, ft_atoi(argv[i]));
		i++;
	}
	print_stack(&stack1);
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
			sa(&stack1);
		else if (ft_strcmp(line, "sb") == 0)
			sb(&stack2);
		else if (ft_strcmp(line, "ss") == 0)
			ss(&stack1, &stack2);
		else if (ft_strcmp(line, "pa") == 0)
			pa(&stack1, &stack2);
		else if (ft_strcmp(line, "pb") == 0)
			pb(&stack2, &stack1);
		else if (ft_strcmp(line, "ra") == 0)
			ra(&stack1);
		else if (ft_strcmp(line, "rb") == 0)
			rb(&stack2);
		else if (ft_strcmp(line, "rr") == 0)
			rr(&stack1, &stack2);
		else if (ft_strcmp(line, "rra") == 0)
			rra(&stack1);
		else if (ft_strcmp(line, "rrb") == 0)
			rrb(&stack2);
		else if (ft_strcmp(line, "rrr") == 0)
			rrr(&stack1, &stack2);
		else 
			return (end());
		free(line);
		print_stack(&stack1);
	}
	//проверка
	if (i - 1 != stack1.size)
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
