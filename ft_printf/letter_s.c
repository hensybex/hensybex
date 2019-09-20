/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   letter_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medesmon <medesmon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 02:24:36 by medesmon          #+#    #+#             */
/*   Updated: 2019/09/20 19:40:29 by medesmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
#include <stdarg.h>

void	print_str(t_params *p, t_str *str, int *i)
{
	ft_putchar(*str->sval);
	str->sval++;
	p->len++;
	(*i)++;
}

void	parse_string_3(t_params *p, t_str str, int *i)
{
	if (str.xval != NULL)
	{
		if (p->pres)
			while (*str.sval && p->pres--)
				print_str(p, &str, i);
		else
			while (*str.sval)
				print_str(p, &str, i);
	}
	else
	{
		ft_putstr("(null)");
		p->len += 6;
	}
	if (p->width != 0 && str.xval != NULL)
	{
		if ((*i) - p->pres > 0 && p->pres > 0)
			p->len += apply_width(p->width - ft_count_num(str.por)
			- p->pres + 1, str.por, p->zero);
		else
			p->len += apply_width(p->width + 1, str.por, p->zero);
	}
}

void	parse_string_2(t_params *p, t_str str, int *i)
{
	if (p->width != 0 && str.xval != NULL)
	{
		if (*i - p->pres > 0 && p->pres > 0)
			p->len += apply_width(p->width - p->pres
			+ ft_count_num(str.por) + 1, str.por, p->zero);
		else
			p->len += apply_width(p->width + 1, str.por, p->zero);
	}
	if (str.xval != NULL)
	{
		if (p->pres)
			while (*str.sval && p->pres--)
				print_str(p, &str, i);
		else
			while (*str.sval)
				print_str(p, &str, i);
	}
	else
	{
		ft_putstr("(null)");
		p->len += 6;
	}
}

int		ret(t_params *p)
{
	if (p->pres == 0 && p->dot == 1 && p->alt == 0)
	{
		if (p->width != 0)
			p->len += apply_width_16(p->width + 1, 0, p->zero) + p->width - 1;
		return (1);
	}
	return (0);
}

void	parse_string(t_params *p)
{
	t_str	str;
	int		i;

	i = 0;
	if (p->format[p->i] == 's')
	{
		str.sval = va_arg(p->ap, char *);
		str.xval = str.sval;
		if (ret(p))
			return ;
		if (str.xval != NULL)
			while (*str.xval)
			{
				str.xval++;
				i++;
			}
		if (i - p->pres > 0)
			str.por = ft_power(i - p->pres);
		else
			str.por = ft_power(i);
		if (p->left == 0)
			parse_string_2(p, str, &i);
		else
			parse_string_3(p, str, &i);
	}
}
