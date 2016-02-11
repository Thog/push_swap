/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 14:52:23 by tguillem          #+#    #+#             */
/*   Updated: 2016/02/11 17:30:32 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		pushback(t_val **lst, int value)
{
	t_val *new;

	if (!(new = create_val()))
		return ;
	new->value = value;
	new->prev = new;
	new->next = new;
	if (*lst)
	{
		new->next = *lst;
		new->prev = (*lst)->prev;
		(*lst)->prev->next = new;
		(*lst)->prev = new;
	}
	else
		*lst = new;
}

void		pushfront(t_val **lst, int value)
{
	pushback(lst, value);
	*lst = (*lst)->prev;
}

void		pop(t_val **lst)
{
	t_val	*tmp;

	if (!*lst)
		return ;
	if (*lst == (*lst)->next)
	{
		free(*lst);
		*lst = NULL;
	}
	else
	{
		tmp = *lst;
		(*lst)->prev->next = (*lst)->next;
		(*lst)->next->prev = (*lst)->prev;
		*lst = (*lst)->next;
		free(tmp);
	}
}

void		shift(t_val **lst)
{
	write(1, "ra", 2);
	if (!*lst)
		return ;
	*lst = (*lst)->next;
}
