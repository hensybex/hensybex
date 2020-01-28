/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medesmon <medesmon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 20:48:16 by medesmon          #+#    #+#             */
/*   Updated: 2019/11/07 15:56:10 by medesmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fdf.h"

void	draw_line(void *mlx_ptr, void *win_ptr, t_line line)
{
	t_koord		error;
	t_koord		delta;
	t_koord		sign;

	delta.x = abs(line.k2.x - line.k1.x);
	delta.y = abs(line.k2.y - line.k1.y);
	sign.x = line.k1.x < line.k2.x ? 1 : -1;
	sign.y = line.k1.y < line.k2.y ? 1 : -1;
	error.x = delta.x - delta.y;
	mlx_pixel_put(mlx_ptr, win_ptr, line.k2.x, line.k2.y, WHITE_COLOUR);
	while (line.k1.x != line.k2.x || line.k1.y != line.k2.y)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, line.k1.x, line.k1.y, WHITE_COLOUR);
		error.y = error.x * 2;
		if (error.y > -delta.y)
		{
			error.x -= delta.y;
			line.k1.x += sign.x;
		}
		if (error.y < delta.x)
		{
			error.x += delta.x;
			line.k1.y += sign.y;
		}
	}
}

t_line	remake_simple_line(int prev_x1, int prev_x2, int prev_y1, int prev_y2)
{
	t_line	line;

	line.k1.x = prev_x1;
	line.k1.y = prev_y1;
	line.k2.x = prev_x2;
	line.k2.y = prev_y2;
	return (line);
}

t_line	rearrange1(t_koord **vertex, int i, int j, t_fdf fdf)
{
	t_line	line;
	t_koord prev1;
	t_koord prev2;

	line.k1 = vertex[i][j];
	line.k2 = vertex[i][j + 1];
	prev1.x = line.k1.x;
	prev2.x = line.k2.x;
	prev1.y = line.k1.y;
	prev2.y = line.k2.y;
	if (fdf.iso == 1)
	{
		line.k1.x = (prev1.x - prev1.y) * cos(0.523599);
		line.k1.y = (prev1.x + prev1.y) * sin(0.523599) - line.k1.z;
		line.k2.x = (prev2.x - prev2.y) * cos(0.523599);
		line.k2.y = (prev2.x + prev2.y) * sin(0.523599) - line.k2.z;
	}
	else
		line = remake_simple_line(prev1.x, prev2.x, prev1.y, prev2.y);
	line.k1.x += (fdf.max_i / 2) + fdf.move.x;
	line.k1.y += (fdf.max_j / 3) + fdf.move.y - 90;
	line.k2.x += (fdf.max_i / 2) + fdf.move.x;
	line.k2.y += (fdf.max_j / 3) + fdf.move.y - 90;
	return (line);
}

t_line	rearrange2(t_koord **vertex, int i, int j, t_fdf fdf)
{
	t_line	line;
	t_koord prev1;
	t_koord prev2;

	line.k1 = vertex[i][j];
	line.k2 = vertex[i + 1][j];
	prev1.x = line.k1.x;
	prev2.x = line.k2.x;
	prev1.y = line.k1.y;
	prev2.y = line.k2.y;
	if (fdf.iso == 1)
	{
		line.k1.x = (prev1.x - prev1.y) * cos(0.523599);
		line.k1.y = (prev1.x + prev1.y) * sin(0.523599) - line.k1.z;
		line.k2.x = (prev2.x - prev2.y) * cos(0.523599);
		line.k2.y = (prev2.x + prev2.y) * sin(0.523599) - line.k2.z;
	}
	else
		line = remake_simple_line(prev1.x, prev2.x, prev1.y, prev2.y);
	line.k1.x += (fdf.max_i / 2) + fdf.move.x;
	line.k1.y += (fdf.max_j / 3) + fdf.move.y - 90;
	line.k2.x += (fdf.max_i / 2) + fdf.move.x;
	line.k2.y += (fdf.max_j / 3) + fdf.move.y - 90;
	return (line);
}

void	draw(t_koord **vertex, t_fdf fdf)
{
	t_line	line;
	int		i;
	int		j;

	i = 0;
	while (i < fdf.len_i)
	{
		j = 0;
		while (j < fdf.len_j)
		{
			if (j < fdf.len_j - 1)
			{
				line = rearrange1(vertex, i, j, fdf);
				draw_line(fdf.mlx, fdf.win, line);
			}
			if (i < fdf.len_i - 1)
			{
				line = rearrange2(vertex, i, j, fdf);
				draw_line(fdf.mlx, fdf.win, line);
			}
			j++;
		}
		i++;
	}
}
