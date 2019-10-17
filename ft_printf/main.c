#include <stdio.h>
#include "ft_printf.h"

int	main()
{
	int	a, b;

	a = ft_printf("%f\n", 120.56);
	b = printf("%f\n", 120.56);
	printf("%d\n%d\n", a, b);
	return (0);
}