/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medesmon <medesmon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 06:21:30 by medesmon          #+#    #+#             */
/*   Updated: 2019/10/17 17:46:35 by medesmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"
#include <stdarg.h>
#include "get_next_line.h"
#include "fcntl.h"

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

int	is_valid_ret(char **line)
{
	if (!is_valid(*line))
	{
		free(*line);
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	char	*line;
	int		i;
	t_stack	stack1;
	t_stack	stack2;

	init(&stack1, &stack2);
	line = 0;
	if ((i = input(argc, argv, &stack1)) == 0)
		return (end());
	if (stack1.size == 0)
		return (0);
	i = stack1.size - 1;
	while (get_next_line(0, &line))
	{
		if (!is_valid_ret(&line))
			return (end());
		if (check_commands(line, &stack1, &stack2) == 0)
			return (end());
		free(line);
	}
	if (ko(stack1, stack2) == 0)
		return (print_ko());
	ft_putendl("OK");
	return (0);
}
