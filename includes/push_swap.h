/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 14:03:23 by tguillem          #+#    #+#             */
/*   Updated: 2016/04/19 13:01:27 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

typedef	struct	s_stack
{
	int			*a;
	int			*b;
	int			a_size;
	int			b_size;
	int			top_a;
	int			top_b;
	int			arg;
	int			count;
}				t_stack;

typedef struct		s_node
{
	int				data;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct		s_nlist
{
	size_t			len;
	t_node			*start;
	t_node			*end;
}					t_nlist;

t_stack			*create_stack(int ac, char **av);
void			resolve_pushswap(t_nlist *a, t_nlist *b);
void			print_op(t_stack *stack, char *operation);
void			ra(t_nlist *a);
void			rb(t_nlist *a);
void			pa(t_nlist *a, t_nlist *b);
void			pb(t_nlist *a, t_nlist *b);
int				is_already_sorted(t_nlist *stack);
#endif
