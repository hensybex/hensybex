/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_final_funcs.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medesmon <medesmon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 20:16:43 by medesmon          #+#    #+#             */
/*   Updated: 2019/10/17 17:49:37 by medesmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_both(int *len_in, int *len_out, t_stack *stack1, t_stack *stack2)
{
	while (ft_abs(*len_out) > 0 && ft_abs(*len_in) > 0)
	{
		if (*len_out > 0)
			rr(stack1, stack2, 1);
		else
			rrr(stack1, stack2, 1);
		if (*len_out > 0)
		{
			(*len_out)--;
			(*len_in)--;
		}
		else
		{
			(*len_out)++;
			(*len_in)++;
		}
	}
}

void	rotate_one(int *len_in, int *len_out, t_stack *stack1, t_stack *stack2)
{
	if (ft_abs(*len_out) > 0)
	{
		if (*len_out > 0)
			while ((*len_out)-- > 0)
				rb(stack1, 1);
		else
			while ((*len_out)++ < 0)
				rrb(stack1, 1);
	}
	else
	{
		if (*len_in > 0)
			while ((*len_in)-- > 0)
				ra(stack2, 1);
		else
			while ((*len_in)++ < 0)
				rra(stack2, 1);
	}
}

void	rotate_one_alt(int *len_in, int *len_out,
t_stack *stack1, t_stack *stack2)
{
	if (*len_out > 0)
		while ((*len_out)-- > 0)
			rb(stack1, 1);
	else
		while ((*len_out)++ < 0)
			rrb(stack1, 1);
	if (*len_in > 0)
		while ((*len_in)-- > 0)
			ra(stack2, 1);
	else
		while ((*len_in)++ < 0)
			rra(stack2, 1);
}
