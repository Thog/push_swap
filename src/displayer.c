/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displayer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 15:40:21 by tguillem          #+#    #+#             */
/*   Updated: 2016/04/19 13:43:38 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		display_resolved(t_stack *stack)
{
	int		i;

	i = 0;
	ft_putstr("\na: ");
	while (i < stack->a_size)
	{
		ft_putnbr(stack->a[i]);
		ft_putchar(' ');
		i++;
	}
	ft_putstr("\nb: ");
	i = 0;
	while (i < stack->b_size)
	{
		ft_putnbr(stack->b[i]);
		ft_putchar(' ');
		i++;
	}
	ft_putchar('\n');
}

void		print_op(t_stack *stack, char *str)
{
	if (stack->count)
		ft_putchar(' ');
	stack->count++;
	ft_putstr(str);
}
