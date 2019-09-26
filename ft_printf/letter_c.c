/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   letter_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgilwood <bgilwood@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 02:26:15 by medesmon          #+#    #+#             */
/*   Updated: 2019/09/26 20:04:29 by bgilwood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
