/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   letter_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgilwood <bgilwood@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 04:07:21 by medesmon          #+#    #+#             */
/*   Updated: 2019/09/26 20:06:38 by bgilwood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_hex_2(t_params *p, unsigned long long ival)
{
	if (ival != 0)
	{
		if (p->zero == 1)
			ft_putstr("0x");
		if (p->mod == 0)
			p->len += apply_width_16(p->width - 1 - p->fl, ival, p->zero) + 2;
		else
			p->len += apply_width_16(p->width - 1 - p->fl, ival, p->zero) + 2;
		if (p->zero == 0)
			ft_putstr("0x");
	}
	else
	{
		if (p->mod == 0)
			p->len += apply_width_16(p->width - p->fl, ival, p->zero);
		else
			p->len += apply_width_16(p->width - p->fl, ival, p->zero);
	}
	p->len += apply_pres_16(p->pres + 1, ival);
	if (p->mod == 2 || p->mod == 1)
		ft_putnbr_hex_long(ival);
	else
		ft_putnbr_hex(ival);
}

void	parse_hex_3(t_params *p, unsigned long long ival)
{
	if (p->mod == 0)
		p->len += apply_width_16(p->width + 1 - p->fl, ival, p->zero);
	else
		p->len += apply_width_16(p->width + 1 - p->fl, ival, p->zero);
	p->len += apply_pres_16(p->pres + 1, ival);
	if (p->mod == 2 || p->mod == 1)
		ft_putnbr_hex_long(ival);
	else
		ft_putnbr_hex(ival);
}

void	parse_hex_4(t_params *p, unsigned long long ival)
{
	ft_putstr("0x");
	p->len += apply_pres_16(p->pres + 1, ival);
	if (p->mod == 2 || p->mod == 1)
		ft_putnbr_hex_long(ival);
	else
		ft_putnbr_hex(ival);
	if (ival != 0)
		if (p->mod == 0)
			p->len += apply_width_16(p->width - 1 - p->fl, ival, 0) + 2;
		else
			p->len += apply_width_16(p->width - 1 - p->fl, ival, 0) + 2;
	else
	{
		if (p->mod == 0)
			p->len += apply_width_16(p->width - p->fl, ival, p->zero);
		else
			p->len += apply_width_16(p->width - p->fl, ival, p->zero);
	}
}

void	parse_hex_5(t_params *p, unsigned long long ival)
{
	p->len += apply_pres_16(p->pres + 1, ival);
	if (p->mod == 2 || p->mod == 1)
		ft_putnbr_hex_long(ival);
	else
		ft_putnbr_hex(ival);
	if (p->mod == 0)
		p->len += apply_width_16(p->width + 1 - p->fl, ival, p->zero);
	else
		p->len += apply_width_16(p->width + 1 - p->fl, ival, p->zero);
}

void	parse_hex(t_params *p)
{
	unsigned long long	ival;
	char				*cval;

	cval = NULL;
	if (p->format[p->i] == 'x')
	{
		apply_mod_uns(p, &ival);
		if (ret_hex(p, ival))
			return ;
		cval = ft_itoa(ival);
		if (p->alt == 1 && p->left == 0)
			parse_hex_2(p, ival);
		else if (p->alt == 0 && p->left == 0)
			parse_hex_3(p, ival);
		else if (p->alt == 1 && p->left == 1)
			parse_hex_4(p, ival);
		else if (p->alt == 0 && p->left == 1)
			parse_hex_5(p, ival);
		if (p->mod == 2 || p->mod == 1)
			p->len += ft_10_to_16_long(ival);
		else
			p->len += ft_10_to_16(ival);
	}
	if (cval != NULL)
		free(cval);
}
