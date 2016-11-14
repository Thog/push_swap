/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 14:03:23 by tguillem          #+#    #+#             */
/*   Updated: 2016/10/26 15:05:32 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
# include <limits.h>

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
void				sa(t_nlist *a, int verbose);
void				sb(t_nlist *b, int verbose);
void				ss(t_nlist *a, t_nlist *b, int verbose);
void				ra(t_nlist *a, int verbose);
void				rb(t_nlist *a, int verbose);
void				rr(t_nlist *a, t_nlist *b, int verbose);
void				rra(t_nlist *a, int verbose);
void				rrb(t_nlist *a, int verbose);
void				rrr(t_nlist *a, t_nlist *b, int verbose);
void				pa(t_nlist *a, t_nlist *b, int verbose);
void				pb(t_nlist *a, t_nlist *b, int verbose);
t_node				*compute_end(t_node *node);
int					is_already_sorted(t_nlist *stack);
void				pushback_operation(t_node **start, t_node **end);
void				pushup_operation(t_node **start, t_node **end);
void				link_node(t_node *start, t_node *end);
t_node				*new_node(int data);
void				destroy_nlist(t_nlist **data);
int					fill_stack(t_nlist *a, int ac, char **av, char ***split);
int					check_args_before_split(char *name);
void				destroy_args(char ***args);
int					dist_end(t_node *node);
t_node				*get_limits(t_node *node, int max);
int					dist_end(t_node *node);
int					d_node(t_node *node);
void				fast_swap(t_nlist *a, t_nlist *b);
void				merge_swap(t_nlist *a, t_nlist *b, int pos, int min);
int					contain_value(int nb, int *array, int len);
void				rotation_chooser(t_nlist *a, t_nlist *b, int min);
int					is_bigger(t_node *node, int n, int min);
void				rotation_selector(t_nlist *b);
int					is_smallest(t_node *src, t_node *cmp);
void				order_stacks(t_nlist *a, t_nlist *b, int min);
int					get_biggest_entry(t_node *node, int *array, int len,
	int pos);
#endif
