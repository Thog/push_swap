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

t_node			*compute_end(t_node *node)
{
	if (!node || !node->next)
		return (node);
	while (node && node->next)
		node = node->next;
	return (node);
}

int				is_already_sorted(t_nlist *stack)
{
	t_node	*node;

	if (!stack)
		return (0);
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
