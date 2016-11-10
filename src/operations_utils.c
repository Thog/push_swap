/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 14:54:45 by tguillem          #+#    #+#             */
/*   Updated: 2016/10/26 15:04:41 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		get_biggest_entry(t_node *node, int *array, int len, int pos)
{
	int max;

	max = INT_MAX;
	while (node)
	{
		if (node->data < max && pos < node->data && !contain_value(node->data,
			array, len))
			max = node->data;
		node = node->next;
	}
	return (max);
}

int		is_smallest(t_node *src, t_node *cmp)
{
	src = get_limits(src, 0);
	if (src && cmp && src->data > cmp->data)
		return (1);
	return (0);
}

void	order_stacks(t_nlist *a, t_nlist *b, int min)
{
	show_stacks(a, b);
	if (a->start->data > a->start->next->data && a->start->next->data != min &&
a->start->data != min)
		sa(a, 1);
	if (a->end->data > a->start->data && a->start->data != min)
	{
		rra(a, 1);
		sa(a, 1);
	}
	if (is_already_sorted(a))
		return ;
	if (dist_end(b->start) > 2 && b->start->data > b->start->next->data &&
b->start->data > b->start->next->next->data)
		rr(a, b, 1);
	else
		ra(a, 1);
}

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