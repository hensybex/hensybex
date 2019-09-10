/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medesmon <medesmon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 18:53:37 by medesmon          #+#    #+#             */
/*   Updated: 2019/09/09 19:33:21 by medesmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
#include <stdarg.h>

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
			parse_flags(p);
			parse_width_pres_persent(p);
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
		p->i++;
	}
}

void    initialize(t_params *p)
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
	while (p->format[p->i] == '-' || p->format[p->i] == '+' || p->format[p->i] == ' ' || p->format[p->i] == '#' || p->format[p->i] == '0')
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

void	parse_width_pres_persent(t_params *p)
{
	if (p->format[p->i] == '*')
	{
		p->width = va_arg(p->ap, int);
		if (p->width < 0)
		{
			p->width *= -1;
			p->left = 1;
		}
		p->i++;
	}
	if (p->format[p->i] >= '0' && p->format[p->i] <= '9')
		p->width = 0;
	while (p->format[p->i] >= '0' && p->format[p->i] <= '9')
	{
		p->width *= 10;
		p->width += p->format[p->i] - 48;
		p->i++;
	}
	while (p->format[p->i] == ' ')
		p->i++;
	if (p->format[p->i] == '.')
	{
		p->dot = 1;
		p->i++;
		p->zero = 0;
		if (p->format[p->i] == '*')
		{
			p->pres = va_arg(p->ap, int);
			if (p->pres < 0)
			{
				p->dot = 0;
				p->pres = 0;
			}
			p->i++;
			if (p->zero == 0)
				p->zero = 1;
		}
		while (p->format[p->i] >= '0' && p->format[p->i] <= '9')
		{
			p->pres *= 10;
			p->pres += p->format[p->i] - 48;
			p->i++;
		}
	}
	if (p->format[p->i] == '%')
	{
		if (p->left == 0 && p->width != 0)
			p->len +=  apply_width(p->width + 1, 1, 0);
		ft_putchar('%');
		p->len++;
		if (p->left == 1 && p->width != 0)
			p->len +=  apply_width(p->width + 1, 1, 0);
	}
}

void	parse_modifiers(t_params *p)
{
	int counter;

	counter = 0;
	while (p->format[p->i] == 'h' ||  p->format[p->i] == 'l' || p->format[p->i] == 'L')
	{
		if (p->format[p->i] == 'h')
			counter--;
		else if (p->format[p->i] == 'l')
			counter++;
		else
			counter = 3;
		p->i++;
	}
	p->mod = counter;
}