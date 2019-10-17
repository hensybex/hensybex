/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medesmon <medesmon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 17:01:07 by medesmon          #+#    #+#             */
/*   Updated: 2019/10/12 15:59:56 by medesmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *stack, const int value)
{
	stack->data[stack->size] = value;
	stack->size++;
}

void	push_rev(t_stack *stack, const int value)
{
	int	i;

	stack->size++;
	i = stack->size - 1;
	while (i > 0)
	{
		stack->data[i] = stack->data[i - 1];
		i--;
	}
	stack->data[0] = value;
}

int		pop(t_stack *stack)
{
	stack->size--;
	return (stack->data[stack->size]);
}
