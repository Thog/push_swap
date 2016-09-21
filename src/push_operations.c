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

static void	push_operation(t_nlist *a, t_nlist *b)
{
	pushback_operation(&a->start, &b->end);
}

void		pa(t_nlist *a, t_nlist *b)
{
	push_operation(b, a);
	ft_putstr("pa");
}

void		pb(t_nlist *a, t_nlist *b)
{
	push_operation(a, b);
	ft_putstr("pb");
}
