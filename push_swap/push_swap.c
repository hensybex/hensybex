/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medesmon <medesmon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 18:26:52 by medesmon          #+#    #+#             */
/*   Updated: 2019/10/17 17:46:37 by medesmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

t_duo	find_min_max(t_stack *stack1)
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

void	choose_elems(t_params *p, t_duo duo, t_stack stack, int min)
{
	if (p->fl == 0 && (stack.data[p->i] != duo.min
	&& stack.data[p->i] != duo.max))
		p->fl = stack.data[p->i];
	else if (stack.data[p->i] != duo.min && stack.data[p->i]
	!= duo.max && stack.data[p->i] != p->fl)
	{
		p->k = stack.size - p->i;
		if (p->k < min)
		{
			p->pos = p->i + 1;
			min = p->k;
		}
	}
	p->i++;
}

void	push_3_elems(t_stack *stack1, t_stack *stack2, t_duo duo)
{
	t_params	p;
	int			min;

	p.fl = 0;
	while (stack1->size >= 4)
	{
		p.i = 0;
		min = stack1->size;
		while (p.i < stack1->size)
			choose_elems(&p, duo, *stack1, min);
		push_concrete(stack1, stack2, p.pos);
	}
}

void	sort_3(t_stack *stack1, t_duo duo)
{
	if ((stack1->data[0] == duo.min && stack1->data[2] == duo.max)
	|| (stack1->data[1] == duo.min && stack1->data[0] == duo.max) ||
	(stack1->data[2] == duo.min && stack1->data[1] == duo.max))
		sa(stack1, 1);
}

void	push_swap(t_stack *stack1, t_stack *stack2)
{
	t_duo		duo;

	duo = find_min_max(stack1);
	push_3_elems(stack1, stack2, duo);
	sort_3(stack1, duo);
	push_back(stack2, stack1);
	sort_final(stack1, duo);
}
