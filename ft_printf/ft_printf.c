/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgilwood <bgilwood@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 22:25:37 by medesmon          #+#    #+#             */
/*   Updated: 2019/09/26 20:04:08 by bgilwood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(char *fmt, ...)
{
	t_params	p;

	p.format = (char *)fmt;
	p.i = 0;
	p.len = 0;
	va_start(p.ap, fmt);
	parser(&p);
	va_end(p.ap);
	return (p.len);
}
