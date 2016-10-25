/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 14:01:50 by tguillem          #+#    #+#             */
/*   Updated: 2016/10/23 13:26:45 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			resolve_pushswap(t_nlist *a, t_nlist *b)
{

	if (is_already_sorted(a))
		return ;
	if (dist_end(a->start) >= 40)
	{
		// MERGE
		//merge_swap(a, b);
	}
	else
	{
		// FAST
		while (!is_already_sorted(a) && !b->start)
			fast_swap(a, b);
	}
}

int				main(int ac, char **av)
{
	return (ft_prgm_base(ac, av, &resolve_pushswap));
}
