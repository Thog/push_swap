/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 16:03:02 by tguillem          #+#    #+#             */
/*   Updated: 2016/10/23 13:23:07 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ra(t_nlist *a, int verbose)
{
	pushup_operation(&a->start, &a->end);
	if (verbose)
		ft_putstr("ra\n");
}

void		rb(t_nlist *b, int verbose)
{
	pushup_operation(&b->start, &b->end);
	if (verbose)
		ft_putstr("rb\n");
}

void		rr(t_nlist *a, t_nlist *b, int verbose)
{
	pushup_operation(&a->start, &a->end);
	pushup_operation(&b->start, &b->end);
	if (verbose)
		ft_putstr("rr\n");
}
