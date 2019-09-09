/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medesmon <medesmon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 18:47:12 by medesmon          #+#    #+#             */
/*   Updated: 2019/08/24 02:08:51 by medesmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
#include <stdio.h>
#include <stdarg.h>

int  ft_printf(char *fmt, ...)
{
    t_params        p;

    p.format = (char *)fmt;
    p.i = 0;
    p.len = 0;
    va_start(p.ap, fmt);
    parser(&p);
    va_end(p.ap);
    return (p.len);
}