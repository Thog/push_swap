/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 14:01:50 by tguillem          #+#    #+#             */
/*   Updated: 2016/02/11 17:31:16 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		ft_atoi(const char *nptr)
{
	int		i;
	int		n;
	int		sign;

	i = 0;
	n = 0;
	sign = 1;
	while ((nptr[i] == ' ') || (nptr[i] == '\t') || (nptr[i] == '\n')
			|| (nptr[i] == '\v') || (nptr[i] == '\f') || (nptr[i] == '\r'))
		i++;
	sign = (nptr[i] == '-') ? -1 : 1;
	i = (nptr[i] == '-' || nptr[i] == '+') ? i + 1 : i;
	while (nptr[i] && nptr[i] >= '0' && nptr[i] <= '9')
	{
		n = n * 10 + (nptr[i] - '0');
		i++;
	}
	return (n * sign);
}

int				main(int ac, char **av)
{
	int		i;
	t_val	*stack_a;
	t_val	*stack_b;

	if (ac < 3)
		write(1, "\n", 1);
	else
	{
		stack_a = create_val();
		stack_b = create_val();
		i = 0;
		while (++i < ac)
			pushback(&stack_a, ft_atoi(av[i]));
		push_swap(stack_a, stack_b);
	}
	return (0);
}
