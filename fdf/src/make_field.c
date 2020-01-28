/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_field.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medesmon <medesmon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 23:05:14 by medesmon          #+#    #+#             */
/*   Updated: 2019/11/07 15:38:26 by medesmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_koord	**make_field(int len_i, int len_j, int **matr, t_fdf fdf)
{
	t_koord	**vertex;
	int		i;
	int		j;

	vertex = (t_koord **)malloc(sizeof(t_koord *) * len_i);
	i = -1;
	while (++i < len_i)
		vertex[i] = (t_koord *)malloc(sizeof(t_koord) * len_j);
	i = 0;
	while (i < len_i)
	{
		j = 0;
		while (j < len_j)
		{
			vertex[i][j].x = i * fdf.zoom * fdf.max_i / fdf.len_i / 30;
			vertex[i][j].y = j * fdf.zoom * fdf.max_i / fdf.len_i / 30;
			vertex[i][j].z = matr[i][len_j - j - 1]
			* fdf.zoom * fdf.max_i / fdf.len_i / 90;
			j++;
		}
		i++;
	}
	return (vertex);
}

void	remake_field(int len_i, int len_j, int **matr, t_fdf fdf)
{
	int		i;
	int		j;

	i = 0;
	while (i < len_i)
	{
		j = 0;
		while (j < len_j)
		{
			fdf.vertex[i][j].x = i * fdf.zoom * fdf.max_i / fdf.len_i / 30;
			fdf.vertex[i][j].y = j * fdf.zoom * fdf.max_i / fdf.len_i / 30;
			fdf.vertex[i][j].z = matr[i][len_j - j - 1]
			* fdf.zoom / 3 * fdf.max_i / fdf.len_i / 30;
			j++;
		}
		i++;
	}
}
