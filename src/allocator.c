/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 16:57:04 by tguillem          #+#    #+#             */
/*   Updated: 2016/09/21 16:57:04 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node		*new_node(int data)
{
	t_node		*res;

	res = NULL;
	if ((res = (t_node*)ft_memalloc(sizeof(t_node))))
		res->data = data;
	return (res);
}

void		destroy_nlist(t_nlist **lst)
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
