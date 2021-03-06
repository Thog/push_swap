/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 16:03:35 by tguillem          #+#    #+#             */
/*   Updated: 2016/10/18 10:27:44 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		push_operation(t_nlist *a, t_nlist *b, char *operation, int log)
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
		a->end = compute_end(a->start);
		b->end = compute_end(b->start);
		if (log)
			ft_putstr(operation);
	}
}

void			pa(t_nlist *a, t_nlist *b, int verbose)
{
	push_operation(b, a, "pa\n", verbose);
}

void			pb(t_nlist *a, t_nlist *b, int verbose)
{
	push_operation(a, b, "pb\n", verbose);
}
