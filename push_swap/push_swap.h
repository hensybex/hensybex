/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medesmon <medesmon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 04:43:18 by medesmon          #+#    #+#             */
/*   Updated: 2019/09/23 20:13:42 by medesmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define STACK_MAX_SIZE 300
# define FD_MAX_NUM 4864
# define STACK_OVERFLOW  -100
# define STACK_UNDERFLOW -101

# include "./libft/includes/libft.h"
# include <stdarg.h>

int checker(int argc, char **argv);

typedef struct  duo
{
    int max;
    int min;
}               t_duo;

typedef struct  return_params
{
    int     full_len;
    int     position;
}               t_return;

typedef struct Stack {
    int		data[STACK_MAX_SIZE];
    size_t	size;
	int		stack_num;
} Stack_t;

void    push_n(Stack_t *stack, int number, ...);
void	push(Stack_t *stack, int value);
int		pop(Stack_t *stack);
int		pop_n(Stack_t *stack, int n);
int		peek(Stack_t *stack);
void	print_stack(Stack_t *stack);

void    sa(Stack_t *stack);
void    sb(Stack_t *stack);
void	ss(Stack_t *stack1, Stack_t *stack2);
void    pa(Stack_t *stack_from, Stack_t *stack_into);
void    pb(Stack_t *stack_from, Stack_t *stack_into);
void    ra(Stack_t *stack);
void    rb(Stack_t *stack);
void    rr(Stack_t *stack1, Stack_t *stack2);
void    rra(Stack_t *stack);
void    rra(Stack_t *stack);
void    rrb(Stack_t *stack);
void    rrr(Stack_t *stack1, Stack_t *stack2);
void    push_swap(Stack_t *stack1, Stack_t *stack2);
void    push_concrete(Stack_t *stack1, Stack_t *stack2, int i);
int     count_concrete(Stack_t *stack1, Stack_t *stack2, int i);
void    push_final(Stack_t *stack1, Stack_t *stack2, int i);
int     count_out(Stack_t *stack1, int i);
t_duo   find_min_max(Stack_t *stack1);
void    push_3_elems(Stack_t *stack1, Stack_t *stack2, t_duo duo);
void	push_back(Stack_t *stack2, Stack_t *stack1);
void	push_rev(Stack_t *stack, const int value);
int		end();
void	sort_3(Stack_t *stack1, t_duo duo);

#endif
