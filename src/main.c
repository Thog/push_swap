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

static int		check_args_validity(int ac, char **av)
{
	int		i;
	int		j;

	i = 1;
	while (ac > i)
	{
		j = 0;
		while (av[i][j])
		{
			if (ft_isdigit(av[i][j]) || (!j && av[i][j] == '-' && \
						ft_isdigit(av[i][j + 1])))
				j++;
			else
			{
				ft_putendl("Invalid arguments. Please check them and try again.");
				return (0);
			}
		}
		i++;
	}
	return (1);
}

int				main(int ac, char **av)
{
	t_stack		*stack;

	if (ac < 3)
		write(1, "\n", 1);
	else if (check_args_validity(ac, av) && (stack = create_stack(ac, av)))
		resolve_pushswap(stack);
	return (0);
}
