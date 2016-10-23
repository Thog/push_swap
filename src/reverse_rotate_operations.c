/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_operations.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 16:03:11 by tguillem          #+#    #+#             */
/*   Updated: 2016/10/23 13:22:40 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		rra(t_nlist *a, int verbose)
{
	pushback_operation(&a->start, &a->end);
	if (verbose)
		ft_putstr("rra\n");
}

void		rrb(t_nlist *b, int verbose)
{
	pushback_operation(&b->start, &b->end);
	if (verbose)
		ft_putstr("rrb\n");
}

void		rrr(t_nlist *a, t_nlist *b, int verbose)
{
	pushback_operation(&a->start, &a->end);
	pushback_operation(&b->start, &b->end);
	if (verbose)
		ft_putstr("rrr\n");
}
