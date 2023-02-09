/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 12:03:02 by aramirez          #+#    #+#             */
/*   Updated: 2023/02/01 12:33:49 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORTING_H
# define SORTING_H
# include "stack.h"
# include "actions.h"

typedef enum e_options_type
{
	ROT,
	REV,
	ROT_REV,
	REV_ROT
}	t_options_type;

typedef struct s_option
{
	int				movs_rotate_a;
	int				movs_rotate_b;
	int				movs_reverse_a;
	int				movs_reverse_b;
	int				quantity_moves;
	t_options_type	type;

}	t_option;

void			sort_stacks(t_stack *stack_a, t_stack *stack_b);
void			calc_min_actions_by_moves(t_option *option);
t_options_type	get_type(int rot, int rev, int rot_rev, int rev_rot);
t_option		get_min_actions_a(t_stack *stack_a, t_stack *stack_b, int obj);
t_option		get_min_actions_b(t_stack *stack_a, t_stack *stack_b, int obj);
t_actions		calc_actions(t_option option);
t_actions		get_moves_sort_a(t_stack *stack_a, t_stack *stack_b);
t_actions		get_moves_sort_b(t_stack *stack_a, t_stack *stack_b);

#endif
