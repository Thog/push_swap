/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 10:33:38 by tguillem          #+#    #+#             */
/*   Updated: 2016/10/07 18:29:10 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			show_stacks(t_nlist *a, t_nlist *b)
{
	t_node	*node;

	node = a->start;
	ft_printf_fd(2, "a (%p / %p): %s", node, a->end, node ? "" : "Empty");
	while (node)
	{
		ft_printf_fd(2, "%i ", node->data);
		node = node->next;
	}
	ft_putstr_fd("\n", 2);
	node = b->start;
	ft_printf_fd(2, "b (%p / %p): %s", node, b->end, node ? "" : "Empty");
	while (node)
	{
		ft_printf_fd(2, "%i ", node->data);
		node = node->next;
	}
	ft_putstr_fd("\n", 2);
}

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
		sa(a);
	else if (!ft_strcmp("sb", buffer))
		sb(b);
	else if (!ft_strcmp("ss", buffer))
		ss(a, b);
	else if (!ft_strcmp("pa", buffer))
		pa(a, b);
	else if (!ft_strcmp("pb", buffer))
		pb(a, b);
	else if (!ft_strcmp("ra", buffer))
		ra(a);
	else if (!ft_strcmp("rb", buffer))
		rb(b);
	else if (!ft_strcmp("rr", buffer))
		rr(a, b);
	else if (!ft_strcmp("rra", buffer))
		rra(a);
	else if (!ft_strcmp("rrb", buffer))
		rrb(b);
	else if (!ft_strcmp("rrr", buffer))
		rrr(a, b);
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
	ft_printf("%s\n", (is_already_sorted(a) && !b->start) ? "OK" : "KO");
}

int				main(int ac, char **av)
{
	return (ft_prgm_base(ac, av, &apply_checker));
}
