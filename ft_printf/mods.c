/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mods.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgilwood <bgilwood@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 02:37:52 by medesmon          #+#    #+#             */
/*   Updated: 2019/09/26 20:06:47 by bgilwood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	apply_mod_int(t_params *p, long long int *ival)
{
	if (p->mod == 2)
		*ival = va_arg(p->ap, long long int);
	else if (p->mod == 1)
		*ival = va_arg(p->ap, long int);
	else if (p->mod == -1)
		*ival = (short)va_arg(p->ap, int);
	else if (p->mod == -2)
		*ival = (char)va_arg(p->ap, int);
	else
		*ival = va_arg(p->ap, int);
}

void	apply_mod_uns(t_params *p, unsigned long long int *ival)
{
	if (p->mod == 2)
		*ival = va_arg(p->ap, unsigned long long int);
	else if (p->mod == 1)
		*ival = va_arg(p->ap, unsigned long int);
	else if (p->mod == -1)
		*ival = (unsigned short)va_arg(p->ap, int);
	else if (p->mod == -2)
		*ival = (unsigned char)va_arg(p->ap, int);
	else
		*ival = va_arg(p->ap, unsigned int);
}

int		ret_o(t_params *p, unsigned long long int ival)
{
	if (p->width < ft_count_num_8(ival) && p->width)
		p->pres--;
	if (p->pres == 0 && ival == 0 && p->dot == 1 && p->alt == 0)
	{
		if (p->width != 0)
			p->len += apply_width_16(p->width + 1, 0, p->zero) + p->width - 1;
		return (1);
	}
	return (0);
}

int		ret_hex(t_params *p, unsigned long long ival)
{
	if (p->pres > ft_count_num_16(ival))
		p->fl = p->pres - ft_count_num_16(ival);
	if (p->pres == 0 && ival == 0 && p->dot == 1)
	{
		if (p->width != 0)
			p->len += apply_width_16(p->width + 1, 0, p->zero) + p->width - 1;
		return (1);
	}
	return (0);
}

int		ret_hex_upper(t_params *p, unsigned long long ival)
{
	if (p->pres > ft_count_num_16(ival))
		p->fl = p->pres - ft_count_num_16(ival);
	if (p->pres == 0 && ival == 0 && p->dot == 1)
	{
		if (p->width != 0)
			p->len += apply_width_16(p->width + 1, 0, p->zero) + p->width - 1;
		return (1);
	}
	return (0);
}
