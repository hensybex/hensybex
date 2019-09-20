/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medesmon <medesmon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 22:25:37 by medesmon          #+#    #+#             */
/*   Updated: 2019/09/19 22:25:42 by medesmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
#include <stdio.h>
#include <stdarg.h>

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
