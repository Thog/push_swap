/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 15:40:38 by tguillem          #+#    #+#             */
/*   Updated: 2016/04/14 15:44:29 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		print_op(stack, "pa");
	}
	stack->count++;
}

void	push_b(t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	j = stack->b[i];
	while (stack->b[i + 1] != stack->b[stack->b_size - 1])
	{
		stack->b[i] = j;
		j = stack->b[i + 1];
		i++;
	}
	stack->b[0] = stack->a[stack->a_size - 1];
	stack->a_size--;
	print_op(stack, "pb");
	stack->count++;
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
	print_op(stack, "sa");
	stack->count++;
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
			stack->a[j + i] = backup[j];
		j++;
	}
	j = 0;
	while (j < i)
	{
		print_op(stack, "ra");
		stack->count++;
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
			stack->a[j - i] = backup[j];
		j++;
	}
	j = 0;
	while (j < i)
	{
		print_op(stack, "rra");
		stack->count++;
		j++;
	}
}
