/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_funcs_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medesmon <medesmon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 20:13:01 by medesmon          #+#    #+#             */
/*   Updated: 2019/10/17 17:46:41 by medesmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rra(t_stack *stack, int t)
{
	int	temp1;
	int	temp2;
	int	i;

	if (stack->size == 0)
		return (0);
	i = 0;
	temp2 = stack->data[0];
	while (i < stack->size - 1)
	{
		temp1 = stack->data[i];
		stack->data[i] = stack->data[i + 1];
		stack->data[i + 1] = temp1;
		i++;
	}
	stack->data[stack->size - 1] = temp2;
	if (t == 1)
		ft_putendl("rra");
	return (1);
}

int	rrb(t_stack *stack, int t)
{
	int	temp1;
	int	temp2;
	int	i;

	if (stack->size == 0)
		return (0);
	i = 0;
	temp2 = stack->data[0];
	while (i < stack->size - 1)
	{
		temp1 = stack->data[i];
		stack->data[i] = stack->data[i + 1];
		stack->data[i + 1] = temp1;
		i++;
	}
	stack->data[stack->size - 1] = temp2;
	if (t == 1)
		ft_putendl("rrb");
	return (1);
}

int	rrr(t_stack *stack1, t_stack *stack2, int t)
{
	if (stack1->size == 0 || stack2->size == 0)
		return (0);
	rra(stack1, 0);
	rrb(stack2, 0);
	if (t == 1)
		ft_putendl("rrr");
	return (1);
}
