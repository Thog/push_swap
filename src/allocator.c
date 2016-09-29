/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 16:57:04 by tguillem          #+#    #+#             */
/*   Updated: 2016/09/29 10:34:49 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				is_duplicate(t_node *stack, int data)
{
	while (stack)
	{
		if (stack->data == data)
			return (1);
		stack = stack->next;
	}
	return (0);
}

int				fill_stack(t_nlist *a, int ac, char **av)
{
	int		i;
	int		data;
	t_node	*node;
	t_node	*prev_node;

	i = 0;
	prev_node = NULL;
	while ((++i) < ac)
	{
		data = ft_atoi(av[i]);
		if (is_duplicate(a->start, data))
			return (0);
		node = new_node(data);
		if (i == (ac - 1))
			a->end = node;
		else if (i == 1)
			a->start = node;
		link_node(node, prev_node);
		prev_node = node;
	}
	return (1);
}

t_node			*new_node(int data)
{
	t_node		*res;

	res = NULL;
	if ((res = (t_node*)ft_memalloc(sizeof(t_node))))
		res->data = data;
	return (res);
}

void			destroy_nlist(t_nlist **lst)
{
	t_node		*node;
	t_node		*tmp;

	if (lst && *lst)
	{
		node = (*lst)->end;
		while (node)
		{
			tmp = node->next;
			ft_memdel((void**)&node);
			node = tmp;
		}
		ft_memdel((void**)lst);
	}
}
