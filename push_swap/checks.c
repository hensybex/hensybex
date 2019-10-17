/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medesmon <medesmon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 19:46:48 by medesmon          #+#    #+#             */
/*   Updated: 2019/10/17 17:46:43 by medesmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sorted(t_stack stack)
{
	int	i;
	int	fl;

	i = 0;
	fl = 0;
	while (i < stack.size - 1)
	{
		if (stack.data[i] > stack.data[i + 1])
			i++;
		else
		{
			fl = 1;
			i++;
		}
	}
	if (fl == 0)
		return (0);
	return (1);
}

int	check_duplicate(t_stack stack)
{
	int	i;
	int	k;

	i = 0;
	while (i < stack.size)
	{
		k = 0;
		while (k < i)
		{
			if (stack.data[i] == stack.data[k])
				return (0);
			k++;
		}
		i++;
	}
	return (1);
}

int	check_commands(char *line, t_stack *stack1, t_stack *stack2)
{
	if (ft_strcmp(line, "sa") == 0)
		sa(stack1, 0);
	else if (ft_strcmp(line, "sb") == 0)
		sb(stack2, 0);
	else if (ft_strcmp(line, "ss") == 0)
		ss(stack1, stack2, 0);
	else if (ft_strcmp(line, "pa") == 0)
		pa(stack2, stack1, 0);
	else if (ft_strcmp(line, "pb") == 0)
		pb(stack1, stack2, 0);
	else if (ft_strcmp(line, "ra") == 0)
		ra(stack1, 0);
	else if (ft_strcmp(line, "rb") == 0)
		rb(stack2, 0);
	else if (ft_strcmp(line, "rr") == 0)
		rr(stack1, stack2, 0);
	else if (ft_strcmp(line, "rra") == 0)
		rra(stack1, 0);
	else if (ft_strcmp(line, "rrb") == 0)
		rrb(stack2, 0);
	else if (ft_strcmp(line, "rrr") == 0)
		rrr(stack1, stack2, 0);
	else
		return (0);
	return (1);
}
