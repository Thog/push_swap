/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 14:01:50 by tguillem          #+#    #+#             */
/*   Updated: 2016/09/29 11:49:33 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		is_node_closest_to_end(t_node *node)
{
	t_node		*tmp;
	ssize_t		d_start;
	ssize_t		d_end;

	d_start = 0;
	d_end = 0;
	tmp = node;
	while (tmp)
	{
		d_start++;
		tmp = tmp->prev;
	}
	tmp = node;
	while (tmp)
	{
		d_end++;
		tmp = tmp->next;
	}
	return (d_end < d_start);
}

static int		push_smallest_on_start(t_nlist *stack, t_nlist *other)
{
	t_node	*node;
	t_node	*smallest;
	int		closest_end;

	smallest = stack->start;
	node = stack->start;
	while (node != NULL)
	{
		if (node->data < smallest->data)
			smallest = node;
		node = node->next;
	}
	closest_end = is_node_closest_to_end(smallest);
	while (stack->start != smallest)
	{
		if (closest_end)
			ra(stack);
		else
			rra(stack);
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
