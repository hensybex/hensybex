/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medesmon <medesmon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 19:52:17 by medesmon          #+#    #+#             */
/*   Updated: 2019/10/17 18:29:19 by medesmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		input_line(char **argv, t_stack **stack)
{
	char	**line;
	int		i;
	char	*new;

	line = ft_strsplit(argv[1], ' ');
	i = 0;
	while (line[i] != NULL)
	{
		if (!(free_itoa(line, new, argv)))
			return (0);
		free(new);
		if (!(ft_isnumber(line[i]) || (line[i][0] == '-'
		&& ft_strcmp("-", line[i]) != 0)) ||
		(line[i][0] == '+' && ft_strcmp("+", line[i]) != 0))
			return (free_ret(line));
		if ((ft_atoi(line[i]) == -1 && ft_strcmp("-1", line[i]) != 0)
		|| (ft_atoi(line[i]) == 0 && (ft_strcmp("0", line[i]) != 0)))
			return (free_ret(line));
		push_rev(*stack, ft_atoi(line[i]));
		i++;
	}
	return (free_ret_1(line));
}

int		input_lines(char **argv, t_stack **stack)
{
	int		i;
	char	*new;

	i = 1;
	while (argv[i])
	{
		if (!(free_new(argv, i)))
			return (0);
		free(new);
		if (!ft_isnumber(argv[i]) || (argv[i][0]
		== '-' && ft_strcmp("-", argv[i]) == 0) ||
		(argv[i][0] == '+' && ft_strcmp("+", argv[i]) != 0))
			return (0);
		if ((ft_atoi(argv[i]) == -1 && ft_strcmp("-1", argv[i]) != 0)
		|| (ft_atoi(argv[i]) == 0 && ft_strcmp("0", argv[i]) != 0))
			return (0);
		push_rev(*stack, ft_atoi(argv[i]));
		i++;
	}
	return (1);
}

void	init(t_stack *stack1, t_stack *stack2)
{
	stack1->size = 0;
	stack2->size = 0;
	stack2->stack_num = 2;
	stack1->stack_num = 1;
}

int		input(int argc, char **argv, t_stack *stack1)
{
	if (argc < 2)
		return (-1);
	if (argc == 2)
	{
		if (input_line(argv, &stack1) == 0)
			return (0);
	}
	else
	{
		if (input_lines(argv, &stack1) == 0)
			return (0);
	}
	if (check_duplicate(*stack1) == 0)
		return (0);
	return (1);
}
