/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_sols.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timofeykamenetskiy <timofeykamenetskiy@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 15:56:05 by medesmon          #+#    #+#             */
/*   Updated: 2019/10/17 00:16:53 by timofeykame      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

char	*before(char *str)
{
	char	*new;
	int		i;

	i = 0;
	while (str[i] != '-')
		i++;
	new = malloc(sizeof(char) * i);
	i = 0;
	while (str[i] != '-')
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*after(char *str)
{
	char	*new;
	int		i;
	int		j;
	int		k;

	i = 0;
	while (str[i] != '-')
		i++;
	i++;
	j = i;
	while (str[j])
		j++;
	new = malloc(sizeof(char) * (j - i));
	k = 0;
	while (i < j)
	{
		new[k] = str[i];
		i++;
		k++;
	}
	new[k] = '\0';
	return (new);
}

char	*cut(int num, char *str)
{
	int		i;
	int		counter;
	char	*new;
	int		ptr;

	i = 0;
	ptr = 0;
	counter = -1;
	while (counter < num)
	{
		if (str[i] == '-')
		{
			counter++;
			if (counter < num)
				ptr = i + 1;
		}
		i++;
	}
	while (str[i] != '-' && str[i])
		i++;
	new = malloc(sizeof(char) * (i - ptr));
	counter = 0;
	while (ptr < i)
	{
		new[counter] = str[ptr];
		counter++;
		ptr++;
	}
	return (new);
}

int	find_len(char *str)
{
	int	i;
	int	counter;

	counter = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '-')
			counter++;
		i++;
	}
	return (counter);
}

int		match(char *sol1, char *sol2)
{
	int	i;
	int	j;
	int	len1;
	int	len2;

	len1 = find_len(sol1);
	len2 = find_len(sol2);
	i = 0;
	while (i < len1)
	{
		j = 0;
		while (j < len2)
		{
			if ((ft_strcmp(before(cut(i, sol1)), after(cut(j, sol2))) == 0)
			|| (ft_strcmp(after(cut(i, sol1)), before(cut(j, sol2))) == 0))
				return (i);
			j++;
		}
		i++;
	}
	return (-1);	
}

char	*cut_full_before(int num, char *str)
{
	int		i;
	int		counter;
	char	*new;

	i = 0;
	counter = -1;
	while (counter < num - 1)
	{
		if (str[i] == '-')
			counter++;
		i++;
	}
	while (str[i] != '-' && str[i])
		i++;
	new = malloc(sizeof(char) * (i + 1));
	counter = 0;
	while (counter < i + 1)
	{
		new[counter] = str[counter];
		counter++;
	}
	return (new);
}

char	*cut_full_after(int num, char *str)
{
	int		i;
	int		counter;
	char	*new;
	int		ptr;

	i = 0;
	counter = -1;
	while (counter < num)
	{
		if (str[i] == '-')
			counter++;
		i++;
	}
	ptr = i;
	while (str[i])
		i++;
	new = malloc(sizeof(char) * (i - ptr));
	counter = 0;
	while (ptr < i)
	{
		new[counter] = str[ptr];
		counter++;
		ptr++;
	}
	return (new);
}

char	**work_sols(char** solutions, int len)
{
	int		i;
	int		j;
	int		fl;
	int		k;
	char	**new_sols;

	i = -1;
	new_sols = (char **)malloc(sizeof(char *) * 10);
	while (++i < 10)
		new_sols[i] = (char *)malloc(sizeof(char) * 10);
	i = 0;
	k = 0;
	while (i < len - 1)
	{
		if (ft_strcmp(solutions[i], "END") == 0)
			i++;
		else
		{
			fl = 1;
			j = i + 1;
			while (j < len && fl)
			{
				if (ft_strcmp(solutions[j], "END") == 0)
					j++;
				else
				{
					if (match(solutions[i], solutions[j]) != -1)
					{
						fl = 0;
						//remake(solutions[i], solutions[j], match(solutions[i], solutions[j]) + 1, match(solutions[j], solutions[i]) + 1);
						new_sols[k] = ft_strjoin(cut_full_before(match(solutions[i], solutions[j]), solutions[i]),
						cut_full_after(match(solutions[j], solutions[i]) + 1, solutions[j]));
						new_sols[k + 1] = ft_strjoin(cut_full_before(match(solutions[j], solutions[i]), solutions[j]),
						cut_full_after(match(solutions[i], solutions[j]) + 1, solutions[i]));
						k += 2;
						solutions[i] = "END";
						solutions[j] = "END";
						i = -1;
					}
					j++;
				}
			}
			i++;
		}
	}
	new_sols[k] = ft_strdup("\0");
	return (new_sols);
}