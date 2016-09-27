/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_operations.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 16:03:02 by tguillem          #+#    #+#             */
/*   Updated: 2016/09/21 16:03:02 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		rra(t_nlist *a)
{
	pushup_operation(&a->end, &a->start);
	ft_putstr("rra\n");
}

void		rrb(t_nlist *b)
{
	pushup_operation(&b->end, &b->start);
	ft_putstr("rrb\n");
}

void		rrr(t_nlist *a, t_nlist *b)
{
	pushup_operation(&a->end, &a->start);
	pushup_operation(&b->end, &b->start);
	ft_putstr("rrr\n");
}
