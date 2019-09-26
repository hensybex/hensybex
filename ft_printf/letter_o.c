/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   letter_o.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgilwood <bgilwood@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 22:26:11 by medesmon          #+#    #+#             */
/*   Updated: 2019/09/26 20:05:11 by bgilwood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_o_2(t_params *p, unsigned long long int ival)
{
	if (ival != 0)
	{
		if (p->pres - ft_10_to_8_long(ival) > 0 && p->pres)
			p->len += apply_width_8(p->width -
			p->pres + ft_10_to_8_long(ival), ival, p->zero) + 1;
		else
			p->len += apply_width_8(p->width, ival, p->zero) + 1;
		ft_putstr("0");
	}
	else
		p->len += apply_width_8(p->width, ival, p->zero);
	if (p->mod == 2 || p->mod == 1)
	{
		p->len += apply_pres(p->pres, ival);
		ft_putnbr_8_long(ival);
	}
	else
	{
		p->len += apply_pres(p->pres, ival);
		ft_putnbr_8(ival);
	}
}

void	parse_o_3(t_params *p, unsigned long long int ival)
{
	if (p->pres - ft_10_to_8_long(ival) > 0 && p->pres)
		p->len += apply_width_8(p->width -
		p->pres + ft_10_to_8_long(ival) + 1, ival, p->zero);
	else
		p->len += apply_width_8(p->width + 1, ival, p->zero);
	if (p->mod == 2 || p->mod == 1)
	{
		p->len += apply_pres(p->pres + 1, ival);
		ft_putnbr_8_long(ival);
	}
	else
	{
		p->len += apply_pres(p->pres + 1, ival);
		ft_putnbr_8(ival);
	}
}

void	parse_o_4(t_params *p, unsigned long long int ival)
{
	ft_putstr("0");
	if (p->mod == 2 || p->mod == 1)
	{
		p->len += apply_pres(p->pres + 1, ival);
		ft_putnbr_8_long(ival);
	}
	else
	{
		p->len += apply_pres(p->pres + 1, ival);
		ft_putnbr_8(ival);
	}
	if (ival != 0)
		if (p->pres - ft_10_to_8_long(ival) > 0 && p->pres)
			p->len += apply_width_8(p->width -
			p->pres + ft_10_to_8_long(ival), ival, p->zero) + 1;
		else
			p->len += apply_width_8(p->width, ival, p->zero) + 1;
	else
		p->len += apply_width_8(p->width, ival, p->zero);
}

void	parse_o_5(t_params *p, unsigned long long int ival)
{
	if (p->mod == 2 || p->mod == 1)
	{
		p->len += apply_pres(p->pres + 1, ival);
		ft_putnbr_8_long(ival);
	}
	else
	{
		p->len += apply_pres(p->pres + 1, ival);
		ft_putnbr_8(ival);
	}
	if (p->pres - ft_10_to_8_long(ival) > 0)
		p->len += apply_width_8(p->width - p->pres
		+ ft_10_to_8_long(ival) + 1, ival, p->zero);
	else
		p->len += apply_width_8(p->width + 1, ival, p->zero);
}

void	parse_o(t_params *p)
{
	unsigned long long int	ival;
	char					*cval;

	cval = NULL;
	if (p->format[p->i] == 'o')
	{
		apply_mod_uns(p, &ival);
		cval = ft_itoa(ival);
		if (ret_o(p, ival))
			return ;
		if (p->alt == 1 && p->left == 0)
			parse_o_2(p, ival);
		else if (p->alt == 0 && p->left == 0)
			parse_o_3(p, ival);
		else if (p->alt == 1 && p->left == 1)
			parse_o_4(p, ival);
		else if (p->alt == 0 && p->left == 1)
			parse_o_5(p, ival);
		if (p->mod == 2 || p->mod == 1)
			p->len += ft_10_to_8_long(ival);
		else
			p->len += ft_10_to_8_long(ival);
	}
	if (cval != NULL)
		free(cval);
}
