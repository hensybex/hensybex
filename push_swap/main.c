#include <stdio.h>
#include "push_swap.h"
#include <stdarg.h>

int main()
{
    Stack_t stack1;
    Stack_t stack2;

    stack1.size = 0;
    stack2.size = 0;
    stack2.stack_num = 2;
    stack1.stack_num = 1;
    push_n(&stack1, 6, 2, 1, 3, 6, 5, 8);
    print_stack(&stack1);
    print_stack(&stack2);
    push_swap(&stack1, &stack2);
    //push_concrete(&stack1, &stack2, 6);
    print_stack(&stack1);
    print_stack(&stack2);
    return (0);
}