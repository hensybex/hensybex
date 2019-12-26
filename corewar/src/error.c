#include "../includes/asm.h"

void error(char *error, int line_num)
{
	ft_putstr(error);
	if (line_num != -1)
	{
		ft_putstr(" in line");
		ft_putnbr(line_num);
		ft_putchar('\n');
	}
	exit(1);
}
