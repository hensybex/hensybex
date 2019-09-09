#include "libft/libft.h"
#include "ft_printf.h"
#include <stdio.h>
#include <stdarg.h>
#include <limits.h>


int main()
{
    int a, b;
    
    //printf("%lo, %lo", 0ul, ULONG_MAX);
    //printf("%llo, %llo", 0llu, ULLONG_MAX);
    //printf("%hu, %hu", 0, USHRT_MAX);
    //printf("%hhu, %hhu", 0, UCHAR_MAX);
    //printf("%hu, %hu", 0, USHRT_MAX);
    a = ft_printf("{%f}{%lf}{%Lf}", 1.42, 1.42, 1.42l);
    printf("\n");
    b = printf("{%f}{%lf}{%Lf}", 1.42, 1.42, 1.42l);
    printf("\n");
    printf("%d %d \n", a, b);
}