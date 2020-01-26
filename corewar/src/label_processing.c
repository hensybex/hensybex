/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label_processing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medesmon <medesmon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 05:29:28 by medesmon          #+#    #+#             */
/*   Updated: 2020/01/26 21:15:13 by medesmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int		is_label(char *line)
{
	int	i;

	line = skip_whitespace(line);
	i = 0;
	while (line[i] != LABEL_CHAR && line[i] && line[i] != ' ')
		i++;
	if (line[i - 1] == DIRECT_CHAR && line[i] == LABEL_CHAR)
		return (0);
	else if (line[i] == LABEL_CHAR)
		return (1);
	else
		return (0);
}

int		is_empty(char *line)
{
	int	i;

	line = skip_whitespace(line);
	if (line == '\0')
		return (1);
	else
		return (0);
}

char	*pass_label(char *str)
{
	int		i;
	int		j;
	char	*new_str;

	i = 0;
	while (str[i] != LABEL_CHAR)
		i++;
	i++;
	new_str = (char *)malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	j = 0;
	while (str[i])
	{
		new_str[j] = str[i];
		i++;
		j++;
	}
	new_str[j] = '\0';
	return (new_str);
}

t_labels	*add_label_row(char *line, t_labels *labels_row)
{
	t_labels	*buff;
	char		*tmp;

	if (labels_row == NULL)
	{
		labels_row = (t_labels *)malloc(sizeof(t_labels));
		labels_row->label = ft_strdup(cut_label(line));
		labels_row->next = NULL;
	}
	else
	{
		buff = labels_row;
		while (buff->next != NULL)
			buff = buff->next;
		buff->next = (t_labels *)malloc(sizeof(t_labels));
		buff->next->label = ft_strdup(cut_label(line));
		buff->next->next = NULL;
	}
	return (labels_row);
}

void	label_processing(char *line, int fd, t_parse *champ)
{
	char		*buff;
	int			i;
	t_labels	*labels_row;

	labels_row = NULL;
	buff = ft_strchr(line, LABEL_CHAR) + 1;
	labels_row = add_label_row(line, labels_row);
	if (labels_row == NULL)
		print_error
	while ((is_empty(buff) || buff[0] == '\0') && get_next_line(fd, &line) > 0)
	{
		buff = ft_strjoin(buff, line);
		champ->line_num++;
		if (is_label(buff))
		{
			labels_row = add_label_row(buff, labels_row);
			buff = pass_label(buff);
		}
	}
	command_search(cut_comment(buff), champ, labels_row);
}
