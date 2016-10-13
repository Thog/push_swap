/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 14:01:50 by tguillem          #+#    #+#             */
/*   Updated: 2016/10/07 18:31:55 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			show_stacks(t_nlist *a, t_nlist *b)
{
	t_node	*node;

	node = a->start;
	ft_printf_fd(2, "a (%p / %p): %s", node, a->end, node ? "" : "Empty");
	while (node)
	{
		ft_printf_fd(2, "%i ", node->data);
		node = node->next;
	}
	ft_putstr_fd("\n", 2);
	node = b->start;
	ft_printf_fd(2, "b (%p / %p): %s", node, b->end, node ? "" : "Empty");
	while (node)
	{
		ft_printf_fd(2, "%i ", node->data);
		node = node->next;
	}
	ft_putstr_fd("\n", 2);
}

static long		is_node_closest_to_end(t_node *node)
{
	t_node		*tmp;
	long		d_start;
	long		d_end;

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
	return (d_end - d_start);
}

static int		push_smallest_on_start(t_nlist *stack, t_nlist *other)
{
	t_node	*node;
	t_node	*smallest;
	long	closest_end;

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
		if (closest_end < 0)
			ra(stack);
		else if (stack->start && stack->start->next == smallest)
			sa(stack);
		else
			rra(stack);
		if (is_already_sorted(stack) && !other->start)
			return (0);
	}
	return (1);
}

void			resolve_pushswap(t_nlist *a, t_nlist *b)
{
	show_stacks(a, b);
	if (is_already_sorted(a))
		return ;
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
