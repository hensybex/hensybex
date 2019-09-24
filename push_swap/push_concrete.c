/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_concrete.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medesmon <medesmon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 18:46:51 by medesmon          #+#    #+#             */
/*   Updated: 2019/09/24 22:09:16 by medesmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"
#include <stdarg.h>

int		end()
{
	ft_putendl("Error");
	return (0);
}

void	push_concrete(Stack_t *stack1, Stack_t *stack2, int i)
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

int		count_out(Stack_t *stack1, int i)
{
	int	fl;
	int	k;
	int	len_out;

	k = 0;
	fl = 0;
	if (i <= stack1->size / 2) //сдвиг вверх
		while (k++ < i) 
			len_out = -k;
	else //сдвиг вниз
	{
		while (k++ < stack1->size - i);
		len_out = k - 1;
	}
	return(len_out);
}

int		count_concrete(Stack_t *stack1, Stack_t *stack2, int i)
{
	int	k;
	int	fl;
	int	len_out;
	int	len_in;
	int	full_len;

	fl = 0;
	k = 0;
	if (i <= stack1->size / 2) //сдвиг вверх
		while (k++ < i) 
			len_out = -k;
	else //сдвиг вниз
	{
		while (k++ < stack1->size - i);
		len_out = k - 1;
	}
	k = 0;
	while (fl == 0)
	{
		if (k == stack2->size - 1)
		{
			fl = 1;
			k = -1;
		}
		else if (stack1->data[i - 1] < stack2->data[k] && stack1->data[i - 1] > stack2->data[k + 1])
			fl = 1;
		k++;
	}
	if (k <= stack2->size / 2)  //сдвиг вверх
		len_in = -k;
	else  //сдвиг вниз
		len_in = stack2->size - k;
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

void	push_final(Stack_t *stack1, Stack_t *stack2, int i)
{
	int	k;
	int	fl;
	int	len_out;
	int	len_in;
	int	full_len;

	fl = 0;
	k = 0;
	if (i <= stack1->size / 2) //сдвиг вверх
		while (k++ < i) 
			len_out = -k;
	else //сдвиг вниз
	{
		while (k++ < stack1->size - i);
		len_out = k - 1;
	}
	k = 0;
	while (fl == 0)
	{
		if (k == stack2->size - 1)
		{
			fl = 1;
			k = -1;
		}
		else if (stack1->data[i - 1] < stack2->data[k] && stack1->data[i - 1] > stack2->data[k + 1])
			fl = 1;
		k++;
	}
	if (k <= stack2->size / 2)  //сдвиг вверх
		len_in = -k;
	else  //сдвиг вниз
		len_in = stack2->size - k;
	if (len_out * len_in > 0)
	{
		while (ft_abs(len_out) > 0 && ft_abs(len_in) > 0)
		{
			if (len_out > 0)
				rr(stack1, stack2, 1);
			else
				rrr(stack1, stack2, 1);
			if (len_out > 0)
			{
				len_out--;
				len_in--;
			}
			else
			{
				len_out++;
				len_in++;
			}
		}
		if (ft_abs(len_out) > 0)
		{
			if (len_out > 0)
				while (len_out-- > 0)
					rb(stack1, 1);
			else
				while (len_out++ < 0)
					rrb(stack1, 1);
		}
		else
		{
			if (len_in > 0)
				while (len_in-- > 0)
					ra(stack2, 1);
			else
				while (len_in++ < 0)
					rra(stack2, 1);
		}
	}
	else
	{
		if (len_out > 0)
			while (len_out-- > 0)
				rb(stack1, 1);
		else
			while (len_out++ < 0)
				rrb(stack1, 1);
		if (len_in > 0)
			while (len_in-- > 0)
				ra(stack2, 1);
		else
			while (len_in++ < 0)
				rra(stack2, 1);
	}
	pa(stack1, stack2, 1);
}
