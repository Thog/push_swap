/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushback_operations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 16:57:12 by tguillem          #+#    #+#             */
/*   Updated: 2016/09/21 16:57:12 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		link_node(t_node *node, t_node *prev)
{
	if (node)
		node->prev = prev;
	if (prev)
		prev->next = node;
}

void		pushback_operation(t_node **start, t_node **end)
{
	t_node	*prev;

	if (!*end || !*start)
		return ;
	prev = (*end)->prev;
	link_node(*start, *end);
	if ((*end)->prev)
		(*end)->prev->next = NULL;
	(*end)->prev = NULL;
	*start = *end;
	if (prev)
		*end = prev;
}

void		pushup_operation(t_node **start, t_node **end)
{
	t_node	*prev;

	if (!*end || !*start)
		return ;
	prev = *start;
	link_node(prev, *end);
	*start = (*start)->next;
	prev->next = NULL;
	(*start)->prev = NULL;
	*end = prev;
}
