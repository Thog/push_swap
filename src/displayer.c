#include "push_swap.h"

void		display_resolved(t_stack *stack)
{
	int		i;

	i = 0;
	while (i < stack->a_size)
	{
		ft_putnbr(stack->a[i]);
		ft_putchar('\n');
		i++;
	}
}
