/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medesmon <medesmon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 18:47:40 by medesmon          #+#    #+#             */
/*   Updated: 2019/09/08 16:22:01 by medesmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define BUFF_SIZE 100
# define FD_MAX_NUM 4864

# include "./libft/libft.h"
# include <stdarg.h>

int				ft_printf(char *format, ...);
int				apply(int width, int num);

typedef struct	s_params
{
	int			alt;
	int			pos;
	int			width;
	int			pres;
	int			left;
	int			space;
	va_list		ap;
	char		*format;
	char		*fmt_copy;
	size_t		i;
	int			len;
	int			zero;
	int			mod;
	int			dot;
	int			fl;
}				t_params;

void			initialize(t_params *p);
int				symbol_parser(t_params *p);
void			parser(t_params *p);
void			parse_width_pres_persent(t_params *p);
void			parse_flags(t_params *p);
void			parse_csp(t_params *p);
void			parse_symbol(t_params *p);
void			parse_string(t_params *p);
void			parse_pointer(t_params *p);
void			parse_dio(t_params *p);
void			parse_d_i(t_params *p);
void			parse_o(t_params *p);
void			parse_dio(t_params *p);
void			parse_unsigned(t_params *p);
void			parse_hex(t_params *p);
void			parse_hex_upper(t_params *p);
void			parse_uxx(t_params *p);
int				apply_width(int width, int num, int zero);
int				apply_pres(int pres, int num);
int				apply_pres_16(int pres, int num);
void			parse_modifiers(t_params *p);
int				apply_width_long_long(int width, unsigned long long num, int zero);
int 			apply_width_long(int width, long long num, int zero);
int				apply_width_16(int width, unsigned long long num, int zero);
int				apply_width_8(int width, unsigned long long num, int zero);
double			ft_calc_modulo(double nb, int *size);
void			ft_handle_integer(double *nb, char **str, int *i, double modulo);
void			ft_handle_decimals(char **str, int *i, double nb, int precision);
int				ft_put_float_to_string(double nb, char **s, int precision);
void			parse_f(t_params *p);

#endif