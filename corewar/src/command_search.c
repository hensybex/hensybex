/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_search.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timofeykamenetskiy <timofeykamenetskiy@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 03:22:21 by medesmon          #+#    #+#             */
/*   Updated: 2020/01/14 18:48:56 by timofeykame      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

t_command	*command_init()
{
	t_command *cmd;

	cmd = (t_command *)malloc(sizeof(t_command));
	cmd->type = -1;
	cmd->arg[0] = 0;
	cmd->arg[1] = 0;
	cmd->arg[2] = 0;
	cmd->next = NULL;
	cmd->label = NULL;
	cmd->arg_num = 0;
	cmd->label_size = 0;
	return (cmd);
}

int		is_whitespace(int c)
{
	return	(c == '\t' ||
			c == '\v' ||
			c == '\f' ||
			c == '\r' ||
			c == ' ');
}

char	 *skip_whitespace(char *line)
{
	while (is_whitespace(*line))
		line++;
	return	(line);
}

char	*skip_command(char *line)
{
	while (!is_whitespace(*line))
		line++;
	return (line);
}

void	add_command(t_command *cmd, t_parse *champ)
{
	t_command *buff;

	if (champ->list_cmd == NULL)
		champ->list_cmd = cmd;
	else
	{
		buff = champ->list_cmd;
		while (buff->next != NULL)
			buff = buff->next;
		buff->next = cmd;
	}
}

void	add_cmd_arg(char *line, t_command *cmd)
{
	int	i;

	i = 0;
	while (cmd->arg[i] != NULL)
		i++;
	cmd->arg[i] = ft_strdup(line);
	cmd->arg_num++;
}

char	*cut_arg(char *line)
{
	char	*new_line;
	int		i;
	int		j;

	i = 0;
	while (line[i] != ' ' && line[i] != '	' && line[i] != '\0' && line[i] != SEPARATOR_CHAR)
		i++;
	new_line = (char *)malloc(sizeof(char) * (i + 1));
	j = 0;
	while (j < i)
	{
		new_line[j] = line[j];
		j++;
	}
	new_line[j] = '\0';
	return (new_line);
}

void	check_label_validity(char *line, t_parse *champ)
{
	int			i;
	t_labels	*buff;
	int			fl;

	fl = 0;
	buff = champ->labels;
	line++;
	while (buff != NULL && fl == 0)
	{
		if (ft_strcmp(buff->label, line) == 0)
			fl = 1;
		buff = buff->next;
	}
	if (fl == 0)
		error("Usage of undeclared label", champ->line_num);
}

char	*is_dir(char *line, t_command *cmd, t_parse *champ)
{
	char	*tmp_line;

	line = skip_whitespace(line);
	tmp_line = cut_arg(line);
	if (tmp_line[0] != DIRECT_CHAR)
		error("Invalid argument [T_DIR]", champ->line_num);
	tmp_line++;
	if (tmp_line[0] == LABEL_CHAR)
		check_label_validity(tmp_line, champ);
	else if (ft_strcmp(ft_itoa(ft_atoi(tmp_line)), tmp_line) != 0)
		error("Invalid argument [T_DIR]", champ->line_num);
	add_cmd_arg(tmp_line, cmd);
	line += ft_strlen(tmp_line) + 1;
	return (line);
}

char	*is_indir(char *line, t_command *cmd, t_parse *champ)
{
	char	*tmp_line;

	line = skip_whitespace(line);
	tmp_line = cut_arg(line);
	if (ft_strcmp(ft_itoa(ft_atoi(tmp_line)), tmp_line) != 0)
		error("Invalid argument [T_IND]", champ->line_num);
	add_cmd_arg(tmp_line, cmd);
	line += ft_strlen(tmp_line);
	return (line);
}

char	*is_reg(char *line, t_command *cmd, t_parse *champ)
{
	char	*tmp_line;

	line = skip_whitespace(line);
	tmp_line = cut_arg(line);
	if (tmp_line[0] != 'r')
		error("Letter r missing in [T_REG]", champ->line_num);
	tmp_line++;
	if (ft_strcmp(ft_itoa(ft_atoi(tmp_line)), tmp_line) != 0)
		error("Invalid argument [T_REG]", champ->line_num);
	if (ft_atoi(tmp_line) > REG_NUMBER)
		error("Reg number beyound limit!", champ->line_num);
	tmp_line--;
	add_cmd_arg(tmp_line, cmd);
	line += ft_strlen(tmp_line);
	return (line);
}

char	*is_regindir(char *line, t_command *cmd, t_parse *champ)
{
	char	*tmp_line;

	line = skip_whitespace(line);
	tmp_line = cut_arg(line);
	if (tmp_line[0] != 'r')
	{
		if (ft_strcmp(ft_itoa(ft_atoi(tmp_line)), tmp_line) != 0)
			error("Invalid aargument [T_REG/T_IND]", champ->line_num);
	}
	else
	{
		tmp_line++;
		if (ft_atoi(tmp_line) > REG_NUMBER)
			error("Reg number beyound limit", champ->line_num);
		if (ft_strcmp(ft_itoa(ft_atoi(tmp_line)), tmp_line) != 0)
			error("Invalid argument [T_REG/T_IND]", champ->line_num);
		tmp_line--;
	}
	add_cmd_arg(tmp_line, cmd);
	line += ft_strlen(tmp_line);
	return (line);
}

char	*is_regdir(char *line, t_command *cmd, t_parse *champ)
{
	char	*tmp_line;

	line = skip_whitespace(line);
	tmp_line = cut_arg(line);
	if (tmp_line[0] == 'r' || tmp_line[0] == DIRECT_CHAR)
	{
		tmp_line++;
		if (line[0] == 'r' && ft_atoi(tmp_line) > REG_NUMBER)
			error("Reg number beyound limit", champ->line_num);
		if (ft_strcmp(ft_itoa(ft_atoi(tmp_line)), tmp_line) != 0)
			error("Invalid argument [T_REG/T_DIR]", champ->line_num);
		tmp_line--;
	}
	else
		error("Invalid argument [T_REG/T_DIR]", champ->line_num);
	add_cmd_arg(tmp_line, cmd);
	line += ft_strlen(tmp_line);
	return (line);
}

char	*is_dirindir(char *line, t_command *cmd, t_parse *champ)
{
	char	*tmp_line;

	line = skip_whitespace(line);
	tmp_line = cut_arg(line);
	if (tmp_line[0] != DIRECT_CHAR)
	{
		if (ft_strcmp(ft_itoa(ft_atoi(tmp_line)), tmp_line) != 0)
			error("Invalid argument [T_IND/T_DIR]", champ->line_num);
	}
	else
	{
		tmp_line++;
		if (ft_strcmp(ft_itoa(ft_atoi(tmp_line)), tmp_line) != 0)
			error("Invalid argument [T_IND/T_DIR]", champ->line_num);
		tmp_line--;
	}
	add_cmd_arg(tmp_line, cmd);
	line += ft_strlen(tmp_line);
	return (line);
}

char	*is_any(char *line, t_command *cmd, t_parse *champ)
{
	char	*tmp_line;

	line = skip_whitespace(line);
	tmp_line = cut_arg(line);
	if (tmp_line[0] == DIRECT_CHAR || tmp_line[0] == 'r')
	{
		tmp_line++;
		if (line[0] == 'r' && ft_atoi(tmp_line) > REG_NUMBER)
			error("Reg number beyound limit", champ->line_num);
		if (ft_strcmp(ft_itoa(ft_atoi(tmp_line)), tmp_line) != 0)
			error("Invalid argument [T_REG/T_DIR/T_IND]", champ->line_num);
		tmp_line--;
	}
	else
	{
		if (ft_strcmp(ft_itoa(ft_atoi(tmp_line)), tmp_line) != 0)
			error("Invalid aargument [T_REG/T_DIR/T_IND]", champ->line_num);
	}
	add_cmd_arg(tmp_line, cmd);
	line += ft_strlen(tmp_line);
	return (line);
}

char	*find_separator(char *line, int line_num)
{
	int	i;

	line = skip_whitespace(line);
	if (line[0] != SEPARATOR_CHAR)
		error("Separator char missing or invalid", line_num);
	line++;
	return (line);
}

void	check_live(t_command *cmd, char *line, t_parse *champ)
{
	line += 4;
	line = is_dir(line, cmd, champ);
	line = skip_whitespace(line);
	if (line[0] != '\0')
		error("Symbols after argument in live command", champ->line_num);
	add_command(cmd, champ);
}

void	check_ld(t_command *cmd, char *line, t_parse *champ)
{
	line += 2;
	line = is_dirindir(line, cmd, champ);
	line = find_separator(line, champ->line_num);
	line = is_reg(line, cmd, champ);
	line = skip_whitespace(line);
	if (line[0] != '\0')
		error("Symbols after argument in ld command", champ->line_num);
	add_command(cmd, champ);
}

void	check_st(t_command *cmd, char *line, t_parse *champ)
{
	line += 2;
	line = is_reg(line, cmd, champ);
	line = find_separator(line, champ->line_num);
	line = is_regindir(line, cmd, champ);
	line = skip_whitespace(line);
	if (line[0] != '\0')
		error("Symbols after argument in st command", champ->line_num);
	add_command(cmd, champ);
}

void	check_add(t_command *cmd, char *line, t_parse *champ)
{
	line += 3;
	line = is_reg(line, cmd, champ);
	line = find_separator(line, champ->line_num);
	line = is_reg(line, cmd, champ);
	line = find_separator(line, champ->line_num);
	line = is_reg(line, cmd, champ);
	line = skip_whitespace(line);
	if (line[0] != '\0')
		error("Symbols after argument in add command", champ->line_num);
	add_command(cmd, champ);
}

void	check_sub(t_command *cmd, char *line, t_parse *champ)
{
	line += 3;
	line = is_reg(line, cmd, champ);
	line = find_separator(line, champ->line_num);
	line = is_reg(line, cmd, champ);
	line = find_separator(line, champ->line_num);
	line = is_reg(line, cmd, champ);
	line = skip_whitespace(line);
	if (line[0] != '\0')
		error("Symbols after argument in sub command", champ->line_num);
	add_command(cmd, champ);
}

void	check_and(t_command *cmd, char *line, t_parse *champ)
{
	line += 3;
	line = is_any(line, cmd, champ);
	line = find_separator(line, champ->line_num);
	line = is_any(line, cmd, champ);
	line = find_separator(line, champ->line_num);
	line = is_reg(line, cmd, champ);
	line = skip_whitespace(line);
	if (line[0] != '\0')
		error("Symbols after argument in and command", champ->line_num);
	add_command(cmd, champ);
}

void	check_or(t_command *cmd, char *line, t_parse *champ)
{
	line += 2;
	line = is_any(line, cmd, champ);
	line = find_separator(line, champ->line_num);
	line = is_any(line, cmd, champ);
	line = find_separator(line, champ->line_num);
	line = is_reg(line, cmd, champ);
	line = skip_whitespace(line);
	if (line[0] != '\0')
		error("Symbols after argument in or command", champ->line_num);
	add_command(cmd, champ);
}

void	check_xor(t_command *cmd, char *line, t_parse *champ)
{
	line += 3;
	line = is_any(line, cmd, champ);
	line = find_separator(line, champ->line_num);
	line = is_any(line, cmd, champ);
	line = find_separator(line, champ->line_num);
	line = is_reg(line, cmd, champ);
	line = skip_whitespace(line);
	if (line[0] != '\0')
		error("Symbols after argument in xor command", champ->line_num);
	add_command(cmd, champ);
}

void	check_zjmp(t_command *cmd, char *line, t_parse *champ)
{
	line += 4;
	line = is_dir(line, cmd, champ);
	line = skip_whitespace(line);
	if (line[0] != '\0')
		error("Symbols after argument in zjmp command", champ->line_num);
	add_command(cmd, champ);
}

void	check_ldi(t_command *cmd, char *line, t_parse *champ)
{
	line += 3;
	line = is_any(line, cmd, champ);
	line = find_separator(line, champ->line_num);
	line = is_regdir(line, cmd, champ);
	line = find_separator(line, champ->line_num);
	line = is_reg(line, cmd, champ);
	line = skip_whitespace(line);
	if (line[0] != '\0')
		error("Symbols after argument in ldi command", champ->line_num);
	add_command(cmd, champ);
}

void	check_sti(t_command *cmd, char *line, t_parse *champ)
{
	line += 3;
	line = is_reg(line, cmd, champ);
	line = find_separator(line, champ->line_num);
	line = is_any(line, cmd, champ);
	line = find_separator(line, champ->line_num);
	line = is_regdir(line, cmd, champ);
	line = skip_whitespace(line);
	if (line[0] != '\0')
		error("Symbols after argument in sti command", champ->line_num);
	add_command(cmd, champ);
}

void	check_fork(t_command *cmd, char *line, t_parse *champ)
{
	line += 4;
	line = is_dir(line, cmd, champ);
	line = skip_whitespace(line);
	if (line[0] != '\0')
		error("Symbols after argument in fork command", champ->line_num);
	add_command(cmd, champ);
}

void	check_lld(t_command *cmd, char *line, t_parse *champ)
{
	line += 3;
	line = is_dirindir(line, cmd, champ);
	line = find_separator(line, champ->line_num);
	line = is_reg(line, cmd, champ);
	line = skip_whitespace(line);
	if (line[0] != '\0')
		error("Symbols after argument in lld command", champ->line_num);
	add_command(cmd, champ);
}

void	check_lldi(t_command *cmd, char *line, t_parse *champ)
{
	line += 4;
	line = is_any(line, cmd, champ);
	line = find_separator(line, champ->line_num);
	line = is_regdir(line, cmd, champ);
	line = find_separator(line, champ->line_num);
	line = is_reg(line, cmd, champ);
	line = skip_whitespace(line);
	if (line[0] != '\0')
		error("Symbols after argument in lldi command", champ->line_num);
	add_command(cmd, champ);
}

void	check_lfork(t_command *cmd, char *line, t_parse *champ)
{
	line += 5;
	line = is_dir(line, cmd, champ);
	line = skip_whitespace(line);
	if (line[0] != '\0')
		error("Symbols after argument in lfork command", champ->line_num);
	add_command(cmd, champ);
}

void	check_aff(t_command *cmd, char *line, t_parse *champ)
{
	line += 3;
	line = is_reg(line, cmd, champ);
	line = skip_whitespace(line);
	if (line[0] != '\0')
		error("Symbols after argument in aff command", champ->line_num);
	add_command(cmd, champ);
}

void	check_command(t_command *cmd, char *line, t_parse *champ)
{
	if (cmd->type == 0)
		check_live(cmd, line, champ);
	else if (cmd->type == 1)
		check_ld(cmd, line, champ);
	else if (cmd->type == 2)
		check_st(cmd, line, champ);
	else if (cmd->type == 3)
		check_add(cmd, line, champ);
	else if (cmd->type == 4)
		check_sub(cmd, line, champ);
	else if (cmd->type == 5)
		check_and(cmd, line, champ);
	else if (cmd->type == 6)
		check_or(cmd, line, champ);
	else if (cmd->type == 7)
		check_xor(cmd, line, champ);
	else if (cmd->type == 8)
		check_zjmp(cmd, line, champ);
	else if (cmd->type == 9)
		check_ldi(cmd, line, champ);
	else if (cmd->type == 10)
		check_sti(cmd, line, champ);
	else if (cmd->type == 11)
		check_fork(cmd, line, champ);
	else if (cmd->type == 12)
		check_lld(cmd, line, champ);
	else if (cmd->type == 13)
		check_lldi(cmd, line, champ);
	else if (cmd->type == 14)
		check_lfork(cmd, line, champ);
	else if (cmd->type == 15)
		check_aff(cmd, line, champ);
	else
	{
		ft_putnbr(cmd->type);
		error("Eta comanda mnoyu eshe ne obrabotana :(", champ->line_num);
	}
}

char	*cut_command(char *line)
{
	char	*command;
	int		i;
	int		j;

	i = 0;
	while (line[i] != '%' && line[i] != '\t' && line[i] != '\v' && line[i] != '\f' && line[i] != '\r' && line[i] != ' '  && line[i] != '\0')
		i++;
	j = 0;
	command = (char *)malloc(sizeof(char) * i);
	while (j < i)
	{
		command[j] = line[j];
		j++;
	}
	command[j] = '\0';
	return (command);
}

void	command_search(char *line, t_parse *champ, char *label)
{
	int			i;
	int			j;
	t_command	*cmd;

	if (line[0] != '\0')
	{
		cmd = command_init();
		line = skip_whitespace(line);
		i = 0;
		while (ft_strcmp(cut_command(line), g_op[i].name) != 0 && i < 16)
			i++;
		if (i == 16)
			error("Undefined command", champ->line_num);
		cmd->type = i;
		check_command(cmd, line, champ);
		if (label != NULL)
			cmd->label = ft_strdup(label);
	}
}

/* void	command_search(char *line, t_parse *champ)
{
	int			i;
	int			j;
	t_command	*cmd;

	cmd = command_init();
	line = skip_whitespace(line);
	i = 0;
	while (!ft_strstr(line, g_op[i].name) && i < 16)
		i++;
	if (i == 16)
		error("Undefined command!");
	cmd->type = i;
	ft_putnbr(i);
	ft_putendl(line);
	line = skip_command(line);
	i = 0;
	while (i != g_op[cmd->type].args_num)
	{
		line = skip_whitespace(line);
		j = 0;
		while (line[j] != '\0' && line[j] != SEPARATOR_CHAR && !is_whitespace(line[j]))
			j++;
		cmd->arg[i] = ft_strndup(line, j);
		line += j;
		if (*line == SEPARATOR_CHAR)
			line++;
		i++;
	}
	add_command(cmd, champ);
} */