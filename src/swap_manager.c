/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 15:40:58 by tguillem          #+#    #+#             */
/*   Updated: 2016/04/14 15:45:30 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		backward_diff(t_stack *stack, int type)
{
	int	i;

	i = 0;
	if (type == 0)
	{
		if (stack->a[stack->a_size - 1] > stack->a[stack->a_size - 2])
			return (0);
	}
	else if (stack->a[0] < stack->a[1])
		return (0);
	while (i < stack->a_size - 1)
	{
		if (stack->a[i] < stack->a[i + 1])
			i++;
		else
			return (0);
	}
	return (1);
}

int				find_best_swap(t_stack *stack)
{
	if (stack->a_size == 3)
		return (1);
	else if (backward_diff(stack, 0) == 1)
		return (2);
	else if (backward_diff(stack, 1) == 1)
		return (3);
	else if (((stack->a_size / 2) - 2) < stack->a[get_min(stack)])
		return (0);
	else if (stack->a_size == 2)
		return (4);
	return (0);
}
