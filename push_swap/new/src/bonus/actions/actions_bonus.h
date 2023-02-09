/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 21:19:32 by aramirez          #+#    #+#             */
/*   Updated: 2023/02/09 15:32:38 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACTIONS_BONUS_H
# define ACTIONS_BONUS_H

# include "stack_bonus.h"

typedef struct s_actions
{
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
}	t_actions;

void		sa(t_stack *a, int print);
void		sb(t_stack *b, int print);
void		ss(t_stack *a, t_stack *b, int print);
void		pa(t_stack *a, t_stack *b, int print);
void		pb(t_stack *a, t_stack *b, int print);
void		ra(t_stack *a, int print);
void		rb(t_stack *b, int print);
void		rr(t_stack *a, t_stack *b, int print);
void		rra(t_stack *a, int print);
void		rrb(t_stack *b, int print);
void		rrr(t_stack *a, t_stack *b, int print);

t_actions	new_action(void);
void		execute_actions(
				t_actions actions, t_stack *stack_a, t_stack *stack_b);

#endif