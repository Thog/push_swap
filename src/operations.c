/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 15:40:38 by tguillem          #+#    #+#             */
/*   Updated: 2016/04/19 14:04:26 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rewind_stack(t_stack *stack, int index)
{
	int	distance;

	distance = stack->a_size - 1 - index;
	if (index < distance && index != 0)
	{
		while (index < stack->a_size)
		{
			print_op(stack, "ra");
			++index;
		}
	}
	else
	{
		while (index)
		{
			print_op(stack, "rra");
			--index;
		}
	}
}

void		resolve_pushswap(t_stack *stack)
{
	int		tmp;
	int		index;

	index = 0;
	while (index < (stack->a_size - 1))
	{
		if (stack->a[index + 1] < stack->a[index])
		{
			tmp = stack->a[index];
			stack->a[index] = stack->a[index + 1];
			stack->a[index + 1] = tmp;
			print_op(stack, "sa");
			rewind_stack(stack, index);
			index = -1;
		}
		else
			print_op(stack, "ra");
		++index;
	}
	print_op(stack, "ra");
}
