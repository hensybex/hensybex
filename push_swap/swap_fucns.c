#include "libft/includes/libft.h"
#include "push_swap.h"

int	sa(Stack_t *stack, int t)
{
	int	temp;

	if (stack->size == 0)
		return (end());
	temp = stack->data[stack->size - 1];
	stack->data[stack->size - 1] = stack->data[stack->size - 2];
	stack->data[stack->size - 2] = temp;
	if (t == 1)
		ft_putendl("sa");
	return (0);
}

int	sb(Stack_t *stack, int t)
{
	int	temp;

	if (stack->size == 0)
		return (end());
	temp = stack->data[stack->size - 1];
	stack->data[stack->size - 1] = stack->data[stack->size - 2];
	stack->data[stack->size - 2] = temp;
	if (t == 1)
		ft_putendl("sb");
	return (0);
}

int	ss(Stack_t *stack1, Stack_t *stack2, int t)
{
	int	temp;

	if (stack1->size == 0 || stack2->size == 0)
		return (end());
	temp = stack1->data[stack1->size - 1];
	stack1->data[stack1->size - 1] = stack1->data[stack1->size - 2];
	stack1->data[stack1->size - 2] = temp;
	temp = stack2->data[stack2->size - 1];
	stack2->data[stack2->size - 1] = stack2->data[stack2->size - 2];
	stack2->data[stack2->size - 2] = temp;
	if (t == 1)
		ft_putendl("ss");
	return (0);
}

int	pa(Stack_t *stack_from, Stack_t *stack_into, int t)
{
	int	temp;

	if (stack_from->size == 0)
		return (end());
	if (stack_from->size != 0)
	{
		temp = stack_from->data[stack_from->size - 1];
		push(stack_into, temp);
		pop(stack_from);
	}
	if (t == 1)
		ft_putendl("pa");
	return (0);
}

int	pb(Stack_t *stack_from, Stack_t *stack_into, int t)
{
	int	temp;

	if (stack_from->size == 0)
		return (end());
	if (stack_from->size != 0)
	{
		temp = stack_from->data[stack_from->size - 1];
		push(stack_into, temp);
		pop(stack_from);
	}
	if (t == 1)
		ft_putendl("pb");
	return (0);
}

int	rra(Stack_t *stack, int t)
{
	int	temp1;
	int	temp2;
	int	i;

	if (stack->size == 0)
		return (end());
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
	if (t == 1)
		ft_putendl("rra");
	return (0);
}

int	rrb(Stack_t *stack, int t)
{
	int	temp1;
	int	temp2;
	int	i;

	if (stack->size == 0)
		return (end());
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
	if (t == 1)
		ft_putendl("rrb");
	return (0);
}

int	rrr(Stack_t *stack1, Stack_t *stack2, int t)
{
	int	temp1;
	int	temp2;
	int	i;

	if (stack1->size == 0 || stack2->size == 0)
		return (end());
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
	if (t == 1)
		ft_putendl("rrr");
	return (0);
}

int	ra(Stack_t *stack, int t)
{
	int	temp1;
	int	temp2;
	int	i;

	if (stack->size == 0)
		return (end());
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
	if (t == 1)
		ft_putendl("ra");
	return (0);
}

int	rb(Stack_t *stack, int t)
{
	int	temp1;
	int	temp2;
	int	i;

	if (stack->size == 0)
		return (end());
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
	if (t == 1)
		ft_putendl("rb");
	return (0);
}

int	rr(Stack_t *stack1, Stack_t *stack2, int t)
{
	int	temp1;
	int	temp2;
	int	i;

	if (stack1->size == 0 || stack2->size == 0)
		return (end());
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
	if (t == 1)
		ft_putendl("rr");
	return (0);
}
