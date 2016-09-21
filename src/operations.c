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

int			is_already_sorted(t_nlist *stack)
{
	t_node	*node;

	node = stack->start;
	if (stack->start->data == stack->end->data)
		return (1);
	while (node->next != NULL)
	{
		if (node->data > node->next->data)
			return (0);
		node = node->next;
	}
	return (1);
}

void 			push_smallest_on_start(t_nlist *stack)
{
	t_node	*node;
	int		smallest;

	smallest = stack->start->data;
	node = stack->start;
	while (node != NULL)
	{
		if (node->data < smallest)
			smallest = node->data;
		node = node->next;
	}
	while (stack->start->data != smallest)
	{
		ra(stack);
		ft_putchar(' ');
	}
}

void			resolve_pushswap(t_nlist *a, t_nlist *b)
{
	if (is_already_sorted(a))
		return;
	while (a->start != NULL)
	{
		push_smallest_on_start(a);
		pb(a, b);
		ft_putchar(' ');
	}
	while (b->start != NULL)
	{
		pa(a, b);
		ft_putchar(b->start->next ? ' ' : '\n');
	}
}
