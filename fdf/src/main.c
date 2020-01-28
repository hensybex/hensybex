/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medesmon <medesmon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 19:44:37 by medesmon          #+#    #+#             */
/*   Updated: 2019/11/07 14:15:15 by medesmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "libft.h"
#include <math.h>
#include <stdio.h>
#include "fdf.h"

void	init_fdf(t_fdf *fdf, t_return_read_file ret)
{
	fdf->len_i = ret.ret_i;
	fdf->len_j = ret.ret_j;
	fdf->zoom = 10;
	fdf->move.x = 0;
	fdf->move.y = 0;
	fdf->move.z = 0;
	fdf->max_i = 2000;
	fdf->max_j = 1200;
	fdf->iso = 1;
}

int		close_window(void *ptr)
{
	exit(0);
	ptr = NULL;
	return (0);
}

void	free_all(t_fdf *fdf)
{
	int	i;
	int	j;

	i = 0;
	while (i < fdf->len_i)
	{
		free(fdf->matrica[i]);
		free(fdf->vertex[i]);
		i++;
	}
}

int		main(int argc, char **argv)
{
	t_return_read_file	ret;
	t_fdf				fdf;

	if (argc != 2)
		return (0);
	ret = read_file(argv, &fdf);
	if (ret.error == -1)
	{
		ft_putendl("Invalid map");
		return (0);
	}
	init_fdf(&fdf, ret);
	fdf.mlx = mlx_init();
	fdf.win = mlx_new_window(fdf.mlx, 2000, 1200, "Fdf");
	fdf.vertex = make_field(fdf.len_i, fdf.len_j, fdf.matrica, fdf);
	draw(fdf.vertex, fdf);
	mlx_hook(fdf.win, 2, 0, key_press, &fdf);
	mlx_hook(fdf.win, 17, 0, close_window, &fdf);
	mlx_loop(fdf.mlx);
	free(fdf.vertex);
	free_all(&fdf);
	return (0);
}
