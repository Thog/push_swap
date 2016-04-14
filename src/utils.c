/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 15:41:05 by tguillem          #+#    #+#             */
/*   Updated: 2016/04/14 15:48:34 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	fill_stack(int ac, int *stack, char **av)
{
	int		i;
	int		j;

	i = 0;
	while (i < ac - 1)
	{
		stack[i] = ft_atoi(av[i + 1]);
		i++;
	}
	i = 0;
	while (i < ac)
	{
		j = i + 1;
		while (j < ac - 1)
		{
			if (stack[i] == stack[j])
			{
				ft_putendl("Duplicate entry. Try with another parameters.");
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int			is_stack_valid(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->a_size - 1)
	{
		if (stack->a[i] < stack->a[i + 1])
			i++;
		else
			return (1);
	}
	return (0);
}

t_stack		*create_stack(int ac, char **av)
{
	int		*stack_a;
	int		*stack_b;
	t_stack	*rest;

	stack_b = NULL;
	stack_a = NULL;
	if (!(stack_a = (int*)ft_memalloc(sizeof(int) * (ac - 1))) ||
			!(stack_b = (int*)ft_memalloc(sizeof(int) * (ac - 1))) ||
			!(rest = (t_stack*)ft_memalloc(sizeof(t_stack)))
			|| !fill_stack(ac, stack_a, av))
		return (NULL);
	rest->a = stack_a;
	rest->b = stack_b;
	rest->a_size = ac - 1;
	rest->b_size = ac - 1;
	rest->top_a = 0;
	rest->top_b = 0;
	rest->count = 0;
	if (!is_stack_valid(rest))
		return (NULL);
	return (rest);
}

int			get_max(t_stack *stack)
{
	int	count;
	int	pos;

	count = stack->top_a + 1;
	pos = stack->top_a;
	while (count < stack->count)
	{
		if (stack->a[pos] < stack->a[count])
			pos = count;
		count++;
	}
	return (pos);
}

int			get_min(t_stack *stack)
{
	int	count;
	int	pos;

	count = stack->top_a + 1;
	pos = stack->top_a;
	while (count < stack->count)
	{
		if (stack->a[pos] > stack->a[count])
			pos = count;
		count++;
	}
	return (pos);
}
