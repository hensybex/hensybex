/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   letter_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgilwood <bgilwood@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 22:26:19 by medesmon          #+#    #+#             */
/*   Updated: 2019/09/26 20:05:47 by bgilwood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ret_u(t_params *p, unsigned long long ival)
{
	if (p->pres == 0 && ival == 0 && p->dot == 1 && p->alt == 0)
	{
		if (p->width != 0)
			p->len += apply_width_16(p->width + 1, 0, p->zero) + p->width - 1;
		return (1);
	}
	if (p->pres > ft_count_num(ival))
		p->fl = p->pres - ft_count_num(ival);
	if (p->left == 0)
	{
		p->len += apply_width_long_long(p->width + 1 - p->fl, ival, p->zero);
		p->len += apply_pres(p->pres + 1, ival);
	}
	return (0);
}

void	parse_unsigned(t_params *p)
{
	unsigned long long	ival;

	if (p->format[p->i] == 'u')
	{
		apply_mod_uns(p, &ival);
		if (ret_u(p, ival))
			return ;
		if (p->mod == -1)
			ft_putnbr_uns(ival);
		else if (p->mod == -2)
			ft_putnbr_uns(ival);
		else
			ft_putnbr_big(ival);
		p->len += ft_count_num_long_long(ival);
		if (p->left == 1)
		{
			p->len += apply_width_long_long(p->width + 1
			- p->fl, ival, p->zero);
			p->len += apply_pres(p->pres + 1, ival);
		}
	}
}
