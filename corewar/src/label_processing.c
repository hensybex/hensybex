/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label_processing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medesmon <medesmon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 05:29:28 by medesmon          #+#    #+#             */
/*   Updated: 2019/12/25 05:55:13 by medesmon         ###   ########.fr       */
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

void	label_processing(char *line, int fd, t_parse *champ)
{
	char	*buff;
	int		i;

	buff = ft_strchr(line, LABEL_CHAR) + 1;
	buff = skip_whitespace(buff);
	while (is_empty(buff) && get_next_line(fd, &line) > 0)
		buff = ft_strjoin(buff, line);
	command_search(buff, champ, cut_label(line));
}