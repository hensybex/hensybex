/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medesmon <medesmon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 17:01:07 by medesmon          #+#    #+#             */
/*   Updated: 2019/09/09 18:50:53 by medesmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"
#include <stdarg.h>

void    push_n(Stack_t *stack, int number, ...)
{
    int         ival;
    int         i;
    va_list     argptr;

    i = 0;
    va_start(argptr, number);
    while (i++ < number)
    {
        ival = va_arg(argptr, int);
        stack->data[stack->size] = ival;
        stack->size++;
    }
    va_end(argptr);
}

void    push(Stack_t *stack, const int value)
{
    stack->data[stack->size] = value;
    stack->size++;
}

int     pop(Stack_t *stack)
{
    if (stack->size == 0)
        exit(STACK_UNDERFLOW);
    stack->size--;
    return (stack->data[stack->size]);
}

int     pop_n(Stack_t *stack, int n)
{
    int i;

    i = 0;
    while (i++ < n)
        pop(stack);
    return (stack->data[stack->size]);
}

int     peek(Stack_t *stack)
{
    if (stack->size <= 0)
        exit(STACK_UNDERFLOW);
    return stack->data[stack->size - 1];
}
 
void    print_stack(Stack_t *stack)
{
    int i;
    
    i = 0;
    ft_putstr("stack ");
    ft_putnbr(stack->stack_num);
    ft_putstr(" consists of ");
    ft_putnbr(stack->size);
    if (stack->size % 10 == 1)
        ft_putendl(" element");
    else
        ft_putendl(" elements");
    while (i < stack->size)
    {
        ft_putnbr(stack->data[stack->size - i - 1]);
        if (i != stack->size - 1)
            ft_putchar('\n');
        i++;
    }
    printf("\n");
}