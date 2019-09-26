/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgilwood <bgilwood@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 03:33:29 by medesmon          #+#    #+#             */
/*   Updated: 2019/09/26 20:06:59 by bgilwood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_width(t_params *p)
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
}

void	parse_pres(t_params *p)
{
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
}

void	parse_percent(t_params *p)
{
	if (p->format[p->i] == '%')
	{
		if (p->left == 0 && p->width != 0)
			p->len += apply_width(p->width + 1, 1, 0);
		ft_putchar('%');
		p->len++;
		if (p->left == 1 && p->width != 0)
			p->len += apply_width(p->width + 1, 1, 0);
	}
}

void	parse_modifiers(t_params *p)
{
	int counter;

	counter = 0;
	while (p->format[p->i] == 'h' || p->format[p->i] == 'l'
	|| p->format[p->i] == 'L')
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
