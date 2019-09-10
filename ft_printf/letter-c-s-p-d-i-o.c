/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   letter-c-s-p-d-i-o.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medesmon <medesmon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 19:01:12 by medesmon          #+#    #+#             */
/*   Updated: 2019/09/07 17:59:27 by medesmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
#include <stdarg.h>

void    parse_symbol(t_params *p)
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

void    parse_string(t_params *p)
{
    char    *sval;
    char    *xval;
    int     i;
    int     por;

    i = 0;
    if (p->format[p->i] == 's')
    {
        sval = va_arg(p->ap, char *);
        xval = sval;

        if (p->pres == 0 && p->dot == 1 && p->alt == 0)
        {
            if (p->width != 0)
                p->len += apply_width_16(p->width + 1, 0, p->zero) + p->width - 1;
            return ;
        }
        if (xval != NULL)
            while (*xval)
            {
                xval++;
                i++;
            }
        if (i - p->pres > 0)
            por = ft_power(i - p->pres);
        else
            por = ft_power(i);
        if (p->left == 0)
        {
            if (p->width != 0 && xval != NULL)
            {
                if (i - p->pres > 0 && p->pres > 0)
                    p->len += apply_width(p->width - p->pres + ft_count_num(por) + 1, por, p->zero);
                else
                    p->len += apply_width(p->width + 1, por, p->zero);
            }
            if (xval != NULL)
            {
                if (p->pres)
                    while (*sval && p->pres--)
                    {
                        ft_putchar(*sval);
                        sval++;
                        p->len++;
                        i++;
                    }
                else
                    while (*sval)
                    {
                        ft_putchar(*sval);
                        sval++;
                        p->len++;
                        i++;
                    }
            }
            else
            {
                ft_putstr("(null)");
                p->len += 6;
            }
        }
        else
        {
            if (xval != NULL)
            {
                if (p->pres)
                    while (*sval && p->pres--)
                    {
                        ft_putchar(*sval);
                        sval++;
                        p->len++;
                        i++;
                    }
                else
                    while (*sval)
                    {
                        ft_putchar(*sval);
                        sval++;
                        p->len++;
                        i++;
                    }
            }
            else
            {
                ft_putstr("(null)");
                p->len += 6;
            }
            if (p->width != 0 && xval != NULL)
            {
                if (i - p->pres > 0 && p->pres > 0)
                    p->len += apply_width(p->width - ft_count_num(por) - p->pres + 1, por, p->zero);
                else
                    p->len += apply_width(p->width + 1, por, p->zero);
            }
        }
        
    }
}

void    parse_pointer(t_params *p)
{
    int *pval;
    int fl;
    int fl_pres;
    int fl2;

    if (p->format[p->i] == 'p')
    {
        fl = 0;
        fl_pres = 0;
        fl2 = 1;
        pval = va_arg(p->ap, int *);
        if (p->pres > ft_10_to_16_long((long)pval) && (long)pval)
        {
            if (p->pres - ft_10_to_16_long((long)pval) == 1)
                fl_pres = 1;
            else
                fl_pres = 2;
        }
        if ((char)pval != 0)
        {
            fl = 1;
            fl2 = 0;
        }
        if (((long)pval) && p->dot == 0)
            p->width++;
        if (p->left == 0)
            p->len += apply_width(p->width - 2 - ft_10_to_16_long((long)pval) + fl, 0, p->zero);
        ft_putstr("0x");
        if (p->pres == 0 && pval == 0 && p->dot == 1 && p->alt == 0)
        {
            p->len += 2;
            if (p->width != 0)
                p->len += apply_width_16(p->width + 1, 0, p->zero) + p->width - 1;
            return ;
        }
        p->len += apply_pres(p->pres + fl2 + fl_pres - ft_10_to_16_long((long)pval), 1);
        ft_putnbr_hex_long((long)pval);
        p->len += ft_10_to_16_long((long)pval) + 2; // +2 ibo ox
        if (pval == 0)
            p->len++;
        if (p->left == 1)
            p->len += apply_width(p->width - 2 - ft_10_to_16_long((long)pval) + fl, 0, p->zero);
    }
}

void	parse_d_i(t_params *p)
{
	long long int ival;

	if (p->format[p->i] == 'd' || p->format[p->i] == 'i')
	{
		if (p->mod == 2)
			ival = va_arg(p->ap, long long int);
        else if (p->mod == 1)
			ival = va_arg(p->ap, long int);
		else if (p->mod == -1)
			ival = (short)va_arg(p->ap, int);
		else if (p->mod == -2)
			ival = (char)va_arg(p->ap, int);
		else
			ival = va_arg(p->ap, int);
        if (ival == 0 && p->width && p->pres == 0 && p->dot == 0 && p->pos == 0 && p->zero == 0)
        {
            if (p->left == 0)
                p->len += apply_width(p->width, 0, p->zero) + 1;
            ft_putnbr(0);
            if (p->left == 1)
                p->len += apply_width(p->width, 0, p->zero) + 1;
            return ;
        }
        if (ival == 0 && p->pres)
        {
            if (p->width)
                p->len += p->width - p->pres;
            p->len--;
        }
        if ((ival == 0 && p->space == 1) || (p->left == 1 && ival == 0))
        {
            if (p->space == 1)
                ft_putchar(' ');
            p->width--;
            p->len += 2;
        }
        if (p->pres == 0 && ival == 0 && p->dot == 1 && p->alt == 0)
        {
            if (p->width != 0)
                p->len += apply_width_16(p->width + 1, 0, p->zero) + p->width - 1;
            return ;
        }
        if (p->pos == 1 && ival >= 0 && p->zero == 1)
        {
            ft_putchar('+');
            if (ival == 0)
            {
                p->width--;
                p->len++;
            }
            p->len++;
        }
        if ((ival < 0 && p->zero == 1) || ((ival < 0 && p->pres)))
        {
            if (p->left == 0 && p->zero == 0)
            {
                if (p->pres >= ft_count_num(ival))
                    p->width--;
            }
            else
            {
                ft_putchar('-');
                p->len++;
                ival = -ival;
                p->pos = 0;
                p->width--;
            }
        }
		if (p->left == 0 && (p->pres - ft_count_num(ival) > 0))
			p->len += apply_width_long(p->width - p->pos - p->space + 1 - p->pres + ft_count_num(ival), ival, p->zero);
        else if (p->left == 0 && (p->pres - ft_count_num(ival) <= 0))
			p->len += apply_width_long(p->width - p->pos - p->space + 1, ival, p->zero);
        if (p->pos == 1 && ival >= 0 && p->zero == 0)
		{
			ft_putchar('+');
			p->len++;
		}
		else if (p->pos == 0 && ival > 0 && p->space == 1)
		{
			ft_putchar(' ');
			p->len++;
		}
        if (ival == 0 && p->pres)
        {
            p->pres--;
            p->len++;
        }
        if ((ival < 0 && p->pres) && p->left == 0)
        {
            ft_putchar('-');
            p->len++;
            ival = -ival;
            p->pos = 0;
            p->width--;
        }
        p->len += apply_pres(p->pres + 1, ival);
		ft_putnbr(ival);
		if (p->left == 1 && (p->pres - ft_count_num(ival) > 0))
			p->len += apply_width_long(p->width - p->pos + 1 - p->pres + ft_count_num(ival), ival, p->zero);
		else if (p->left == 1 && (p->pres - ft_count_num(ival) <= 0))
			p->len += apply_width_long(p->width - p->pos + 1, ival, p->zero);
        p->len += ft_count_num(ival);
        if (ival == (-9223372036854775807 - 1))
            p->len += 19;
	}
}

void    parse_o(t_params *p)
{
    unsigned long long int  ival;
    char                    *cval;

    if (p->format[p->i] == 'o')
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
			ival = va_arg(p->ap, unsigned int);
        cval = ft_itoa(ival);
        if (p->width < ft_count_num_8(ival) && p->width)
            p->pres--;
        if (p->pres == 0 && ival == 0 && p->dot == 1 && p->alt == 0)
        {
            if (p->width != 0)
                p->len += apply_width_16(p->width + 1, 0, p->zero) + p->width - 1;
            return ;
        }
        if (p->alt == 1 && p->left == 0)
        {
            if (ival != 0)
            {
                if (p->pres - ft_10_to_8_long(ival) > 0 && p->pres)
                    p->len += apply_width_8(p->width - p->pres + ft_10_to_8_long(ival), ival, p->zero) + 1;
                else
                    p->len += apply_width_8(p->width, ival, p->zero) + 1;
                ft_putstr("0");
            }
            else
                p->len += apply_width_8(p->width, ival, p->zero);
            if (p->mod == 2 || p->mod == 1)
            {
                p->len += apply_pres(p->pres, ival);
                ft_putnbr_8_long(ival);
            }
            else
            {
                p->len += apply_pres(p->pres, ival);
                ft_putnbr_8(ival);
            }
        }
        else if (p->alt == 0 && p->left == 0)
        {
            if (p->pres - ft_10_to_8_long(ival) > 0 && p->pres)
                p->len += apply_width_8(p->width - p->pres + ft_10_to_8_long(ival) + 1, ival, p->zero);
            else
                p->len += apply_width_8(p->width + 1, ival, p->zero);
            if (p->mod == 2 || p->mod == 1)
            {
                p->len += apply_pres(p->pres + 1, ival);
                ft_putnbr_8_long(ival);
            }
            else
            {
                p->len += apply_pres(p->pres + 1, ival);
                ft_putnbr_8(ival);
            }
        }
        else if (p->alt == 1 && p->left == 1)
        {
            ft_putstr("0");
            if (p->mod == 2 || p->mod == 1)
            {
                p->len += apply_pres(p->pres + 1, ival);
                ft_putnbr_8_long(ival);
            }
            else
            {
                p->len += apply_pres(p->pres + 1, ival);
                ft_putnbr_8(ival);
            }
            if (ival != 0)
                if (p->pres - ft_10_to_8_long(ival) > 0 && p->pres)
                    p->len += apply_width_8(p->width - p->pres + ft_10_to_8_long(ival), ival, p->zero) + 1;
                else
                    p->len += apply_width_8(p->width, ival, p->zero) + 1;
            else
                p->len += apply_width_8(p->width, ival, p->zero);
        }
        else if (p->alt == 0 && p->left == 1)
        {
            if (p->mod == 2 || p->mod == 1)
            {
                p->len += apply_pres(p->pres + 1, ival);
                ft_putnbr_8_long(ival);
            }
            else
            {
                p->len += apply_pres(p->pres + 1, ival);
                ft_putnbr_8(ival);
            }
            if (p->pres - ft_10_to_8_long(ival) > 0)
                p->len += apply_width_8(p->width - p->pres + ft_10_to_8_long(ival) + 1, ival, p->zero);
            else
                p->len += apply_width_8(p->width + 1, ival, p->zero);
        }
        if (p->mod == 2 || p->mod == 1)
            p->len += ft_10_to_8_long(ival);
        else
            p->len += ft_10_to_8_long(ival);
    }
}