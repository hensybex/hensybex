/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medesmon <medesmon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 21:25:28 by medesmon          #+#    #+#             */
/*   Updated: 2019/10/17 18:27:43 by medesmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"
#include <stdarg.h>

int	main(int argc, char **argv)
{
	t_stack stack1;
	t_stack stack2;
	int		i;

	init(&stack1, &stack2);
	i = 0;
	if ((i = input(argc, argv, &stack1)) == 0)
		return (end());
	if (stack1.size == 0)
		return (0);
	else if (i == -1)
		return (0);
	if (check_sorted(stack1) == 0)
		return (0);
	if (check_duplicate(stack1) == 0)
		return (end());
	push_swap(&stack1, &stack2);
	return (0);
}
