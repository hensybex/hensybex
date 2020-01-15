/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label_search.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timofeykamenetskiy <timofeykamenetskiy@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 03:54:36 by medesmon          #+#    #+#             */
/*   Updated: 2020/01/14 16:22:54 by timofeykame      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	check_label_symbol(char symbol, int line_num)
{
	int	i;
	int	fl;

	fl = 0;
	i = 0;
	while (i < 37 && fl == 0)
	{
		if (symbol == LABEL_CHARS[i])
			fl = 1;
		i++;
	}
	if (fl == 0)
		error("Undefined label symbol", line_num);
}

void	check_label_symbols(char *line, int line_num)
{
	int	i;

	i = 0;
	while (line[i] != LABEL_CHAR)
	{
		check_label_symbol(line[i], line_num);
		i++;
	}
}

void	check_exception(char *line, int line_num)
{
	int	i;

	i = 0;
	while (!ft_strstr(line, g_op[i].name) && i < 16)
		i++;
	if (i == 16)
		error("Undefined label symbol", line_num);
}

char	*cut_label(char *str)
{
	int		i;
	char	*new_str;

	i = 0;
	while (str[i] != LABEL_CHAR)
		i++;
	new_str = (char *)malloc(sizeof(char) * i);
	i = 0;
	while (str[i] != LABEL_CHAR)
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

void	add_label(char *line, t_parse *champ)
{
	t_labels *buff;

	if (champ->labels == NULL)
	{
		champ->labels = (t_labels *)malloc(sizeof(t_labels));
		champ->labels->label = ft_strdup(cut_label(line));
		champ->labels->next = NULL;
	}
	else
	{
		buff = champ->labels;
		while (buff->next != NULL)
			buff = buff->next;
		buff->next = (t_labels *)malloc(sizeof(t_labels));
		buff->next->label = ft_strdup(cut_label(line));
		buff->next->next = NULL;
	}
}

void	label_search(char *line, t_parse *champ, int fd)
{
	int	i;

	line = skip_whitespace(line);
	i = 0;
	while (line[i] != LABEL_CHAR && line[i] && line[i] != ' ')
		i++;
	if (line[i - 1] == DIRECT_CHAR && line[i] == LABEL_CHAR)
		check_exception(line, champ->line_num);
	else if (line[i] == LABEL_CHAR)
	{
		check_label_symbols(line, champ->line_num);
		add_label(line, champ);
	}
}
