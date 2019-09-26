/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   letter_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgilwood <bgilwood@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 02:30:33 by medesmon          #+#    #+#             */
/*   Updated: 2019/09/26 20:05:22 by bgilwood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_pointer_2(t_params *p, t_fl fl, int *pval)
{
	if (((long)pval) && p->dot == 0)
		p->width++;
	if (p->left == 0)
		p->len += apply_width(p->width - 2 -
		ft_10_to_16_long((long)pval) + fl.fl1, 0, p->zero);
	ft_putstr("0x");
	if (p->pres == 0 && pval == 0 && p->dot == 1 && p->alt == 0)
	{
		p->len += 2;
		if (p->width != 0)
			p->len += apply_width_16(p->width + 1, 0, p->zero) + p->width - 1;
		return ;
	}
	p->len += apply_pres(p->pres + fl.fl2 +
	fl.fl_pres - ft_10_to_16_long((long)pval), 1);
	ft_putnbr_hex_long((long)pval);
	p->len += ft_10_to_16_long((long)pval) + 2;
	if (pval == 0)
		p->len++;
	if (p->left == 1)
		p->len += apply_width(p->width - 2 -
		ft_10_to_16_long((long)pval) + fl.fl1, 0, p->zero);
}

void	parse_pointer(t_params *p)
{
	int		*pval;
	t_fl	fl;

	if (p->format[p->i] == 'p')
	{
		fl.fl1 = 0;
		fl.fl_pres = 0;
		fl.fl2 = 1;
		pval = va_arg(p->ap, int *);
		if (p->pres > ft_10_to_16_long((long)pval) && (long)pval)
		{
			if (p->pres - ft_10_to_16_long((long)pval) == 1)
				fl.fl_pres = 1;
			else
				fl.fl_pres = 2;
		}
		if ((char)pval != 0)
		{
			fl.fl1 = 1;
			fl.fl2 = 0;
		}
		parse_pointer_2(p, fl, pval);
	}
}
