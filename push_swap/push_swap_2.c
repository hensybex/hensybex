/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medesmon <medesmon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 20:51:00 by medesmon          #+#    #+#             */
/*   Updated: 2019/10/17 17:47:17 by medesmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_back(t_stack *stack2, t_stack *stack1)
{
	int	i;
	int	min;
	int	k;
	int	position;

	while (stack2->size)
	{
		i = 0;
		min = stack2->size + stack1->size;
		while (i < stack2->size)
		{
			k = count_concrete(stack2, stack1, i + 1);
			if (k < min)
			{
				position = i + 1;
				min = k;
			}
			i++;
		}
		push_final(stack2, stack1, position);
	}
}

void	sort_final(t_stack *stack1, t_duo duo)
{
	int i;
	int position;

	i = 0;
	while (i < stack1->size)
	{
		if (stack1->data[i] == duo.max)
			position = i;
		i++;
	}
	if (position <= stack1->size / 2)
		while (stack1->data[0] != duo.max)
			rra(stack1, 1);
	else
		while (stack1->data[0] != duo.max)
			ra(stack1, 1);
}
