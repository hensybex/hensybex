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

size_t  sizing_line_down(t_command *buff, int location)
{
    size_t  size;
    size_t  i;

	size = 0;
    i = location;
	ft_putstr("\ndown\n");
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
size_t  sizing_line_up(t_command *buff, int location)
{
    size_t  size;
    size_t  i;
    size = 1;
    if (g_op[buff->type].args_types_code)
        size++;
    i = 0;
	ft_putchar('\n');
	ft_putnbr(size);
	ft_putstr("up\n");
    while (i < location)
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
		if ((command->arg[i][1] == LABEL_CHAR && command->arg[i][0] == DIRECT_CHAR) || command->arg[i][0] == LABEL_CHAR)
			return (i);
		i++;
	}
	return (-1);
}

char	*cut_first_two_symbols(char *line)
{
	int	i;
	char	*new_line;

	i = 0;
	new_line = (char *)malloc(sizeof(char) * ft_strlen(line));
	while (i < ft_strlen(line) - 2)
	{
		new_line[i] = line[i + 2];
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
	label_place = find_label(cut_first_two_symbols(command->arg[needed_arg]), champ);
	ft_putnbr(cmd_num);
	ft_putchar(' ');
	ft_putstr(cut_first_two_symbols(command->arg[needed_arg]));
	ft_putchar(' ');
	ft_putnbr(label_place);
	ft_putchar(' ');
	
	if (cmd_num < label_place)
	{
		while (i != cmd_num + 1)
		{
			if (i == cmd_num)
				size += sizing_line_down(buff, needed_arg);
			i++;
			buff = buff->next;
		}
		ft_putnbr(size);
		while (i != label_place - 1)
		{
			size += sizing(buff);
			i++;
			buff = buff->next;
		}
	}
	else
	{
		while (i != label_place - 1)
		{
			i++;
			buff = buff->next;
		}
		ft_putnbr(size);
		while (i != cmd_num)
		{
			size += sizing(buff);
			i++;
			buff = buff->next;
			if (i == label_place)
				size += sizing_line_up(buff, needed_arg);
		}
		size *= -1;
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
			free(buff->arg[needed_arg]);
			buff->arg[needed_arg] = ft_itoa(buff->label_size);
			ft_putstr("Size of label is ");
			ft_putnbr(buff->label_size);
			ft_putchar('\n');
		}
		buff = buff->next;
		i++;
	}
	
	ft_putendl("\n---------------------------End of label conversion---------------------------\n");
}