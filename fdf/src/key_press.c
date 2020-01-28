/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medesmon <medesmon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 07:47:44 by medesmon          #+#    #+#             */
/*   Updated: 2019/11/07 02:21:42 by medesmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		zoom(int key, t_fdf *param)
{
	if (key == 24)
	{
		mlx_clear_window(((t_fdf *)param)->mlx, ((t_fdf *)param)->win);
		((t_fdf *)param)->zoom += 2;
		remake_field(((t_fdf *)param)->len_i,
		((t_fdf *)param)->len_j, ((t_fdf *)param)->matrica, *param);
		draw((param->vertex), *param);
	}
	if (key == 27)
	{
		mlx_clear_window(((t_fdf *)param)->mlx, ((t_fdf *)param)->win);
		((t_fdf *)param)->zoom -= 2;
		remake_field(((t_fdf *)param)->len_i,
		((t_fdf *)param)->len_j, ((t_fdf *)param)->matrica, *param);
		draw((param->vertex), *param);
	}
}

void		move_up_down(int key, t_fdf *param)
{
	if (key == 126)
	{
		mlx_clear_window(((t_fdf *)param)->mlx, ((t_fdf *)param)->win);
		((t_fdf *)param)->move.y -= 20;
		remake_field(((t_fdf *)param)->len_i,
		((t_fdf *)param)->len_j, ((t_fdf *)param)->matrica, *param);
		draw((param->vertex), *param);
	}
	if (key == 125)
	{
		mlx_clear_window(((t_fdf *)param)->mlx, ((t_fdf *)param)->win);
		((t_fdf *)param)->move.y += 20;
		remake_field(((t_fdf *)param)->len_i,
		((t_fdf *)param)->len_j, ((t_fdf *)param)->matrica, *param);
		draw((param->vertex), *param);
	}
}

void		move_left_right(int key, t_fdf *param)
{
	if (key == 123)
	{
		mlx_clear_window(((t_fdf *)param)->mlx, ((t_fdf *)param)->win);
		((t_fdf *)param)->move.x -= 20;
		remake_field(((t_fdf *)param)->len_i,
		((t_fdf *)param)->len_j, ((t_fdf *)param)->matrica, *param);
		draw((param->vertex), *param);
	}
	if (key == 124)
	{
		mlx_clear_window(((t_fdf *)param)->mlx, ((t_fdf *)param)->win);
		((t_fdf *)param)->move.x += 20;
		remake_field(((t_fdf *)param)->len_i,
		((t_fdf *)param)->len_j, ((t_fdf *)param)->matrica, *param);
		draw((param->vertex), *param);
	}
}

void		change_iso(int key, t_fdf *param)
{
	if (key == 35)
	{
		mlx_clear_window(((t_fdf *)param)->mlx, ((t_fdf *)param)->win);
		((t_fdf *)param)->iso *= -1;
		remake_field(((t_fdf *)param)->len_i,
		((t_fdf *)param)->len_j, ((t_fdf *)param)->matrica, *param);
		draw((param->vertex), *param);
	}
}

int			key_press(int key, t_fdf *param)
{
	if (key == 53)
		exit(1);
	zoom(key, param);
	move_left_right(key, param);
	change_iso(key, param);
	move_up_down(key, param);
	if (key == 44)
	{
		mlx_clear_window(((t_fdf *)param)->mlx, ((t_fdf *)param)->win);
		((t_fdf *)param)->move.z += 20;
		remake_field(((t_fdf *)param)->len_i,
		((t_fdf *)param)->len_j, ((t_fdf *)param)->matrica, *param);
		draw((param->vertex), *param);
	}
	if (key == 47)
	{
		mlx_clear_window(((t_fdf *)param)->mlx, ((t_fdf *)param)->win);
		((t_fdf *)param)->move.z -= 20;
		remake_field(((t_fdf *)param)->len_i,
		((t_fdf *)param)->len_j, ((t_fdf *)param)->matrica, *param);
		draw((param->vertex), *param);
	}
	return (0);
}
