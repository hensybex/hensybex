/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_concrete.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medesmon <medesmon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 18:46:51 by medesmon          #+#    #+#             */
/*   Updated: 2019/10/17 17:47:20 by medesmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_concrete(t_stack *stack1, t_stack *stack2, int i)
{
	int k;

	k = 0;
	if (i <= stack1->size / 2)
	{
		while (k++ < i)
			rra(stack1, 1);
	}
	else
	{
		while (k++ < stack1->size - i)
		{
			ra(stack1, 1);
		}
	}
	pb(stack1, stack2, 1);
}

int		count_out(t_stack *stack, int i)
{
	int	k;
	int	len_out;

	k = 0;
	if (i <= stack->size / 2)
		while (k++ < i)
			len_out = -k;
	else
	{
		while (k < stack->size - i + 1)
			k++;
		len_out = k - 1;
	}
	return (len_out);
}

int		count_in(t_stack *stack_from, t_stack *stack_into, int i)
{
	int	fl;
	int	k;
	int	len_in;

	fl = 0;
	k = 0;
	while (fl == 0)
	{
		if (k == stack_from->size - 1)
		{
			fl = 1;
			k = -1;
		}
		else if (stack_into->data[i - 1] < stack_from->data[k]
		&& stack_into->data[i - 1] > stack_from->data[k + 1])
			fl = 1;
		k++;
	}
	if (k <= stack_from->size / 2)
		len_in = -k;
	else
		len_in = stack_from->size - k;
	return (len_in);
}

int		count_concrete(t_stack *stack1, t_stack *stack2, int i)
{
	int	len_out;
	int	len_in;
	int	full_len;

	len_out = count_out(stack1, i);
	len_in = count_in(stack2, stack1, i);
	if (len_out * len_in > 0)
	{
		if (ft_abs(len_out) > ft_abs(len_in))
			full_len = ft_abs(len_out);
		else
			full_len = ft_abs(len_in);
	}
	else
	{
		full_len = (ft_abs(len_out) + ft_abs(len_in));
	}
	return (full_len);
}

void	push_final(t_stack *stack1, t_stack *stack2, int i)
{
	int	len_out;
	int	len_in;

	len_out = count_out(stack1, i);
	len_in = count_in(stack2, stack1, i);
	if (len_out * len_in > 0)
	{
		rotate_both(&len_in, &len_out, stack1, stack2);
		rotate_one(&len_in, &len_out, stack1, stack2);
	}
	else
		rotate_one_alt(&len_in, &len_out, stack1, stack2);
	pa(stack1, stack2, 1);
}
