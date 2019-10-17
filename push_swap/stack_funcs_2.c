/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_funcs_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medesmon <medesmon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 20:10:37 by medesmon          #+#    #+#             */
/*   Updated: 2019/09/26 23:17:38 by medesmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		pop_n(t_stack *stack, int n)
{
	int	i;

	i = 0;
	while (i++ < n)
		pop(stack);
	return (stack->data[stack->size]);
}

int		peek(t_stack *stack)
{
	return (stack->data[stack->size - 1]);
}

void	print_stack(t_stack *stack)
{
	int	i;

	i = 0;
	ft_putstr("stack ");
	ft_putnbr(stack->stack_num);
	ft_putstr(" consists of ");
	ft_putnbr(stack->size);
	if (stack->size % 10 == 1)
		ft_putendl(" element");
	else
		ft_putendl(" elements");
	while (i < stack->size)
	{
		ft_putnbr(stack->data[stack->size - i - 1]);
		if (i != stack->size - 1)
			ft_putchar('\n');
		i++;
	}
	ft_putchar('\n');
}
