/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medesmon <medesmon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 20:04:43 by medesmon          #+#    #+#             */
/*   Updated: 2019/11/07 16:07:37 by medesmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft.h"
# include <math.h>
# include "mlx.h"
# define RED_COLOUR 0xFF0000
# define WHITE_COLOUR 0xFFFFFF
# define YELLOW_COLOUR 0xFFFF00

typedef struct		s_move
{
	int				x;
	int				y;
	int				z;
}					t_move;

typedef struct		s_koord
{
	int				x;
	int				y;
	int				z;
}					t_koord;

typedef struct		s_fdf
{
	void			*mlx;
	void			*win;
	int				len_i;
	int				len_j;
	int				**matrica;
	int				zoom;
	t_move			move;
	int				pos_x;
	int				pos_y;
	int				max_i;
	int				max_j;
	t_koord			**vertex;
	int				iso;
}					t_fdf;

typedef struct		s_line
{
	t_koord			k1;
	t_koord			k2;
	int				len_i;
	int				len_j;
}					t_line;

typedef struct		s_return_read_file
{
	int				ret_i;
	int				ret_j;
	int				error;
}					t_return_read_file;

t_return_read_file	read_file(char **argv, t_fdf *fdf);

t_koord				**make_field(int i, int j, int **matr, t_fdf fdf);

void				remake_field(int len_i, int len_j, int **matr, t_fdf fdf);

int					key_press(int key, t_fdf *param);

int					mouse_press(int button, int x, int y, void *param);

int					mouse_release(int button, int x, int y, void *param);

int					mouse_move(int x, int y, void *param);

void				draw(t_koord **vertex, t_fdf fdf);

void				draw_line(void *mlx_ptr, void *win_ptr, t_line line);

t_line				rearrange1(t_koord **vertex, int i, int j, t_fdf fdf);

t_line				rearrange2(t_koord **vertex, int i, int j, t_fdf fdf);

void				draw_blue_line(void *mlx_ptr, void *win_ptr, t_line line);

int					remake_ret_error(char **line, t_return_read_file *ret);

int					return_error(char **line, t_return_read_file ret);

#endif
