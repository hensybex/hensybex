#include "../includes/asm.h"

t_parse *init_champ(t_parse *champ)
{
	champ = (t_parse *)malloc(sizeof(t_parse));
	champ->name = 0;
	champ->comment = 0;
	champ->list_cmd = NULL;
	champ->error = 0;
	champ->labels = NULL;
	champ->line_num = 1;
	return (champ);
}

void	print_info(t_parse *champ)
{
	t_command	*buff;
	int			i;
	t_labels	*buff_l;

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
		ft_putchar('\n');
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
}

int		main(int ac, char **av)
{
	t_parse *champ;

	print_program_start
	champ = init_champ(champ);
	if (ac == 2)
		parse(av[1], champ);
	print_info(champ);
	// проверка на количество входных данных (ac != 0) +
	// считывание && ошибки (+-)
	// перевод в asm - (обработать случаи с интами, начинающимися с 00000)
	// запись в файл -
	// уборка за собой -
	return (0);
}
