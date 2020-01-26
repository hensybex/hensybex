/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medesmon <medesmon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 03:20:48 by medesmon          #+#    #+#             */
/*   Updated: 2020/01/26 21:22:54 by medesmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	name_search(char *line, t_parse *champ, int fd)
{
	int i;
	char *buff;

	if (champ->name != NULL)
		error("Double name", champ->line_num);
	buff = ft_strstr(line, NAME_CMD_STRING) + ft_strlen(NAME_CMD_STRING);
	i = 0;
	while (buff[i] != '"')
	{
		if (buff[i] != ' ' && buff[i] != '	')
		{
			if (buff[i] == '\0')
				error("Name missing", champ->line_num);
			else
				error("Smth before name", champ->line_num);
		}
		i++;
	}
	buff = ft_strchr(line, '"');
	buff++;
	while (ft_strchr(buff, '"') == NULL && get_next_line(fd, &line) > 0)
		buff = ft_strjoin(buff, line);
	if (ft_strchr(buff, '"') == NULL)
		error("Quotation mark after name missing", champ->line_num);
	i = 0;
	while (buff[i] != '"')
		i++;
	champ->name = ft_strndup(buff, i);
	if (i > PROG_NAME_LENGTH)
		error("Name length beyound limit", champ->line_num);
	if (buff[i + 1] != '\0')
		error("Simbols after name", champ->line_num);
}

void	comment_search(char *line, t_parse *champ, int fd)
{
	int i;
	char *buff;

	if (champ->comment != NULL)
		error("Double comment", champ->line_num);
	buff = ft_strstr(line, COMMENT_CMD_STRING) + ft_strlen(COMMENT_CMD_STRING);
	i = 0;
	while (buff[i] != '"')
	{
		if (buff[i] != ' ' && buff[i] != '	')
		{
			if (buff[i] == '\0')
				error("Comment missing", champ->line_num);
			else
				error("Smth before comment", champ->line_num);
		}
		i++;
	}
	buff = ft_strchr(line, '"');
	buff++;
	while (ft_strchr(buff, '"') == NULL && get_next_line(fd, &line) > 0)
		buff = ft_strjoin(buff, line);
	if (ft_strchr(buff, '"') == NULL)
		error("Quotation mark after comment missing", champ->line_num);
	i = 0;
	while (buff[i] != '"')
		i++;
	champ->comment = ft_strndup(buff, i);
	if (i > COMMENT_LENGTH)
		error("Comment length beyound limits", champ->line_num);
	if (buff[i + 1] != '\0')
		error("Simbols after comment", champ->line_num);
}

char	*cut_before(char *str, int place)
{
	int		i;
	char	*new_str;

	i = 0;
	new_str = (char *)malloc(sizeof(char) * place);
	while (i < place)
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

char	*cut_comment(char *line)
{
	int	i;
	int	fl;
	int	place;

	i = 0;
	fl = 0;
	while (line[i] && fl == 0)
	{
		if (line[i] == COMMENT_CHAR || line[i] == ALT_COMMENT_CHAR)
		{
			fl = 1;
			place = i;
		}
		i++;
	}
	if (fl == 0)
		return (line);
	else
		return(cut_before(line, place));
}

void	line_processing(char *line, t_parse *champ, int fd)
{
	char	*new_line;

	if (line[0] == COMMENT_CHAR || line[0] == ALT_COMMENT_CHAR)
		return ;
	new_line = ft_strdup(cut_comment(line));
	if (ft_strstr(new_line, NAME_CMD_STRING))
		name_search(new_line, champ, fd);
	else if (ft_strstr(new_line, COMMENT_CMD_STRING))
		comment_search(new_line, champ, fd);
	else if (is_label(new_line))
		label_processing(new_line, fd, champ);
	else
		command_search(new_line, champ, NULL);
}

void	check_last_symbols(char *file, int fd)
{
	char	*line;
	int		i;
	char	buff[2];
	int		counter;

	line = (char *)malloc(sizeof(char) * 1);
	line[0] = '\0';
	while ((i = read(fd, buff, 1)) > 0)
		line = ft_strjoin(line, buff);
	i = 0;
	while (line[i])
		i++;
	i--;
	counter = 0;
	while (line[i] == '\n')
	{
		counter++;
		i--;
	}
	if (counter == 0)
		error("Wrong amount of empty lines at the end of file", -1);
}

void	parse(char *file, t_parse *champ)
{
	int		fd;
	char	*line;

	if ((fd = open(file, O_RDONLY)) == -1)
		error("Cannot open file", -1);
	check_last_symbols(file, fd); // проверка \n в последней строке!!!
	fd = open(file, O_RDONLY);
	champ->last_symbol = 0;
	while (get_next_line(fd, &line) > 0)
	{
		label_search(line, champ, fd);
		free(line);
		champ->line_num++;
	}
	champ->line_num = 1;
	fd = open(file, O_RDWR | O_APPEND);
	while (get_next_line(fd, &line) > 0)
	{
		line_processing(line, champ, fd);
		free(line);
		champ->line_num++;
	}
	
	if (champ->name == NULL || champ->comment == NULL)
		error("Undefined parsing error", champ->line_num);
	close(fd);
}
