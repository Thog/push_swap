#include "push_swap.h"

void 			show_stacks(t_nlist *a, t_nlist *b)
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

void			apply_checker(t_nlist *a, t_nlist *b)
{
	char	*buffer; // FIXME: LEAKING

	show_stacks(a, b);
	while (get_next_line(0, &buffer) > 0)
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
		else
		{
			ft_putstr_fd("Error\n", 2);
			return ;
		}
		show_stacks(a, b);
	}
	ft_printf("%s\n", (is_already_sorted(a) && !b->start) ? "OK" : "KO");
}

int				main(int ac, char **av)
{
	return (ft_prgm_base(ac, av, &apply_checker));
}
