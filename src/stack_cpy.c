/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_cpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 15:40:51 by tguillem          #+#    #+#             */
/*   Updated: 2016/04/14 15:40:51 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			*stack_cpy(int *cpy, t_stack *stack)
{
	int		i;

	i = 0;
	cpy = (int *)malloc(sizeof(int) * (stack->a_size + 1));
	while (i < stack->a_size)
	{
		cpy[i] = stack->a[i];
		i++;
	}
	return (cpy);
}
