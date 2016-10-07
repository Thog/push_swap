/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 10:33:34 by tguillem          #+#    #+#             */
/*   Updated: 2016/10/06 18:32:30 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		is_valid_arg(char *str, int j)
{
	size_t		tmp;

	tmp = !j && str[j] == '-' && ft_isdigit(str[j + 1]);
	if (!j)
	{
		if ((str[0] == '-' && ft_strcmp(str, "-2147483648") > 0
			&& ft_strlen(str) >= 11) ||	(ft_strcmp(str, "2147483647") > 0
			&& ft_strlen(str) >= 10))
			return (0);
	}
	return (ft_isdigit(str[j]) || tmp);
}

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
			if (is_valid_arg(av[i], j))
				j++;
			else
				return (0);
		}
		i++;
	}
	return (1);
}

int				ft_prgm_base(int ac, char **av, void (*op)(t_nlist*, t_nlist*))
{
	t_nlist		*a;
	t_nlist		*b;
	int			code;

	code = 0;
	if (ac >= 3 && check_args_validity(ac, av))
	{
		a = (t_nlist*)ft_memalloc(sizeof(t_nlist));
		b = (t_nlist*)ft_memalloc(sizeof(t_nlist));
		if ((!a || !b) && (code = 1))
			ft_putstr_fd("Error\n", 2);
		else if (fill_stack(a, ac, av))
			op(a, b);
		else
			ft_putstr_fd("Error\n", 2);
		destroy_nlist(&a);
		destroy_nlist(&b);
	}
	else if (ac >= 3)
		ft_putstr_fd("Error\n", 2);
	resource_manager_destroy();
	return (code);
}
