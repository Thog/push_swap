/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 10:33:34 by tguillem          #+#    #+#             */
/*   Updated: 2016/10/07 18:12:19 by tguillem         ###   ########.fr       */
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
			&& ft_strlen(str) >= 11) || (ft_strcmp(str, "2147483647") > 0
			&& ft_strlen(str) >= 10))
			return (0);
	}
	return (ft_isdigit(str[j]) || tmp);
}

static int		check_args_validity(int ac, char **av, int splitted)
{
	int		i;
	int		j;

	i = !splitted ? 1 : 0;
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

static int		compute_ac(int ac, char **split)
{
	int		i;

	i = 0;
	if (!split)
		return (ac);
	while (split && *split)
	{
		i++;
		split++;
	}
	return (i);
}

int				check_condtion(int ac, char **av, char ***args)
{

	if (ac >= 3 && check_args_validity(ac, av, 0))
		return (1);
	else if (ac == 2)
	{
		if (!check_args_before_split(av[1]))
			return (2);
		*args = ft_strsplitcmp(av[1], &ft_iswhitespace);
		return (*args && **args && check_args_validity(compute_ac(ac, *args),
			*args, 1));
	}
	return (0);
}

int				ft_prgm_base(int ac, char **av, void (*op)(t_nlist*, t_nlist*))
{
	t_nlist		*a;
	t_nlist		*b;
	char		**args;
	int			code;

	args = NULL;
	code = check_condtion(ac, av, &args);
	if (code == 1)
	{
		code = 0;
		a = (t_nlist*)ft_memalloc(sizeof(t_nlist));
		b = (t_nlist*)ft_memalloc(sizeof(t_nlist));
		if ((!a || !b) && (code = 1))
			ft_putstr_fd("Error\n", 2);
		else if (fill_stack(a, compute_ac(ac, args), av, &args))
			op(a, b);
		else
			ft_putstr_fd("Error\n", 2);
		destroy_nlist(&a);
		destroy_nlist(&b);
	}
	else if (code != 0)
		ft_putstr_fd("Error\n", 2);
	resource_manager_destroy();
	return (code);
}
