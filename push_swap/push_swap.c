/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medesmon <medesmon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 18:26:52 by medesmon          #+#    #+#             */
/*   Updated: 2019/09/10 21:50:52 by medesmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

void    init(t_params *p)
{
    p->min = 0;
    p->max = 0;
    p->i = 1;
    p->fl = 0;
}

void    push_swap(Stack_t *stack1, Stack_t     *stack2)
{
    t_params    p;
    int         mas[stack1->size];
    int         len;

    init(&p);
    p.min = stack1->data[0];
    p.max = stack1->data[0];
    //найти мин
    while (p.i++ < stack1->size - 1)
    {
        if (stack1->data[p.i] < p.min)
            p.min = stack1->data[p.i];
        if (stack1->data[p.i] > p.max)
            p.max = stack1->data[p.i];
    }
    p.i = 0;
    p.k = 0;
    //оставить 3 цифры
    while (stack1->size >= 4)
    {
        if (p.fl == 0 && (stack1->data[p.i] != p.min && stack1->data[p.i] != p.max))
            p.fl = stack1->data[p.i];
        else if (stack1->data[p.i] != p.min && stack1->data[p.i] != p.max && p.fl != stack1->data[p.i])
        {
            push_concrete(stack1, stack2, p.i + 1);
            p.i = -1;
        }
        p.i++;
    }
    //пред-финал
    while(stack2->size)
    {
        p.i = 0;
        p.min = stack2->size + stack1->size;
        while (p.i < stack2->size)
        {
            p.k = count_concrete(stack2, stack1, p.i + 1);
            if (p.k < p.min)
            {
                p.position = p.i + 1;
                p.min = p.k;
            }
            p.i++;
        }
        push_final(stack2, stack1, p.position);
    }
    
    //финал
    p.i = 0;
    while(p.i < stack1->size)
    {
        if (stack1->data[p.i] == p.max)
            p.position = p.i;
        p.i++;
    }
    if (p.position <= stack1->size / 2)
        while(stack1->data[0] != p.max)
            ra(stack1);
    else
        while(stack1->data[0] != p.max)
            rra(stack1);
}