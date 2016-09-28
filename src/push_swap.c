/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 14:01:50 by tguillem          #+#    #+#             */
/*   Updated: 2016/09/21 16:21:19 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		push_smallest_on_start(t_nlist *stack, t_nlist *other)
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
		if (is_already_sorted(stack) && !other->start)
			return (0);
	}
	return (1);
}

void			resolve_pushswap(t_nlist *a, t_nlist *b)
{
	if (is_already_sorted(a))
	{
		write(1, "\n", 1);
		return ;
	}
	while (a->start != NULL)
	{
		if (!push_smallest_on_start(a, b))
			return ;
		pb(a, b);
	}
	while (b->start != NULL)
		pa(a, b);
}

int				main(int ac, char **av)
{
	return (ft_prgm_base(ac, av, &resolve_pushswap));
}
