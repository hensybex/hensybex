/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medesmon <medesmon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 19:04:41 by medesmon          #+#    #+#             */
/*   Updated: 2019/09/07 16:50:32 by medesmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
#include <stdio.h>
#include <stdarg.h>

int apply_width(int width, int num, int zero)
{
    int temp;
    int counter;

    counter = 0;
    temp = width - ft_count_num(num) - 1;
    while (temp-- > 0)
    {
        if (zero == 0)
            ft_putchar(' ');
        else
            ft_putchar('0');
        counter++;
    }
    return (counter);
}

int apply_pres(int pres, int num)
{
    int temp;
    int counter;

    counter = 0;
    temp = pres - ft_count_num(num) - 1;
    while (temp-- > 0)
    {
        ft_putchar('0');
        counter++;
    }
    return (counter);
}

int apply_pres_16(int pres, int num)
{
    int temp;
    int counter;

    counter = 0;
    temp = pres - ft_count_num_16(num) - 1;
    while (temp-- > 0)
    {
        ft_putchar('0');
        counter++;
    }
    return (counter);
}

int  apply_width_long_long(int width, unsigned long long num, int zero)
{
    int temp;
    int counter;

    counter = 0;
    temp = width - ft_count_num_long_long(num) - 1;
    while (temp-- > 0)
    {
        if (zero == 0)
            ft_putchar(' ');
        else
            ft_putchar('0');
        counter++;
    }
    if (num == 0)
        counter = 1;
    return (counter);
}

int apply_width_long(int width, long long num, int zero)
{
    int temp;
    int counter;

    counter = 0;
    temp = width - ft_count_num_long(num) - 1;
    while (temp-- > 0)
    {
        if (zero == 0)
            ft_putchar(' ');
        else
            ft_putchar('0');
        counter++;
    }
    if (num == 0)
        counter = 1;
    return (counter);
}

int apply_width_16(int width, unsigned long long num, int zero)
{
    int temp;
    int counter;

    counter = 0;
    temp = width - ft_count_num_16(num) - 1;
    while (temp-- > 0)
    {
        if (zero == 0)
            ft_putchar(' ');
        else
            ft_putchar('0');
        counter++;
    }
    if (num == 0)
        counter = 1;
    return (counter);
}

int apply_width_8(int width, unsigned long long num, int zero)
{
    int temp;
    int counter;

    counter = 0;
    temp = width - ft_count_num_8(num) - 1;
    while (temp-- > 0)
    {
        if (zero == 0)
            ft_putchar(' ');
        else
            ft_putchar('0');
        counter++;
    }
    if (num == 0)
        counter = 1;
    return (counter);
}