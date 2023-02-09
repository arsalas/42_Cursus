/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 21:19:32 by aramirez          #+#    #+#             */
/*   Updated: 2023/02/09 15:31:35 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HELPERS_BONUS_H
# define HELPERS_BONUS_H

# include "stack_bonus.h"

void	swap_firsts(t_stack *stack);
void	push_increment(t_stack *stack, int num);
void	push_decrement(t_stack *stack);
void	rotate(t_stack *stack);
void	reverse(t_stack *stack);

#endif