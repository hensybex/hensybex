/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medesmon <medesmon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 03:20:48 by medesmon          #+#    #+#             */
/*   Updated: 2020/01/17 18:33:06 by medesmon         ###   ########.fr       */
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

void	line_processing(char *line, t_parse *champ, int fd)
{
	if (ft_strstr(line, NAME_CMD_STRING))
		name_search(line, champ, fd);
	else if (ft_strstr(line, COMMENT_CMD_STRING))
		comment_search(line, champ, fd);
	else if (is_label(line))
		label_processing(line, fd, champ);
	else
		command_search(line, champ, NULL);
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
	if (counter != 1)
		error("Wrong amount of empty lines at the end of file", -1);
}

void	parse(char *file, t_parse *champ)
{
	int		fd;
	char	*line;

	if ((fd = open(file, O_RDONLY)) == -1)
		error("Cannot open file", -1);
	check_last_symbols(file, fd);
	fd = open(file, O_RDONLY);
	champ->last_symbol = 0;
	while (get_next_line(fd, &line) > 0)
	{
		//ft_putnbr(champ->line_num);
		//ft_putchar(' ');
		label_search(line, champ, fd);
		free(line);
		champ->line_num++;
		//check_last_symbol(line, champ);
		//ft_putendl(line);
	}
	//if (champ->last_symbol == 1 || )
	champ->line_num = 1;
	fd = open(file, O_RDWR | O_APPEND);
	while (get_next_line(fd, &line) > 0)
	{
		line_processing(line, champ, fd);
		free(line);
		champ->line_num++;
		/* if (i == 0)
		{
			ft_putendl(buff);
			if (buff == '\0')
				ft_putendl("ZBS");
			else
				ft_putendl("GOVNO");
			break;
		}
		else
		{
			if (buff)
				free(buff);
			buff = line;
		} */
	}
	
	if (champ->name == NULL || champ->comment == NULL)
		error("Undefined parsing error", champ->line_num);
}