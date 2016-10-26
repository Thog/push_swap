/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_merge.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 15:01:01 by tguillem          #+#    #+#             */
/*   Updated: 2016/10/26 15:03:12 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		*get_raw_sorted_stack(t_node *node, int len, int pos)
{
	int	i;
	int	*array;

	i = 0;
	if (!(array = (int*)ft_memalloc(sizeof(int) * len)))
		return (NULL);
	while (i < len)
	{
		array[i] = get_biggest_entry(node, array, i, pos);
		i++;
	}
	return (array);
}

static void		final_sorting(t_nlist *a)
{
	while (a->start->data > a->end->data)
		ra(a, 1);
}

static void		order_and_push_to_a(t_nlist *a, t_nlist *b, int min)
{
	if (dist_end(a->start) > 1 && a->end->data > a->start->data)
		rra(a, 1);
	while (dist_end(b->start) > 1)
	{
		if (dist_end(b->start) > 2 && b->start->data > b->start->next->data &&
				b->start->data > b->start->next->next->data)
			rotation_chooser(a, b, min);
		while (dist_end(a->start) > 1 && is_bigger(a->start, b->start->data,
				min))
			rotation_selector(b);
		pa(a, b, 1);
		if (a->start->data > a->start->next->data &&
			a->start->next->data != min)
		{
			if (dist_end(b->start) > 1 && b->start->data > b->start->next->data)
				ss(a, b, 1);
			else
				sa(a, 1);
		}
		while (is_smallest(b->start, a->start) && !is_already_sorted(a))
			order_stacks(a, b, min);
	}
	pa(a, b, 1);
	if (a->start->data > a->start->next->data && a->start->next->data != min)
		sa(a, 1);
	ra(a, 1);
}

static void		reorder_b(t_nlist *a, t_nlist *b, int *sorted_data, int cut_pos)
{
	if (dist_end(b->start) <= 1)
		return ;
	if (b->start->data > b->end->data)
		rb(b, 1);
	if (b->start->data > b->start->next->data && dist_end(a->start) > 1)
	{
		if (contain_value(a->start->data, sorted_data, cut_pos) &&
			contain_value(a->start->data, sorted_data, cut_pos) &&
			a->start->next->data > a->start->data)
			ss(a, b, 1);
	}
}

void			merge_swap(t_nlist *a, t_nlist *b, int pos)
{
	int			cut_pos;
	int			*sorted_data;
	int			i;
	int			min;

	cut_pos = dist_end(a->start) / 2;
	sorted_data = get_raw_sorted_stack(a->start, cut_pos, pos);
	min = pos == INT_MIN ? sorted_data[0] : pos;
	i = cut_pos;
	while (i)
	{
		if (contain_value(a->start->data, sorted_data, cut_pos) &&
			contain_value(a->start->next->data, sorted_data, cut_pos) &&
			a->start->next->data > a->start->data)
			sa(a, 1);
		if (contain_value(a->start->data, sorted_data, cut_pos))
		{
			pb(a, b, 1);
			i--;
		}
		else
			ra(a, 1);
		reorder_b(a, b, sorted_data, cut_pos);
	}
	order_and_push_to_a(a, b, min);
	if (pos == INT_MIN)
		merge_swap(a, b, sorted_data[cut_pos - 1]);
	ft_memdel((void**)&sorted_data);
	final_sorting(a);
}
