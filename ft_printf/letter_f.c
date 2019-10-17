/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   letter_f.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medesmon <medesmon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 03:39:38 by medesmon          #+#    #+#             */
/*   Updated: 2019/09/27 00:20:15 by medesmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

double	ft_calc_modulo(double nb, int *size)
{
	double	modulo;

	modulo = 1;
	while ((int)(nb /= 10) != 0 && (*size)++)
		modulo *= 10;
	return (modulo);
}

void	ft_handle_integer(double *nb, char **str, int *i, double modulo)
{
	char *s;

	
	s = *str;
	while ((int)*nb != 0)
	{
		s[(*i)++] = (char)((*nb / modulo) + 48);
		*nb -= (int)(*nb / modulo) * modulo;
		modulo /= 10;
	}
}

void	ft_handle_decimals(char **str, int *i, double nb, int precision)
{
	int		j;
	int		tmp;
	char	*s;

	nb *= 10;
	j = 0;
	s = *str;
	s[(*i)++] = '.';
	while (j++ < precision)
	{
		if ((int)nb == 0)
		{
			s[(*i)++] = '0';
			continue ;
		}
		tmp = ((int)nb != 9) ? (int)(nb + 0.01) : (int)nb;
		s[(*i)++] = (char)(tmp + 48);
		nb = (nb - tmp) * 10;
	}
}

int		ft_put_float_to_string(double nb, char **s, int precision)
{
	int		i;
	int		size;
	char	*str;
	int		neg;
	double	modulo;

	size = 1;
	neg = 0;
	if (nb < 0 && size++ && (neg = 1) == 1)
		nb = -nb;
	modulo = ft_calc_modulo(nb, &size);
	ft_putnbr(modulo);
	size += precision;
	if (!(str = malloc(sizeof(char) * (size + 1))))
		return (0);
	i = 0;
	if (neg)
		str[i++] = '-';
	ft_handle_integer(&nb, &str, &i, modulo);
	ft_handle_decimals(&str, &i, nb, precision);
	str[--i] = '\0';
	*s = str;
	return (size);
}

void	parse_f(t_params *p)
{
	char		*nb;
	int			size;
	long double	fval;

	if (p->format[p->i] == 'f')
	{
		if (p->mod == 3)
			fval = va_arg(p->ap, long double);
		else
			fval = va_arg(p->ap, double);
		if (p->pres <= 0)
			p->pres = 7;
		size = ft_put_float_to_string(fval, &nb, p->pres);
		ft_putstr(nb);
		free(nb);
		p->len += size;
	}
}
