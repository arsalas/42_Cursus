/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 21:19:32 by aramirez          #+#    #+#             */
/*   Updated: 2022/05/25 14:21:52 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

typedef struct s_stack
{
	int	*stack;
	int	*original;
	int	len;
}	t_stack;

void	create_stacks(t_stack *stack_a, t_stack *stack_b, int numbers);
void	destroy_stacks(t_stack *stack_a, t_stack *stack_b);

#endif