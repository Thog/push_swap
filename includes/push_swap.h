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

typedef struct		s_val
{
	int				value;
	struct s_val	*prev;
	struct s_val	*next;
}					t_val;

void				pushback(t_val **lst, int value);
void				pushfront(t_val **lst, int value);
void				pop(t_val **lst);
void				shift(t_val **lst);
t_val				*create_val();
void				destroy_val(t_val *lst);
void				clear_val(t_val **stack_a, t_val **stack_b);
void				push_swap(t_val *stack_a, t_val *stack_b);
#endif
