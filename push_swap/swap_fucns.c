#include "libft/includes/libft.h"
#include "push_swap.h"

void    sa(Stack_t *stack)
{
    int temp;

    temp = stack->data[stack->size - 1];
    stack->data[stack->size - 1] = stack->data[stack->size - 2];
    stack->data[stack->size - 2] = temp;
    ft_putendl("sa");
}

void    sb(Stack_t *stack)
{
    int temp;

    temp = stack->data[stack->size - 1];
    stack->data[stack->size - 1] = stack->data[stack->size - 2];
    stack->data[stack->size - 2] = temp;
    ft_putendl("sb");
}

void    ss(Stack_t *stack1, Stack_t *stack2)
{
    int temp;

    temp = stack1->data[stack1->size - 1];
    stack1->data[stack1->size - 1] = stack1->data[stack1->size - 2];
    stack1->data[stack1->size - 2] = temp;
    temp = stack2->data[stack2->size - 1];
    stack2->data[stack2->size - 1] = stack2->data[stack2->size - 2];
    stack2->data[stack2->size - 2] = temp;
    ft_putendl("ss");
}

void    pa(Stack_t *stack_from, Stack_t *stack_into)
{
    int temp;

    if (stack_from->size != 0)
    {
        temp = stack_from->data[stack_from->size - 1];
        push(stack_into, temp);
        pop(stack_from);
    }
    ft_putendl("pa");
}

void    pb(Stack_t *stack_from, Stack_t *stack_into)
{
    int temp;

    if (stack_from->size != 0)
    {
        temp = stack_from->data[stack_from->size - 1];
        push(stack_into, temp);
        pop(stack_from);
    }
    ft_putendl("pb");
}

void    ra(Stack_t *stack)
{
    int temp1;
    int temp2;
    int i;

    i = 0;
    temp2 = stack->data[0];
    while (i < stack->size - 1)
    {
        temp1 = stack->data[i];
        stack->data[i] = stack->data[i + 1];
        stack->data[i + 1] = temp1;
        i++;
    }
    stack->data[stack->size - 1] = temp2;
    ft_putendl("ra");
}

void    rb(Stack_t *stack)
{
    int temp1;
    int temp2;
    int i;

    i = 0;
    temp2 = stack->data[0];
    while (i < stack->size - 1)
    {
        temp1 = stack->data[i];
        stack->data[i] = stack->data[i + 1];
        stack->data[i + 1] = temp1;
        i++;
    }
    stack->data[stack->size - 1] = temp2;
    ft_putendl("rb");
}

void    rr(Stack_t *stack1, Stack_t *stack2)
{
    int temp1;
    int temp2;
    int i;

    i = 0;
    temp2 = stack1->data[0];
    while (i < stack1->size - 1)
    {
        temp1 = stack1->data[i];
        stack1->data[i] = stack1->data[i + 1];
        stack1->data[i + 1] = temp1;
        i++;
    }
    stack1->data[stack1->size - 1] = temp2;
    i = 0;
    temp2 = stack2->data[0];
    while (i < stack2->size - 1)
    {
        temp1 = stack2->data[i];
        stack2->data[i] = stack2->data[i + 1];
        stack2->data[i + 1] = temp1;
        i++;
    }
    stack2->data[stack2->size - 1] = temp2;
    ft_putendl("rr");
}

void    rra(Stack_t *stack)
{
    int temp1;
    int temp2;
    int i;

    i = stack->size - 1;
    temp2 = stack->data[stack->size - 1];
    while (i > 0)
    {
        temp1 = stack->data[i];
        stack->data[i] = stack->data[i - 1];
        stack->data[i - 1] = temp1;
        i--;
    }
    stack->data[0] = temp2;
    ft_putendl("rra");
}

void    rrb(Stack_t *stack)
{
    int temp1;
    int temp2;
    int i;

    i = stack->size - 1;
    temp2 = stack->data[stack->size - 1];
    while (i > 0)
    {
        temp1 = stack->data[i];
        stack->data[i] = stack->data[i - 1];
        stack->data[i - 1] = temp1;
        i--;
    }
    stack->data[0] = temp2;
    ft_putendl("rrb");
}

void    rrr(Stack_t *stack1, Stack_t *stack2)
{
    int temp1;
    int temp2;
    int i;

    i = stack1->size - 1;
    temp2 = stack1->data[stack1->size - 1];
    while (i > 0)
    {
        temp1 = stack1->data[i];
        stack1->data[i] = stack1->data[i - 1];
        stack1->data[i - 1] = temp1;
        i--;
    }
    stack1->data[0] = temp2;
    i = stack2->size - 1;
    temp2 = stack2->data[stack2->size - 1];
    while (i > 0)
    {
        temp1 = stack2->data[i];
        stack2->data[i] = stack2->data[i - 1];
        stack2->data[i - 1] = temp1;
        i--;
    }
    stack2->data[0] = temp2;
    ft_putendl("rrr");
}