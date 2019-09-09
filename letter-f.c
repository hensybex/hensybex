/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   letter-f.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medesmon <medesmon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 16:03:55 by medesmon          #+#    #+#             */
/*   Updated: 2019/09/09 19:48:35 by medesmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
#include <stdarg.h>
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

/* int		ft_handle_inf(char **s)
{
	if (!(*s = malloc(sizeof(char) * 4)))
		return (0);
	*s = "inf";
	return (3);
} */

int		ft_put_float_to_string(double nb, char **s, int precision)
{
	int		i;
	int		size;
	char	*str;
	int		neg;
	double	modulo;

	/* if (nb == INFINITY)
		return (ft_handle_inf(s)); */
	size = 1;
	neg = 0;
	if (nb < 0 && size++ && (neg = 1) == 1)
		nb = -nb;
	modulo = ft_calc_modulo(nb, &size);
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

void    parse_f(t_params *p)
{
	char		*nb;
	int			size;
    long double	fval;

    if (p->format[p->i] == 'f')
    {
		if (p->mod == 2 || p->mod == 3 || p->mod == 1)
			fval = va_arg(p->ap, long double);
		else if (p->mod == -1)
			fval = (short)va_arg(p->ap, double);
		else if (p->mod == -2)
			fval = (char)va_arg(p->ap, double);
		else
        	fval = va_arg(p->ap, double);
		if (p->mod == 3)
		{
			printf("%Lf", fval);
			ft_putendl("ERROR");
		}
		if (p->pres <= 0)
            p->pres = 7;
        size = ft_put_float_to_string(fval, &nb, p->pres);
        ft_putstr(nb);
        free(nb);
        p->len += size;
    }
}