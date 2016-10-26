#include "push_swap.h"

int		need_reverse_rotation(t_nlist *b)
{
	int		len;
	int		min;
	int		index;
	int		i;
	t_node	*tmp;

	min = INT_MAX;
	len = dist_end(b->start);
	i = 0;
	tmp = b->start;
	while (tmp)
	{
		if (min > tmp->data)
		{
			min = tmp->data;
			index = i;
		}
		i++;
		tmp = tmp->next;
	}
	if (index > (len / 2))
		return (1);
	else
		return (0);
}

void 	rotation_chooser(t_nlist *a, t_nlist *b, int min)
{
	t_node		*smallest;

	smallest = get_limits(b->start, 0);
	if (smallest->data > a->start->data && a->start->data != min)
		rr(a, b, 1);
	else
		rb(b, 1);
}

int		contain_value(int data, int *array, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		if (data == array[i])
			return (1);
		i++;
	}
	return (0);
}

int		is_bigger(t_node *node, int n, int min)
{
	if (node->data == min || node->next->data == min)
		return (0);
	if (node->data < n && node->next->data < n)
		return (1);
	return (0);
}

void	rotation_selector(t_nlist *b)
{
	if (need_reverse_rotation(b))
		rrb(b, 1);
	else
		rb(b, 1);
}
