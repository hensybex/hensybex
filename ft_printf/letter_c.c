/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   letter_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medesmon <medesmon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 02:26:15 by medesmon          #+#    #+#             */
/*   Updated: 2019/09/20 03:29:11 by medesmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
#include <stdarg.h>

void	parse_symbol(t_params *p)
{
	if (p->format[p->i] == 'c')
	{
		if (p->left == 0)
		{
			p->len += apply_width(p->width, 0, p->zero);
			{
				ft_putchar(va_arg(p->ap, int));
				p->len++;
			}
		}
		else
		{
			{
				ft_putchar(va_arg(p->ap, int));
				p->len++;
			}
			p->len += apply_width(p->width, 0, p->zero);
		}
	}
}
