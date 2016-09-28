/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 14:03:23 by tguillem          #+#    #+#             */
/*   Updated: 2016/09/21 16:57:39 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

typedef struct		s_node
{
	int				data;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct		s_nlist
{
	t_node			*start;
	t_node			*end;
}					t_nlist;

int					ft_prgm_base(int ac, char **av, void (*op)(t_nlist*,
	t_nlist*));
void				resolve_pushswap(t_nlist *a, t_nlist *b);
void				sa(t_nlist *a);
void				sb(t_nlist *b);
void				ss(t_nlist *a, t_nlist *b);
void				ra(t_nlist *a);
void				rb(t_nlist *a);
void				rr(t_nlist *a, t_nlist *b);
void				rra(t_nlist *a);
void				rrb(t_nlist *a);
void				rrr(t_nlist *a, t_nlist *b);
void				pa(t_nlist *a, t_nlist *b);
void				pb(t_nlist *a, t_nlist *b);
t_node				*compute_end(t_node *node);
int					is_already_sorted(t_nlist *stack);
void				pushback_operation(t_node **start, t_node **end);
void				pushup_operation(t_node **start, t_node **end);
void				link_node(t_node *start, t_node *end);
t_node				*new_node(int data);
void				destroy_nlist(t_nlist **data);
int					fill_stack(t_nlist *a, int ac, char **av);
#endif
