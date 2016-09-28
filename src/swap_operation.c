#include "push_swap.h"

static void		swap_first_entries(t_nlist *a)
{
	t_node		*first;
	t_node		*second;
	t_node		*three;

	first = a->start;
	if (first)
	{
		second = first->next;
		if (second)
		{
			three = second->next;
			first->prev = second;
			second->next = first;
			second->prev = NULL;
			first->next = three;
			a->start = second;
			a->end = compute_end(a->start);
			if (three)
				three->prev = first;
		}
	}
}

void			sa(t_nlist *a)
{
	swap_first_entries(a);
	ft_putstr("sa\n");
}

void			sb(t_nlist *b)
{
	swap_first_entries(b);
	ft_putstr("sb\n");
}

void			ss(t_nlist *a, t_nlist *b)
{
	swap_first_entries(a);
	swap_first_entries(b);
	ft_putstr("ss\n");
}
