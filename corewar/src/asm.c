#include "../includes/asm.h"

t_parse *init_champ(t_parse *champ)
{
	champ = (t_parse *)malloc(sizeof(t_parse));
	champ->name = NULL;
	champ->comment = NULL;
	champ->list_cmd = NULL;
	champ->error = 0;
	champ->labels = NULL;
	champ->line_num = 1;
	champ->size = 0;
	champ->exec_code = NULL;
	return (champ);
}

void	print_info(t_parse *champ)
{
	t_command	*buff;
	int			i;
	t_labels	*buff_l;

	ft_putstr("\n\n");
	ft_putendl("---------------------------Printing info---------------------------");
	ft_putstr("Name:");
	ft_putendl(champ->name);
	ft_putstr("Comment:");
	ft_putendl(champ->comment);
	buff = champ->list_cmd;
	ft_putchar('\n');
	while (buff != NULL)
	{
		ft_putstr("Command:");
		ft_putendl(g_op[buff->type].name);
		i = 0;
		while (i < 3)
		{
			if (buff->arg[i] != 0)
			{
				ft_putstr("Arg[");
				ft_putnbr(i);
				ft_putstr("]:");
				ft_putendl(buff->arg[i]);
			}
			else
			{
				ft_putstr("Arg[");
				ft_putnbr(i);
				ft_putstr("]:");
				ft_putendl("NULL");
			}
			i++;
		}
		ft_putendl(buff->label);
		ft_putstr("Size of this command is: ");
		ft_putnbr(sizing(buff));
		ft_putstr("\n\n\n");
		buff = buff->next;
	}
	ft_putchar('\n');
	ft_putendl("LABELS:");
	buff_l = champ->labels;
	while (buff_l)
	{
		ft_putendl(buff_l->label);
		buff_l = buff_l->next;
	}
	ft_putendl("---------------------------End of info---------------------------");
	ft_putstr("\n");

}

char    *cor_file(char *filename)
{
    char *str;
    char *buff;

    str = NULL;
    if (ft_strstr(filename, ".s") != NULL && filename[ft_strlen(filename) - 1] && filename[ft_strlen(filename) - 2] && filename[ft_strlen(filename) - 1] == 's' && filename[ft_strlen(filename) - 2] == '.')
    {
        str = ft_strndup(filename, ft_strlen(filename) - 2);
        buff = str;
        str = ft_strjoin(str, ".cor");
        free(buff);
    }
    else
        error("Файл не корректный!", -1);
    return (str);
}

void    memory_clearing(t_parse *champ)
{
    t_command   *buff;
    int         i;

    free(champ->name);
    free(champ->comment);
    free(champ->exec_code);
    while (champ->list_cmd != NULL)
    {
        i = 0;
        while (i < 3)
            free (champ->list_cmd->arg[i++]);
        buff = champ->list_cmd;
        champ->list_cmd = champ->list_cmd->next;
        free(buff);
    }
    free(champ);
}

int		main(int ac, char **av)
{
	t_parse *champ;
	int		fd;
	char	*filename;

	print_program_start
	champ = init_champ(champ);
	if (ac == 2)
		parse(av[1], champ);
	print_info(champ);
	label_conversion(champ);
	/* to_asm_code(champ);
    filename = cor_file(av[1]);
    if ((fd = open(filename, O_CREAT | O_TRUNC | O_WRONLY)) == -1)
        error("Файл не создался!", -1);
    write_bytecode_file(fd, champ);
    free(filename);
    memory_clearing(champ); */
	// проверка на количество входных данных (ac != 0) +
	// считывание && ошибки (+-)
	// перевод в asm - (обработать случаи с интами, начинающимися с 00000)
	// запись в файл -
	// уборка за собой -x
	print_program_end
	return (0);
}
