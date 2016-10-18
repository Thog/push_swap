/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 10:33:52 by tguillem          #+#    #+#             */
/*   Updated: 2016/10/18 10:25:53 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		swap_first_entries(t_nlist *a)
{
	t_node		*first;
	t_node		*second;
	t_node		*three;

	first = a->start;
	if (first)
	{
		second = first->next;
		if (second)
		{
			three = second->next;
			first->prev = second;
			second->next = first;
			second->prev = NULL;
			first->next = three;
			a->start = second;
			a->end = compute_end(a->start);
			if (three)
				three->prev = first;
		}
	}
}

void			sa(t_nlist *a, int verbose)
{
	swap_first_entries(a);
	if (verbose)
		ft_putstr("sa\n");
}

void			sb(t_nlist *b, int verbose)
{
	swap_first_entries(b);
	if (verbose)
		ft_putstr("sb\n");
}

void			ss(t_nlist *a, t_nlist *b, int verbose)
{
	swap_first_entries(a);
	swap_first_entries(b);
	if (verbose)
		ft_putstr("ss\n");
}
