/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 14:03:23 by tguillem          #+#    #+#             */
/*   Updated: 2016/02/11 15:09:12 by tguillem         ###   ########.fr       */
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

t_stack		*create_stack(int ac, char **av);
void		resolve_pushswap(t_stack *stack);
int			get_max(t_stack *stack);
int			get_min(t_stack *stack);
int			find_best_swap(t_stack *stack);
void		swap_sa(t_stack *stack);
void		swap_ra(t_stack *stack, int value);
void		swap_rra(t_stack *stack, int value);
void		push_a(t_stack *stack);
void		push_b(t_stack *stack);
void		fast_swap_rra(t_stack *stack);
void		fast_swap_ssr(t_stack *stack);
void		display_resolved(t_stack *stack);
int			*stack_cpy(int *cpy, t_stack *stack);
int			is_stack_valid(t_stack *stack);
#endif
