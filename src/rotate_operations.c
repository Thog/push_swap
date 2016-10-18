/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 16:03:11 by tguillem          #+#    #+#             */
/*   Updated: 2016/10/18 10:26:19 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ra(t_nlist *a, int verbose)
{
	pushback_operation(&a->start, &a->end);
	if (verbose)
		ft_putstr("ra\n");
}

void		rb(t_nlist *b, int verbose)
{
	pushback_operation(&b->start, &b->end);
	if (verbose)
		ft_putstr("rb\n");
}

void		rr(t_nlist *a, t_nlist *b, int verbose)
{
	pushback_operation(&a->start, &a->end);
	pushback_operation(&b->start, &b->end);
	if (verbose)
		ft_putstr("rr\n");
}
