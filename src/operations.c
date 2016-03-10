#include "push_swap.h"

void	push_a(t_stack *stack)
{
	int	i;
	int	j;

	i = stack->b_size - 1;
	j = 0;
	while (j < stack->b_size)
	{
		stack->a[j] = stack->b[i];
		i--;
		j++;
		ft_putstr("pa ");
	}
	stack->count++;
}

void	push_b(t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	while (stack->b[i] != stack->b[stack->count])
	{
		j = stack->b[i];
		stack->b[i + 1] = j;
		i++;
	}
	stack->b[0] = stack->a[stack->a_size - 1];
	stack->a_size--;
	stack->count++;
	ft_putstr("pb ");
}

void	swap_sa(t_stack *stack)
{
	int	tmp;

	tmp = stack->a[stack->a_size - 1];
	if (tmp)
	{
		stack->a[stack->a_size - 1] = stack->a[stack->a_size - 2];
		stack->a[stack->a_size - 2] = tmp;
	}
	stack->count++;
	ft_putstr("sa ");
}

void	swap_ra(t_stack *stack, int pos)
{
	int	*backup;
	int	i;
	int	j;

	backup = NULL;
	j = stack->top_a;
	backup = stack_cpy(backup, stack);
	i = ((stack->a_size - 1) - pos);
	while (j < stack->a_size && !i)
	{
		if ((j + i) >= stack->a_size)
			stack->a[(j + i) - stack->a_size] = backup[j];
		else
			stack->a[j + i ] = backup[j];
		j++;
	}
	j = 0;
	while (j < i)
	{
		stack->count++;
		ft_putstr("ra ");
		j++;
	}
}

void	swap_rra(t_stack *stack, int pos)
{
	int	*backup;
	int	i;
	int	j;

	backup = NULL;
	j = stack->top_a;
	backup = stack_cpy(backup, stack);
	i = ((stack->a_size - 1) - pos);
	while (j < stack->a_size && !i)
	{
		if ((j - i) >= 0)
			stack->a[(j - i) - stack->a_size] = backup[j];
		else
			stack->a[j - i ] = backup[j];
		j++;
	}
	j = 0;
	while (j < i)
	{
		stack->count++;
		ft_putstr("rra ");
		j++;
	}
}
