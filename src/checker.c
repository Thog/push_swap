/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 10:33:38 by tguillem          #+#    #+#             */
/*   Updated: 2016/10/23 13:23:34 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		is_valid_op(char *buffer)
{
	return (!ft_strcmp("sa", buffer) || !ft_strcmp("sb", buffer) ||
		!ft_strcmp("ss", buffer) || !ft_strcmp("pa", buffer) ||
		!ft_strcmp("pb", buffer) || !ft_strcmp("ra", buffer) ||
		!ft_strcmp("rb", buffer) || !ft_strcmp("rr", buffer) ||
		!ft_strcmp("rra", buffer) || !ft_strcmp("rrb", buffer) ||
		!ft_strcmp("rrr", buffer));
}

static int		apply_operation(t_nlist *a, t_nlist *b, char *buffer)
{
	if (!ft_strcmp("sa", buffer))
		sa(a, 0);
	else if (!ft_strcmp("sb", buffer))
		sb(b, 0);
	else if (!ft_strcmp("ss", buffer))
		ss(a, b, 0);
	else if (!ft_strcmp("pa", buffer))
		pa(a, b, 0);
	else if (!ft_strcmp("pb", buffer))
		pb(a, b, 0);
	else if (!ft_strcmp("ra", buffer))
		ra(a, 0);
	else if (!ft_strcmp("rb", buffer))
		rb(b, 0);
	else if (!ft_strcmp("rr", buffer))
		rr(a, b, 0);
	else if (!ft_strcmp("rra", buffer))
		rra(a, 0);
	else if (!ft_strcmp("rrb", buffer))
		rrb(b, 0);
	else if (!ft_strcmp("rrr", buffer))
		rrr(a, b, 0);
	return (1);
}

void			apply_checker(t_nlist *a, t_nlist *b)
{
	char	*buffer;
	t_array	*operations;
	t_array	*index;

	operations = NULL;
	buffer = NULL;
	while (get_next_line(0, &buffer) > 0)
	{
		if (!is_valid_op(buffer))
		{
			ft_putstr_fd("Error\n", 2);
			destroy_array(operations);
			return ;
		}
		operations = array_init(operations, ft_strdup(buffer));
		ft_strdel(&buffer);
	}
	ft_strdel(&buffer);
	index = operations;
	while (index && apply_operation(a, b, index->data))
		index = index->next;
	destroy_array(operations);
	show_stacks(a, b);
	ft_printf("%s\n", (is_already_sorted(a) && !b->start) ? "OK" : "KO");
}

int				main(int ac, char **av)
{
	return (ft_prgm_base(ac, av, &apply_checker));
}
