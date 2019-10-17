/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_funcs_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medesmon <medesmon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 20:12:25 by medesmon          #+#    #+#             */
/*   Updated: 2019/10/17 17:46:44 by medesmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ra(t_stack *stack, int t)
{
	int	temp1;
	int	temp2;
	int	i;

	if (stack->size == 0)
		return (0);
	i = stack->size - 1;
	temp2 = stack->data[stack->size - 1];
	while (i > 0)
	{
		temp1 = stack->data[i];
		stack->data[i] = stack->data[i - 1];
		stack->data[i - 1] = temp1;
		i--;
	}
	stack->data[0] = temp2;
	if (t == 1)
		ft_putendl("ra");
	return (1);
}

int	rb(t_stack *stack, int t)
{
	int	temp1;
	int	temp2;
	int	i;

	if (stack->size == 0)
		return (0);
	i = stack->size - 1;
	temp2 = stack->data[stack->size - 1];
	while (i > 0)
	{
		temp1 = stack->data[i];
		stack->data[i] = stack->data[i - 1];
		stack->data[i - 1] = temp1;
		i--;
	}
	stack->data[0] = temp2;
	if (t == 1)
		ft_putendl("rb");
	return (1);
}

int	rr(t_stack *stack1, t_stack *stack2, int t)
{
	if (stack1->size == 0 || stack2->size == 0)
		return (0);
	ra(stack1, 0);
	rb(stack2, 0);
	if (t == 1)
		ft_putendl("rr");
	return (1);
}
