/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 15:08:33 by tguillem          #+#    #+#             */
/*   Updated: 2016/02/11 16:14:08 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void				clear_val(t_val **stack_a, t_val **stack_b)
{
	while (*stack_b)
	{
		write(1, " pa", 3);
		pushfront(stack_a, (*stack_b)->value);
		pop(stack_b);
	}
}

t_val				*create_val()
{
	t_val		*result;

	result = (t_val*)malloc(sizeof(t_val));
	if (!result)
		return (NULL);
	result->next = result;
	result->prev = result;
	return (result);
}

void				destroy_val(t_val *lst)
{
	int		flag;
	t_val	*tmp;
	t_val	*tmp2;

	flag = 0;
	if (lst)
	{
		tmp = lst->prev;
		while (tmp != lst)
		{
			if (!flag)
				tmp = lst;
			flag = 1;
			tmp2 = tmp;
			tmp = tmp->next;
			free(tmp2);
		}
	}
}
