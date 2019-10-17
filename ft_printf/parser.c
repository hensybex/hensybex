/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medesmon <medesmon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 22:25:50 by medesmon          #+#    #+#             */
/*   Updated: 2019/09/27 00:05:34 by medesmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parser_2(t_params *p)
{
	parse_flags(p);
	parse_width(p);
	parse_pres(p);
	parse_percent(p);
	parse_modifiers(p);
	parse_symbol(p);
	parse_string(p);
	parse_pointer(p);
	parse_d_i(p);
	parse_o(p);
	parse_unsigned(p);
	parse_hex(p);
	parse_hex_upper(p);
	parse_f(p);
}

void	parser(t_params *p)
{
	while (p->format[p->i])
	{
		if (ft_strcmp(p->format, "%") == 0)
			return ;
		initialize(p);
		if (p->format[p->i] != '%')
		{
			ft_putchar(p->format[p->i]);
			p->len++;
		}
		else
		{
			p->i++;
			parser_2(p);
		}
		p->i++;
	}
}

void	initialize(t_params *p)
{
	p->alt = 0;
	p->pos = 0;
	p->width = 0;
	p->pres = 0;
	p->left = 0;
	p->space = 0;
	p->zero = 0;
	p->mod = 0;
	p->dot = 0;
	p->fl = 0;
}

void	parse_flags(t_params *p)
{
	while (p->format[p->i] == '-' || p->format[p->i] == '+'
	|| p->format[p->i] == ' ' || p->format[p->i] == '#'
	|| p->format[p->i] == '0')
	{
		if (p->format[p->i] == '-')
			p->left = 1;
		if (p->format[p->i] == '+')
			p->pos = 1;
		if (p->format[p->i] == ' ')
			p->space = 1;
		if (p->format[p->i] == '#')
			p->alt = 1;
		if (p->format[p->i] == '0')
			p->zero = 1;
		p->format++;
	}
	if (p->left == 1 && p->zero == 1)
		p->zero = 0;
}
