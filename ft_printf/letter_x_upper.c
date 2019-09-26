/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   letter_x_upper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgilwood <bgilwood@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 04:07:49 by medesmon          #+#    #+#             */
/*   Updated: 2019/09/26 20:05:55 by bgilwood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_hex_upper_2(t_params *p, unsigned long long ival)
{
	if (ival != 0)
	{
		if (p->zero == 1)
			ft_putstr("0X");
		if (p->mod == 0)
			p->len += apply_width_16(p->width - 1 - p->fl, ival, p->zero) + 2;
		else
			p->len += apply_width_16(p->width - 1 - p->fl, ival, p->zero) + 2;
		if (p->zero == 0)
			ft_putstr("0X");
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
		ft_putnbr_hex_long_upper(ival);
	else
		ft_putnbr_hex_upper(ival);
}

void	parse_hex_upper_3(t_params *p, unsigned long long ival)
{
	if (p->mod == 0)
		p->len += apply_width_16(p->width + 1 - p->fl, ival, p->zero);
	else
		p->len += apply_width_16(p->width + 1 - p->fl, ival, p->zero);
	p->len += apply_pres_16(p->pres + 1, ival);
	if (p->mod == 2 || p->mod == 1)
		ft_putnbr_hex_long_upper(ival);
	else
		ft_putnbr_hex_upper(ival);
}

void	parse_hex_upper_4(t_params *p, unsigned long long ival)
{
	ft_putstr("0X");
	p->len += apply_pres_16(p->pres + 1, ival);
	if (p->mod == 2 || p->mod == 1)
		ft_putnbr_hex_long_upper(ival);
	else
		ft_putnbr_hex_upper(ival);
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

void	parse_hex_upper_5(t_params *p, unsigned long long ival)
{
	p->len += apply_pres_16(p->pres + 1, ival);
	if (p->mod == 2 || p->mod == 1)
		ft_putnbr_hex_long_upper(ival);
	else
		ft_putnbr_hex_upper(ival);
	if (p->mod == 0)
		p->len += apply_width_16(p->width + 1 - p->fl, ival, p->zero);
	else
		p->len += apply_width_16(p->width + 1 - p->fl, ival, p->zero);
}

void	parse_hex_upper(t_params *p)
{
	unsigned long long	ival;
	char				*cval;

	cval = NULL;
	if (p->format[p->i] == 'X')
	{
		apply_mod_uns(p, &ival);
		if (ret_hex_upper(p, ival))
			return ;
		cval = ft_itoa(ival);
		if (p->alt == 1 && p->left == 0)
			parse_hex_upper_2(p, ival);
		else if (p->alt == 0 && p->left == 0)
			parse_hex_upper_3(p, ival);
		else if (p->alt == 1 && p->left == 1)
			parse_hex_upper_4(p, ival);
		else if (p->alt == 0 && p->left == 1)
			parse_hex_upper_5(p, ival);
		if (p->mod == 2 || p->mod == 1)
			p->len += ft_10_to_16_long(ival);
		else
			p->len += ft_10_to_16(ival);
	}
	if (cval != NULL)
		free(cval);
}
