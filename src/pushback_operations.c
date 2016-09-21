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

static void	pushback_implementation(t_node **start, t_node **end, int allocator)
{
	t_node	*prev;
	t_node	*start_node;
	t_node	*end_node;

	if (!*start)
		return ;
	start_node = *start;
	end_node = *end;
	// before start
	prev = start_node->prev;
	// push start before end
	if (end_node)
		end_node->prev = start_node;
	else
		*end = start_node;
	// remove the linkage of the next for the prev start
	if (prev)
		prev->next = NULL;
	// remove the likage of the prev for the prev start
	start_node->prev = NULL;
	// push end after start
	start_node->next = *end;
	// start is now prev
	if (!allocator)
		*start = prev;
}

void		pushback_init(t_node **start, t_node **end)
{
	pushback_implementation(start, end, 1);
}

void		pushback_operation(t_node **start, t_node **end)
{
	pushback_implementation(start, end, 0);
}
