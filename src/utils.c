/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/18 10:01:34 by tguillem          #+#    #+#             */
/*   Updated: 2016/10/18 10:01:41 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			dist_end(t_node *node)
{
	int			len;

	len = 0;
	while (node)
	{
		len++;
		node = node->next;
	}
	return (len);
}

t_node		*get_max(t_node *node)
{
	t_node	*res;

	res = node;
	while (node)
	{
		if (res->data < node->data)
			res = node;
		node = node->next;
	}
	return (res);
}

int			d_node(t_node *node)
{
	t_node		*tmp;

	tmp = get_max(node);
	if (tmp)
		return (tmp->data);
	else
		return (node->data);
}

int			check_args_before_split(char *name)
{
	int		size;
	char	prev_whitespace;

	prev_whitespace = 0;
	size = ft_strlen(name);
	if (!ft_iswhitespace(name[0]) && !ft_iswhitespace(name[size - 1]))
	{
		while (*name)
		{
			if (prev_whitespace && ft_iswhitespace(*name))
				return (0);
			prev_whitespace = ft_iswhitespace(*name);
			name++;
		}
		return (1);
	}
	return (0);
}

void		destroy_args(char ***args)
{
	char		**arg;

	if (*args)
	{
		arg = *args;
		while (arg && *arg)
		{
			ft_strdel(arg);
			arg++;
		}
		free(*args);
	}
}
