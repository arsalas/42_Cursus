/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 21:19:32 by aramirez          #+#    #+#             */
/*   Updated: 2023/02/01 12:16:38 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

typedef struct s_stack
{
	int	*stack;
	int	len;
}	t_stack;

void	create_stacks(t_stack *stack_a, t_stack *stack_b, int numbers);
void	destroy_stacks(t_stack *stack_a, t_stack *stack_b);
int		is_stack_sort(t_stack *stack);

int		get_movs_rotate(t_stack *stack, int num);
int		get_movs_reverse(t_stack *stack, int num);
int		get_max_num_stack(t_stack *stack);
int		get_min_num_stack(t_stack *stack);
int		get_min_num_stack_position(t_stack *stack);

#endif