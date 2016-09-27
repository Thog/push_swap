/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 15:40:38 by tguillem          #+#    #+#             */
/*   Updated: 2016/09/21 16:56:02 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				fill_stack(t_nlist *a, int ac, char **av)
{
	int		i;
	t_node	*node;
	t_node	*prev_node;

	i = 0;
	prev_node = NULL;
	while ((++i) < ac)
	{
		//ft_printf_fd(2, "Creating node %s (start: %p, end: %p)\n", av[i], a->start, a->end);
		node = new_node(ft_atoi(av[i]));
		if (i == (ac - 1))
			a->end = node;
		else if (i == 1)
			a->start = node;
		link_node(node, prev_node);
		prev_node = node;
	}
	return (1);
}

int				is_already_sorted(t_nlist *stack)
{
	t_node	*node;

	node = stack->start;
	if (node->data == stack->end->data)
		return (1);
	while (node->next != NULL)
	{
		if (node->data > node->next->data)
			return (0);
		node = node->next;
	}
	return (1);
}

void			push_smallest_on_start(t_nlist *stack)
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
	}
}

void			resolve_pushswap(t_nlist *a, t_nlist *b)
{
	if (is_already_sorted(a))
		return ;
	while (a->start != NULL)
	{
		push_smallest_on_start(a);
		pb(a, b);
	}
	while (b->start != NULL)
	{
		pa(a, b);
	}
}
