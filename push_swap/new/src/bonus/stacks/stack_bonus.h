/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 21:19:32 by aramirez          #+#    #+#             */
/*   Updated: 2023/02/09 15:29:40 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_BONUS_H
# define STACK_BONUS_H

typedef struct s_stack
{
	int	*stack;
	int	len;
}	t_stack;

void	create_stacks(t_stack *stack_a, t_stack *stack_b, int numbers);
void	destroy_stacks(t_stack *stack_a, t_stack *stack_b);
int		is_stack_sort(t_stack *stack);

#endif