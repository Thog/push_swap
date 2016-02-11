/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 14:23:34 by tguillem          #+#    #+#             */
/*   Updated: 2016/02/11 17:35:24 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int			compute_min(t_val *lst)
{
	t_val	*tmp;
	int		result;

	if (!lst)
		return (-666);
	result = lst->value;
	tmp = lst->next;
	while (tmp != lst)
	{
		if (result > tmp->value)
			result = tmp->value;
		tmp = tmp->next;
	}
	return (result);
}

static int			is_sorted(t_val *lst)
{
	int		flag;
	int		prev;
	t_val	*tmp;

	if (!lst)
		return (0);
	flag = 0;
	tmp = lst->prev;
	prev = lst->value;
	while (tmp != lst)
	{
		if (!flag)
			tmp = lst;
		flag = 1;
		if (tmp->value < prev)
			return (0);
		prev = tmp->value;
		tmp = tmp->next;
	}
	return (1);
}

void			push_swap(t_val *stack_a, t_val *stack_b)
{
	int		need_space;
	int		min;
	t_val	*tmp;

	min = compute_min(stack_a);
	need_space = 0;
	while (stack_a && !is_sorted(stack_a))
	{
		if (need_space)
			write(1, " ", 1);
		need_space = 1;
		tmp = stack_a;
		if (tmp->value == min)
		{
			write(1, "pb", 2);
			pushfront(&stack_b, tmp->value);
			pop(&stack_a);
			min = compute_min(stack_a);
		}
		else
			shift(&stack_a);
	}
	clear_val(&stack_a, &stack_b);
}
