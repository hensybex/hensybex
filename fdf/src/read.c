/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medesmon <medesmon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 23:05:44 by medesmon          #+#    #+#             */
/*   Updated: 2019/11/07 16:07:10 by medesmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "get_next_line.h"
#include <fcntl.h>

int					check_line(char *line, t_return_read_file ret)
{
	int	j;
	int	k;

	j = 0;
	k = 0;
	while (line[j])
	{
		if (!((line[j] >= '0' && line[j] <= '9') || (line[j + 1] &&
		line[j] == '-' && line[j + 1] >= '0'
		&& line[j + 1] <= '9')) && line[j] != ' ' && line[j] != ',')
		{
			ret.error = -1;
			return (-1);
		}
		k++;
		while (line[j] && line[j] != ' ')
			j++;
		while (line[j] && line[j] == ' ')
			j++;
	}
	return (k);
}

int					get_hw(t_return_read_file *ret, int fd)
{
	int		i;
	char	*line;
	int		k;
	int		check_k;

	i = 0;
	line = NULL;
	while ((ret->error = get_next_line(fd, &line)))
	{
		if (return_error(&line, *ret) == -1)
			return (-1);
		k = check_line(line, *ret);
		if (k == -1)
			remake_ret_error(&line, ret);
		if (i == 0)
			check_k = k;
		else if (k != check_k)
			remake_ret_error(&line, ret);
		i++;
		free(line);
	}
	ret->ret_i = i;
	ret->ret_j = k;
	return (0);
}

void				make_table(char **argv, int fd,
int **table, t_return_read_file *ret)
{
	char	*line;
	int		i;
	int		j;
	int		k;

	i = 0;
	fd = open(argv[1], 0);
	while (get_next_line(fd, &line))
	{
		j = 0;
		if (line[j] == '\0')
			ret->error = -1;
		k = 0;
		while (line[j])
		{
			table[i][k] = ft_atoi(&line[j]);
			k++;
			while (line[j] && line[j] != ' ')
				j++;
			while (line[j] && line[j] == ' ')
				j++;
		}
		i++;
		free(line);
	}
}

t_return_read_file	read_file(char **argv, t_fdf *fdf)
{
	t_return_read_file	ret;
	int					fd;
	int					i;

	fd = open(argv[1], 0);
	ret.error = 0;
	if (get_hw(&ret, fd) == -1)
		return (ret);
	if (ret.ret_i == 0 || ret.ret_j == 0)
	{
		ret.error = -1;
		return (ret);
	}
	fd = open(argv[1], 0);
	fdf->matrica = (int **)malloc(sizeof(int *) * ret.ret_i);
	i = -1;
	while (++i < ret.ret_i)
		fdf->matrica[i] = (int *)malloc(sizeof(int) * ret.ret_j);
	make_table(argv, fd, fdf->matrica, &ret);
	close(fd);
	return (ret);
}
