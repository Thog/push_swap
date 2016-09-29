/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 10:33:34 by tguillem          #+#    #+#             */
/*   Updated: 2016/09/29 10:33:34 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		is_valid_arg(char *str, int j)
{
	size_t		tmp;

	tmp = str[j] == '-' && ft_isdigit(str[j + 1]);
	if (!j)
	{
		tmp += ft_count_digit(ft_atoi(str), 10);
		if (ft_strlen(str) == tmp)
			return (1);
		ft_printf_fd(2, "%i == %i\n", tmp, ft_strlen(str));
	}
	return (ft_isdigit(str[j]));
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
	else
		ft_putstr_fd("Error\n", 2);
	return (code);
}
