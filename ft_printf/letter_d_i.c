/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   letter_d_i.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgilwood <bgilwood@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 02:31:51 by medesmon          #+#    #+#             */
/*   Updated: 2019/09/26 20:04:40 by bgilwood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ret_d_i(t_params *p, int ival)
{
	if (ival == 0 && p->width && p->pres == 0 &&
	p->dot == 0 && p->pos == 0 && p->zero == 0)
	{
		if (p->left == 0)
			p->len += apply_width(p->width, 0, p->zero) + 1;
		ft_putnbr(0);
		if (p->left == 1)
			p->len += apply_width(p->width, 0, p->zero) + 1;
		return (1);
	}
	if (p->pres == 0 && ival == 0 && p->dot == 1 && p->alt == 0)
	{
		if (p->width != 0)
			p->len += apply_width_16(p->width + 1, 0, p->zero) + p->width - 1;
		return (1);
	}
	return (0);
}

void	parse_d_i_2(t_params *p, long long int ival)
{
	if (ival == 0 && p->pres)
	{
		if (p->width)
			p->len += p->width - p->pres;
		p->len--;
	}
	if ((ival == 0 && p->space == 1) || (p->left == 1 && ival == 0))
	{
		if (p->space == 1)
			ft_putchar(' ');
		p->width--;
		p->len += 2;
	}
	if (p->pos == 1 && ival >= 0 && p->zero == 1)
	{
		ft_putchar('+');
		if (ival == 0)
		{
			p->width--;
			p->len++;
		}
		p->len++;
	}
}

void	parse_d_i_3(t_params *p, long long int *ival)
{
	if ((*ival < 0 && p->zero == 1) || ((*ival < 0 && p->pres)))
	{
		if (p->left == 0 && p->zero == 0)
		{
			if (p->pres >= ft_count_num(*ival))
				p->width--;
		}
		else
		{
			ft_putchar('-');
			p->len++;
			*ival = -*ival;
			p->pos = 0;
			p->width--;
		}
	}
	if (p->left == 0 && (p->pres - ft_count_num(*ival) > 0))
		p->len += apply_width_long(p->width - p->pos - p->space +
		1 - p->pres + ft_count_num(*ival), *ival, p->zero);
	else if (p->left == 0 && (p->pres - ft_count_num(*ival) <= 0))
		p->len += apply_width_long(p->width - p->pos -
		p->space + 1, *ival, p->zero);
}

void	parse_d_i_4(t_params *p, long long int *ival)
{
	if (p->pos == 1 && *ival >= 0 && p->zero == 0)
	{
		ft_putchar('+');
		p->len++;
	}
	else if (p->pos == 0 && *ival > 0 && p->space == 1)
	{
		ft_putchar(' ');
		p->len++;
	}
	if (*ival == 0 && p->pres)
	{
		p->pres--;
		p->len++;
	}
	if ((*ival < 0 && p->pres) && p->left == 0)
	{
		ft_putchar('-');
		p->len++;
		*ival = -*ival;
		p->pos = 0;
		p->width--;
	}
	p->len += apply_pres(p->pres + 1, *ival);
	ft_putnbr(*ival);
}

void	parse_d_i(t_params *p)
{
	long long int ival;

	if (p->format[p->i] == 'd' || p->format[p->i] == 'i')
	{
		apply_mod_int(p, &ival);
		if (ret_d_i(p, ival))
			return ;
		parse_d_i_2(p, ival);
		parse_d_i_3(p, &ival);
		parse_d_i_4(p, &ival);
		if (p->left == 1 && (p->pres - ft_count_num(ival) > 0))
			p->len += apply_width_long(p->width - p->pos
			+ 1 - p->pres + ft_count_num(ival), ival, p->zero);
		else if (p->left == 1 && (p->pres - ft_count_num(ival) <= 0))
			p->len += apply_width_long(p->width - p->pos + 1, ival, p->zero);
		p->len += ft_count_num(ival);
		if (ival == (-9223372036854775807 - 1))
			p->len += 19;
	}
}
