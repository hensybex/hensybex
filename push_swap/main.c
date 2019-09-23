/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medesmon <medesmon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 21:25:28 by medesmon          #+#    #+#             */
/*   Updated: 2019/09/23 20:52:15 by medesmon         ###   ########.fr       */
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

	stack1.size = 0;
	stack2.size = 0;
	stack2.stack_num = 2;
	stack1.stack_num = 1;
	i = 1;
	while (argv[i])
	{
		if (!ft_isnumber(argv[i]))
			return (end());
		push_rev(&stack1, ft_atoi(argv[i]));
		i++;
	}
	print_stack(&stack1);
	print_stack(&stack2);
	ft_putendl("------------------------------------");
	push_swap(&stack1, &stack2);
	ft_putendl("------------------------------------");
	print_stack(&stack1);
	print_stack(&stack2);
	return (0);
}
