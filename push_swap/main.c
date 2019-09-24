/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medesmon <medesmon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 21:25:28 by medesmon          #+#    #+#             */
/*   Updated: 2019/09/24 18:16:24 by medesmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"
#include <stdarg.h>

int main(int argc, char **argv)
{
	Stack_t stack1;
	Stack_t stack2;
	int		i;
	char	**line;
	int		k;

	stack1.size = 0;
	stack2.size = 0;
	stack2.stack_num = 2;
	stack1.stack_num = 1;
	i = 0;
	ft_putendl("ERROR");
	if (argc < 2)
	{
		ft_putendl("Error");
		return (0);
	}
	if (argc == 2)
	{
		line = ft_strsplit(argv[1], ' ');
		i = 0;
		while (line[i] != NULL)
		{
			if (!ft_isnumber(line[i]))
				return (end());
			//ft_putendl(line[i]);
			push_rev(&stack1, ft_atoi(line[i]));
			i++;
		}
	}
	else
	{
		i = 1;
		while (argv[i])
		{
			if (!ft_isnumber(argv[i]))
				return (end());
			push_rev(&stack1, ft_atoi(argv[i]));
			i++;
		}
	}
	i = 0;
	while (i < stack1.size - 2)
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
	/* print_stack(&stack1);
	print_stack(&stack2);
	ft_putendl("------------------------------------"); */
	push_swap(&stack1, &stack2);
	/* ft_putendl("------------------------------------");
	print_stack(&stack1);
	print_stack(&stack2); */
	return (0);
}
