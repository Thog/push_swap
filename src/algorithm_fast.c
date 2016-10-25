#include "push_swap.h"

void 	finalize_fast_swap(t_nlist *a, t_nlist *b)
{
	while (dist_end(b->start) > 0)
	{
		while (dist_end(b->start) > 1 && b->end->data > b->start->data)
			rrb(b, 1);
		pa(a, b, 1);
		if (dist_end(b->start) > 1 && dist_end(a->start) > 1 && a->start->data > a->start->next->data && b->start->data < b->start->next->data)
			ss(a, b, 1);
		else
		{
			if (dist_end(a->start) > 1 && a->start->data > a->start->next->data)
				sa(a, 1);
			if (dist_end(b->start) > 1 && b->start->data < b->start->next->data)
				sb(b, 1);
		}
	}
}

void	fast_swap(t_nlist *a, t_nlist *b)
{
	t_node		*max;

	max = get_max(a->start);
	while (a->start && a->start->next)
	{
		if (dist_end(b->start) > 1 && a->start->data > a->start->next->data && b->start->data < b->start->next->data)
			ss(a, b, 1);
		else if (a->start->data > a->start->next->data)
			sa(a, 1);
		else if (dist_end(b->start) > 1 && b->start->data < b->start->next->data)
			sb(b, 1);
		else if (max == a->start || (dist_end(b->start) > 2 && a->start->data > a->start->next->data && a->start->data > a->start->next->next->data))
			ra(a, 1);
		while (dist_end(a->start) > 2 && a->end->data < a->start->data && a->end->data < a->start->next->data)
			rra(a, 1);
		if (dist_end(b->start) > 1 && b->end->data > b->start->data)
			rrb(b, 1);
		if (is_already_sorted(a))
			break ;
		pb(a, b, 1);
		if (dist_end(b->start) > 2 && ((b->start->data < b->start->next->data && b->start->data < b->start->next->next->data) || b->end->data > b->start->data))
			rb(b, 1);
	}
	finalize_fast_swap(a, b);
}
