/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_fucns.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medesmon <medesmon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 21:36:01 by medesmon          #+#    #+#             */
/*   Updated: 2019/09/26 21:54:19 by medesmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sa(t_stack *stack, int t)
{
	int	temp;

	if (stack->size == 0)
		return (end());
	temp = stack->data[stack->size - 1];
	stack->data[stack->size - 1] = stack->data[stack->size - 2];
	stack->data[stack->size - 2] = temp;
	if (t == 1)
		ft_putendl("sa");
	return (0);
}

int	sb(t_stack *stack, int t)
{
	int	temp;

	if (stack->size == 0)
		return (end());
	temp = stack->data[stack->size - 1];
	stack->data[stack->size - 1] = stack->data[stack->size - 2];
	stack->data[stack->size - 2] = temp;
	if (t == 1)
		ft_putendl("sb");
	return (0);
}

int	ss(t_stack *stack1, t_stack *stack2, int t)
{
	int	temp;

	if (stack1->size == 0 || stack2->size == 0)
		return (end());
	temp = stack1->data[stack1->size - 1];
	stack1->data[stack1->size - 1] = stack1->data[stack1->size - 2];
	stack1->data[stack1->size - 2] = temp;
	temp = stack2->data[stack2->size - 1];
	stack2->data[stack2->size - 1] = stack2->data[stack2->size - 2];
	stack2->data[stack2->size - 2] = temp;
	if (t == 1)
		ft_putendl("ss");
	return (0);
}

int	pa(t_stack *stack_from, t_stack *stack_into, int t)
{
	int	temp;

	if (stack_from->size == 0)
		return (end());
	if (stack_from->size != 0)
	{
		temp = stack_from->data[stack_from->size - 1];
		push(stack_into, temp);
		pop(stack_from);
	}
	if (t == 1)
		ft_putendl("pa");
	return (0);
}

int	pb(t_stack *stack_from, t_stack *stack_into, int t)
{
	int	temp;

	if (stack_from->size == 0)
		return (end());
	if (stack_from->size != 0)
	{
		temp = stack_from->data[stack_from->size - 1];
		push(stack_into, temp);
		pop(stack_from);
	}
	if (t == 1)
		ft_putendl("pb");
	return (0);
}
