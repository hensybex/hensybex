/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medesmon <medesmon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 04:43:18 by medesmon          #+#    #+#             */
/*   Updated: 2019/10/17 17:48:27 by medesmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define MAX_INT 2147483647
# define MIN_INT -2147483648
# define STACK_MAX_SIZE 10000
# define FD_MAX_NUM 4864
# define STACK_OVERFLOW  -100
# define STACK_UNDERFLOW -101

# include "./libft/libft.h"
# include <stdarg.h>

int				checker(int argc, char **argv);

typedef struct	s_duo
{
	int			max;
	int			min;
}				t_duo;

typedef struct	s_return
{
	int			full_len;
	int			position;
}				t_return;

typedef struct	s_stack
{
	int			data[STACK_MAX_SIZE];
	int			size;
	int			stack_num;
}				t_stack;

typedef struct	s_params
{
	int			i;
	char		**line;
	int			k;
	int			fl;
	int			pos;
	t_stack		stack1;
	t_stack		stack2;
}				t_params;

void			push_n(t_stack *stack, int number, ...);
void			push(t_stack *stack, int value);
int				pop(t_stack *stack);
int				pop_n(t_stack *stack, int n);
int				peek(t_stack *stack);
void			print_stack(t_stack *stack);
int				sa(t_stack *stack, int t);
int				sb(t_stack *stack, int t);
int				ss(t_stack *stack1, t_stack *stack2, int t);
int				pa(t_stack *stack_from, t_stack *stack_into, int t);
int				pb(t_stack *stack_from, t_stack *stack_into, int t);
int				ra(t_stack *stack, int t);
int				rb(t_stack *stack, int t);
int				rr(t_stack *stack1, t_stack *stack2, int t);
int				rra(t_stack *stack, int t);
int				rra(t_stack *stack, int t);
int				rrb(t_stack *stack, int t);
int				rrr(t_stack *stack1, t_stack *stack2, int t);
void			push_swap(t_stack *stack1, t_stack *stack2);
void			push_concrete(t_stack *stack1, t_stack *stack2, int i);
int				count_concrete(t_stack *stack1, t_stack *stack2, int i);
void			push_final(t_stack *stack1, t_stack *stack2, int i);
int				count_out(t_stack *stack1, int i);
t_duo			find_min_max(t_stack *stack1);
void			push_3_elems(t_stack *stack1, t_stack *stack2, t_duo duo);
void			push_back(t_stack *stack2, t_stack *stack1);
void			push_rev(t_stack *stack, const int value);
void			sort_3(t_stack *stack1, t_duo duo);
int				check_duplicate(t_stack stack);
int				input_line(char **argv, t_stack **stack);
int				input_lines(char **argv, t_stack **stack);
int				check_commands(char *line, t_stack *stack1, t_stack *stack2);
int				input(int argc, char **argv, t_stack *stack1);
void			init(t_stack *stack1, t_stack *stack2);
int				check_sorted(t_stack stack);
int				print_ko(void);
int				free_end(char **line);
int				ko(t_stack stack1, t_stack stack2);
int				end();
void			rotate_both(int *len_in, int *len_out,
t_stack *stack1, t_stack *stack2);
void			rotate_one(int *len_in, int *len_out,
t_stack *stack1, t_stack *stack2);
void			rotate_one_alt(int *len_in, int *len_out,
t_stack *stack1, t_stack *stack2);
void			sort_final(t_stack *stack1, t_duo duo);
int				free_ret(char **line);
int				free_itoa(char **line, char *new, char **origin);
int				free_ret_1(char **line);
int				free_new(char **origin, int i);

#endif
