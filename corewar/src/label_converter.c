/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   label_converter.c								  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: timofeykamenetskiy <timofeykamenetskiy@	+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2020/01/14 15:20:16 by timofeykame	   #+#	#+#			 */
/*   Updated: 2020/01/14 15:20:59 by timofeykame	  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "../includes/asm.h"

size_t  sizing(t_command *buff)
{
	size_t  size;
	size_t  i;
	size = 1;
	if (g_op[buff->type].args_types_code)
		size++;
	i = 0;
	while (i < 3)
	{
		if (buff->arg[i])
		{
			if (*(buff->arg[i]) == 'r')
				size++;
			else if (*(buff->arg[i]) == DIRECT_CHAR)
				size += g_op[buff->type].t_dir_size;
			else
				size += 2;
		}
		i++;
	}
	return (size);
}

int		label_in_arg(t_command *command)
{
	int	i;

	i = 0;
	while (i < command->arg_num)
	{
		if (command->arg[i][0] == LABEL_CHAR)
			return (i);
		i++;
	}
	return (-1);
}

char	*cut_first_symbol(char *line)
{
	int	i;
	char	*new_line;

	i = 0;
	new_line = (char *)malloc(sizeof(char) * (ft_strlen(line) + 1));
	while (i < ft_strlen(line) - 1)
	{
		new_line[i] = line[i + 1];
		i++;
	}
	new_line[i] = '\0';
	return (new_line);
}

int		find_label(char *arg, t_parse *champ)
{
	t_command	*buff;
	int			i;
	int			fl;

	fl = 0;
	i = 0;
	buff = champ->list_cmd;
	while (buff != NULL && fl == 0)
	{
		if (buff->label != NULL && ft_strcmp(arg, buff->label) == 0)
			fl = 1;
		i++;
		buff = buff->next;
	}
	return (i);
}

size_t	calculate_sizing(t_parse *champ, t_command *command, int cmd_num, int needed_arg)
{
	int			label_place;
	t_command	*buff;
	size_t		size;
	int			i;

	i = 0;
	size = 0;
	buff = champ->list_cmd;
	label_place = find_label(cut_first_symbol(command->arg[needed_arg]), champ);
	ft_putnbr(cmd_num);
	ft_putchar(' ');
	ft_putstr(cut_first_symbol(command->arg[needed_arg]));
	ft_putchar(' ');
	ft_putnbr(label_place);
	ft_putchar(' ');
	
	if (cmd_num < label_place)
	{
		while (i != cmd_num)
		{
			i++;
			buff = buff->next;
		}
		while (i != label_place)
		{
			size += sizing(buff);
			i++;
			buff = buff->next;
		}
	}
	else
	{
		while (i != label_place)
		{
			i++;
			buff = buff->next;
		}
		while (i != cmd_num)
		{
			size += sizing(buff);
			i++;
			buff = buff->next;
		}
	}
	ft_putchar('\n');
	return (size);
}

void	label_conversion(t_parse *champ)
{
	t_command	*buff;
	int			i;
	int			needed_arg;

	ft_putendl("\n---------------------------Conversing labels---------------------------");
	buff = champ->list_cmd;
	i = 0;
	while (buff != NULL)
	{
		if ((needed_arg = label_in_arg(buff)) != -1)
		{
			buff->label_size = calculate_sizing(champ, buff, i, needed_arg);
			ft_putstr("Size of label is ");
			ft_putnbr(buff->label_size);
			ft_putchar('\n');
		}
		buff = buff->next;
		i++;
	}
	
	ft_putendl("\n---------------------------End of label conversion---------------------------\n");
}