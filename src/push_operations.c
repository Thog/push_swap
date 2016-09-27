/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 16:03:35 by tguillem          #+#    #+#             */
/*   Updated: 2016/09/21 16:03:54 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_operation(t_nlist *a, t_nlist *b, char *operation)
{
	t_node	*start_a;
	t_node	*start_b;

	start_a = a->start;
	start_b = b->start;
	if (start_a)
	{
		a->start = a->start->next;
		if (a->start)
			a->start->prev = NULL;
		start_a->next = start_b;
		if (start_b)
			start_b->prev = start_a;
		b->start = start_a;
		ft_putstr(operation);
	}
}

void		pa(t_nlist *a, t_nlist *b)
{
	push_operation(b, a, "pa\n");
}

void		pb(t_nlist *a, t_nlist *b)
{
	push_operation(a, b, "pb\n");
}
