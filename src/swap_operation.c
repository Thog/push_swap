#include "push_swap.h"

void		swap_first_entries(t_node *first, char *operation)
{
	t_node		*second;
	t_node		*three;

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
			if (three)
				three->prev = first;
		}
	}
	ft_putstr(operation);
}
