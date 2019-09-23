/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medesmon <medesmon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 18:26:52 by medesmon          #+#    #+#             */
/*   Updated: 2019/09/23 22:06:00 by medesmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

t_duo	find_min_max(Stack_t *stack1)
{
	t_duo	params;
	int		i;
	int		fl;

	fl = 0;
	i = 0;
	params.min = stack1->data[0];
	params.max = stack1->data[0];
	while (i++ < stack1->size - 1)
	{
		if (stack1->data[i] < params.min)
			params.min = stack1->data[i];
		if (stack1->data[i] > params.max)
			params.max = stack1->data[i];
	}
	return (params);
}

void	push_3_elems(Stack_t *stack1, Stack_t *stack2, t_duo duo)
{
	int	fl;
	int	i;
	int	min;
	int	pos;
	int	k;

	fl = 0;
	while (stack1->size >= 4)
	{
		i = 0;
		min = stack1->size;
		while (i < stack1->size)
		{
			if (fl == 0 && (stack1->data[i] != duo.min && stack1->data[i] != duo.max))
				fl = stack1->data[i];
			else if (stack1->data[i] != duo.min && stack1->data[i] != duo.max && stack1->data[i] != fl)
			{
				k = stack1->size - i;
				if (k < min)
				{
					pos = i + 1;
					min = k;
				}
			}
			i++;
		}
		push_concrete(stack1, stack2, pos);
	}
}

void	sort_3(Stack_t *stack1, t_duo duo)
{
	if (stack1->data[2] == duo.min && stack1->data[1] == duo.max)
		ra(stack1);
	
	else if (stack1->data[1] == duo.min && stack1->data[0] == duo.max)
		sa(stack1);
	else if (stack1->data[2] == duo.max && stack1->data[1] == duo.min)
		rra(stack1);
}

void    push_back(Stack_t *stack2, Stack_t *stack1)
{
	int i;
	int min;
	int k;
	int position;

	while(stack2->size)
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

void	sort_final(Stack_t *stack1, Stack_t *stack2, t_duo duo)
{
	int i;
	int position;

	i = 0;
	while(i < stack1->size)
	{
		if (stack1->data[i] == duo.max)
			position = i;
		i++;
	}
	if (position <= stack1->size / 2)
		while(stack1->data[0] != duo.max)
			rra(stack1);
	else
		while(stack1->data[0] != duo.max)
			ra(stack1);
}

void	push_swap(Stack_t *stack1, Stack_t *stack2)
{
	t_duo		duo;
	int			mas[stack1->size];
	int			len;

	duo = find_min_max(stack1);
	push_3_elems(stack1, stack2, duo);
	sort_3(stack1, duo);
	push_back(stack2, stack1);
	sort_final(stack1, stack2, duo);
}
