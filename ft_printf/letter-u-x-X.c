/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   letter-u-x-X.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medesmon <medesmon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 20:42:15 by medesmon          #+#    #+#             */
/*   Updated: 2019/09/06 18:50:21 by medesmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
#include <stdarg.h>

void    parse_unsigned(t_params *p)
{
    unsigned long long  ival;

    if (p->format[p->i] == 'u') //ансайнед инт
    {
        if (p->mod == 2)
			ival = va_arg(p->ap, unsigned long long int);
        else if (p->mod == 1)
			ival = va_arg(p->ap, unsigned long int);
		else if (p->mod == -1)
			ival = (unsigned short)va_arg(p->ap, unsigned int);
		else if (p->mod == -2)
			ival = (unsigned char)va_arg(p->ap, unsigned int);
		else
			ival = va_arg(p->ap, unsigned int);
        if (p->pres == 0 && ival == 0 && p->dot == 1 && p->alt == 0)
        {
            if (p->width != 0)
                p->len += apply_width_16(p->width + 1, 0, p->zero) + p->width - 1;
            return ;
        }
        if (p->pres > ft_count_num(ival))
            p->fl = p->pres - ft_count_num(ival);
        if (p->left == 0)
        {
            p->len += apply_width_long_long(p->width + 1 - p->fl, ival, p->zero);
            p->len += apply_pres(p->pres + 1, ival);
        }
        if (p->mod == -1)
		    ft_putnbr_uns(ival);
		else if (p->mod == -2)
			ft_putnbr_uns(ival);
        else
        ft_putnbr_BIG(ival);
        p->len += ft_count_num_long_long(ival);
        if (p->left == 1)
        {
            p->len += apply_width_long_long(p->width + 1 - p->fl, ival, p->zero);
            p->len += apply_pres(p->pres + 1, ival);
        }
    }
}

void    parse_hex(t_params *p)
{
    unsigned long long  ival;
    char                *cval;

    if (p->format[p->i] == 'x') //шестнадцатеричное, нижний
    {
        if (p->mod == 2)
			ival = va_arg(p->ap, unsigned long long int);
		else if (p->mod == 1)
			ival = va_arg(p->ap, unsigned long int);
		else if (p->mod == -1)
			ival = (unsigned short)va_arg(p->ap, int);
		else if (p->mod == -2)
			ival = (unsigned char)va_arg(p->ap, int);
		else
			ival = va_arg(p->ap, int);
        if (p->pres > ft_count_num_16(ival))
            p->fl = p->pres - ft_count_num_16(ival);
        if (p->pres == 0 && ival == 0 && p->dot == 1)
        {
            if (p->width != 0)
                p->len += apply_width_16(p->width + 1, 0, p->zero) + p->width - 1;
            return ;
        }
        cval = ft_itoa(ival);
        if (p->alt == 1 && p->left == 0)
        {
            if (ival != 0)
            {
                if (p->zero == 1)
                    ft_putstr("0x");
                if (p->mod == 0)
                    p->len += apply_width_16(p->width - 1 - p->fl, ival, p->zero) + 2;
                else
                    p->len += apply_width_16(p->width - 1 - p->fl, ival, p->zero) + 2;
                if (p->zero == 0)
                    ft_putstr("0x");
            }
            else
            {
                if (p->mod == 0)
                    p->len += apply_width_16(p->width - p->fl, ival, p->zero);
                else
                    p->len += apply_width_16(p->width - p->fl, ival, p->zero);
            }
            p->len += apply_pres_16(p->pres + 1, ival);
            if (p->mod == 2 || p->mod == 1)
                ft_putnbr_hex_long(ival);
            else
                ft_putnbr_hex(ival);
        }
        else if (p->alt == 0 && p->left == 0)
        {
            if (p->mod == 0)
                p->len += apply_width_16(p->width + 1 - p->fl, ival, p->zero);
            else
                p->len += apply_width_16(p->width + 1 - p->fl, ival, p->zero);
            p->len += apply_pres_16(p->pres + 1, ival);
            if (p->mod == 2 || p->mod == 1)
                ft_putnbr_hex_long(ival);
            else
                ft_putnbr_hex(ival);
        }
        else if (p->alt == 1 && p->left == 1)
        {
            ft_putstr("0x");
            p->len += apply_pres_16(p->pres + 1, ival);
            if (p->mod == 2 || p->mod == 1)
                ft_putnbr_hex_long(ival);
            else
                ft_putnbr_hex(ival);
            if (ival != 0)
                if (p->mod == 0)
                    p->len += apply_width_16(p->width - 1 - p->fl, ival, 0) + 2;
                else
                    p->len += apply_width_16(p->width - 1 - p->fl, ival, 0) + 2;
            else
                if (p->mod == 0)
                    p->len += apply_width_16(p->width - p->fl, ival, p->zero);
                else
                    p->len += apply_width_16(p->width - p->fl, ival, p->zero);
        }
        else if (p->alt == 0 && p->left == 1)
        {
            p->len += apply_pres_16(p->pres + 1, ival);
            if (p->mod == 2 || p->mod == 1)
                ft_putnbr_hex_long(ival);
            else
                ft_putnbr_hex(ival);
            if (p->mod == 0)
                p->len += apply_width_16(p->width + 1 - p->fl, ival, p->zero);
            else
                p->len += apply_width_16(p->width + 1 - p->fl, ival, p->zero);
        }
        if (p->mod == 2 || p->mod == 1)
            p->len += ft_10_to_16_long(ival);
        else
            p->len += ft_10_to_16(ival);
    }
}

void    parse_hex_upper(t_params *p)
{
    unsigned long long  ival;
    char                *cval;

    if (p->format[p->i] == 'X') //шестнадцатеричное, верхний
    {
        if (p->mod == 2)
			ival = va_arg(p->ap, unsigned long long int);
		else if (p->mod == 1)
			ival = va_arg(p->ap, unsigned long int);
		else if (p->mod == -1)
			ival = (unsigned short)va_arg(p->ap, int);
		else if (p->mod == -2)
			ival = (unsigned char)va_arg(p->ap, int);
		else
			ival = va_arg(p->ap, int);
        if (p->pres > ft_count_num_16(ival))
            p->fl = p->pres - ft_count_num_16(ival);
        if (p->pres == 0 && ival == 0 && p->dot == 1)
        {
            if (p->width != 0)
                p->len += apply_width_16(p->width + 1, 0, p->zero) + p->width - 1;
            return ;
        }
        cval = ft_itoa(ival);
        if (p->alt == 1 && p->left == 0)
        {
            if (ival != 0)
            {
                if (p->zero == 1)
                    ft_putstr("0X");
                if (p->mod == 0)
                    p->len += apply_width_16(p->width - 1 - p->fl, ival, p->zero) + 2;
                else
                    p->len += apply_width_16(p->width - 1 - p->fl, ival, p->zero) + 2;
                if (p->zero == 0)
                    ft_putstr("0X");
            }
            else
            {
                if (p->mod == 0)
                    p->len += apply_width_16(p->width - p->fl, ival, p->zero);
                else
                    p->len += apply_width_16(p->width - p->fl, ival, p->zero);
            }
            p->len += apply_pres_16(p->pres + 1, ival);
            if (p->mod == 2 || p->mod == 1)
                ft_putnbr_hex_long_upper(ival);
            else
                ft_putnbr_hex_upper(ival);
        }
        else if (p->alt == 0 && p->left == 0)
        {
            if (p->mod == 0)
                p->len += apply_width_16(p->width + 1 - p->fl, ival, p->zero);
            else
                p->len += apply_width_16(p->width + 1 - p->fl, ival, p->zero);
            p->len += apply_pres_16(p->pres + 1, ival);
            if (p->mod == 2 || p->mod == 1)
                ft_putnbr_hex_long_upper(ival);
            else
                ft_putnbr_hex_upper(ival);
        }
        else if (p->alt == 1 && p->left == 1)
        {
            ft_putstr("0X");
            p->len += apply_pres_16(p->pres + 1, ival);
            if (p->mod == 2 || p->mod == 1)
                ft_putnbr_hex_long_upper(ival);
            else
                ft_putnbr_hex_upper(ival);
            if (ival != 0)
                if (p->mod == 0)
                    p->len += apply_width_16(p->width - 1 - p->fl, ival, 0) + 2;
                else
                    p->len += apply_width_16(p->width - 1 - p->fl, ival, 0) + 2;
            else
                if (p->mod == 0)
                    p->len += apply_width_16(p->width - p->fl, ival, p->zero);
                else
                    p->len += apply_width_16(p->width - p->fl, ival, p->zero);
        }
        else if (p->alt == 0 && p->left == 1)
        {
            p->len += apply_pres_16(p->pres + 1, ival);
            if (p->mod == 2 || p->mod == 1)
                ft_putnbr_hex_long_upper(ival);
            else
                ft_putnbr_hex_upper(ival);
            if (p->mod == 0)
                p->len += apply_width_16(p->width + 1 - p->fl, ival, p->zero);
            else
                p->len += apply_width_16(p->width + 1 - p->fl, ival, p->zero);
        }
        if (p->mod == 2 || p->mod == 1)
            p->len += ft_10_to_16_long(ival);
        else
            p->len += ft_10_to_16(ival);
    }
}