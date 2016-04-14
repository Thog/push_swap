/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 15:40:45 by tguillem          #+#    #+#             */
/*   Updated: 2016/04/14 15:43:46 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	fast_resolve(t_stack *stack)
{
	int	swap_type;

	swap_type = find_best_swap(stack);
	if (swap_type == 1)
		fast_swap_rra(stack);
	else if (swap_type == 2)
		fast_swap_ssr(stack);
	else if (swap_type == 3)
		swap_sa(stack);
	else if (swap_type == 4)
	{
		if (stack->a[stack->a_size - 2] > stack->a[stack->a_size - 1] \
				&& stack->a[stack->a_size - 1] > stack->a[stack->top_a])
			swap_sa(stack);
		else if (stack->a[stack->a_size - 1] < stack->a[stack->a_size - 2])
			swap_ra(stack, (get_min(stack) - 1));
	}
	else
		return (0);
	if (swap_type != 3)
		display_resolved(stack);
	return (1);
}

static void	iterative_resolve(t_stack *stack)
{
	int	count;
	int	length;
	int	swap_type;

	count = 0;
	length = stack->a_size;
	while (count < length)
	{
		swap_type = 0;
		if (((stack->a_size / 2) - 1) > get_max(stack))
			swap_type = 1;
		if (stack->a[stack->a_size - 1] < stack->a[stack->a_size - 2] \
			&& stack->a_size > 1)
			swap_sa(stack);
		if (!swap_type)
			swap_ra(stack, get_max(stack));
		else
			swap_rra(stack, get_max(stack) + 1);
		push_b(stack);
		count++;
	}
	push_a(stack);
}

void		resolve_pushswap(t_stack *stack)
{
	fast_resolve(stack);
	iterative_resolve(stack);
}
