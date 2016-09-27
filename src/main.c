/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 14:01:50 by tguillem          #+#    #+#             */
/*   Updated: 2016/09/21 16:21:19 by tguillem         ###   ########.fr       */
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
				ft_putstr(
					"Invalid arguments. Please check them and try again.");
				return (0);
			}
		}
		i++;
	}
	return (1);
}

int				main(int ac, char **av)
{
	t_nlist		*a;
	t_nlist		*b;
	int			code;

	code = 0;
	if (ac >= 3 && check_args_validity(ac, av))
	{
		a = (t_nlist*)ft_memalloc(sizeof(t_nlist));
		b = (t_nlist*)ft_memalloc(sizeof(t_nlist));
		if (!a || !b)
		{
			code = 1;
			ft_printf_fd(2, "Cannot allocate memory on the heap, exiting!\n");
		}
		else if (fill_stack(a, ac, av))
		{
			resolve_pushswap(a, b);
			t_node *node = a->start;
			while (node)
			{
				ft_printf("%i ", node->data);
				node = node->next;
			}
			ft_printf("\n");
		}
		else
			ft_putstr("Error");
		destroy_nlist(&a);
		destroy_nlist(&b);
	}
	else
		ft_putstr("Error");
	write(1, "\n", 1);
	return (code);
}
