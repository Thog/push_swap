#include "push_swap.h"

void	fast_swap_rra(t_stack *stack)
{
	if (stack->a[0] > stack->a[stack->a_size - 1])
		swap_rra(stack, 1);
	else if (stack->a[0] < stack->a[stack->a_size - 1] && \
			stack->a[0] > stack->a[stack->a_size - 2])
	{
		swap_rra(stack, 1);
		swap_sa(stack);
	}
	else
	{
		swap_rra(stack, 2);
		swap_sa(stack);
		swap_ra(stack, get_max(stack) - 1);
	}
}

void fast_swap_ssr(t_stack *stack)
{
	if (!is_stack_valid(stack))
		return;
	if (stack->a[0] > stack->a[1] && stack->a[1] > stack->a[2])
	{
		swap_sa(stack);
		swap_ra(stack, 0);
	}
	else if (stack->a[0] < stack->a[1] && stack->a[1] > stack->a[0] && \
			stack->a[0] > stack->a[2])
		swap_ra(stack, get_max(stack));
	else if (stack->a[0] < stack->a[1] && stack->a[1] > stack->a[0] && \
			stack->a[0] > stack->a[2])
		swap_ra(stack, get_max(stack));
	else if (stack->a[0] < stack->a[1] && stack->a[1] > stack->a[0] && \
			stack->a[0] < stack->a[2])
		swap_sa(stack);
	else
	{
		swap_sa(stack);
		swap_ra(stack, get_max(stack));
	}
}
