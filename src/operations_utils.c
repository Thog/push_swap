#include "push_swap.h"

int		get_biggest_entry(t_node *node, int *array, int len, int pos)
{
	int max;

	max = INT_MAX;
	while (node)
	{
		if (node->data < max && pos < node->data && !contain_value(node->data, array, len))
			max = node->data;
		node = node->next;
	}
	return (max);
}

int			is_smallest(t_node *src, t_node *cmp)
{
	src = get_limits(src, 0);
	if (src && cmp && src->data > cmp->data)
		return (1);
	return (0);
}

void	order_stacks(t_nlist *a, t_nlist *b, int min)
{
	if (a->start->data > a->start->next->data && a->start->next->data != min &&
a->start->data != min)
		sa(a, 1);
	if (a->end->data > a->start->data && a->start->data != min)
	{
		rra(a, 1);
		sa(a, 1);
	}
	if (dist_end(b->start) > 2 && b->start->data > b->start->next->data &&
b->start->data > b->start->next->next->data)
		rr(a, b, 1);
	else
		ra(a, 1);
}
