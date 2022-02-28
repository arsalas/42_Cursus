/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 21:19:32 by aramirez          #+#    #+#             */
/*   Updated: 2022/02/24 12:21:10 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include "./libft/libft.h"

void	sa(int *a);
void	sb(int *b);
void	ss(int *a, int *b);
void	pa(int *a, int *b);
void	pb(int *a, int *b);
void	ra(int *a);
void	rb(int *b);
void	rr(int *a, int *b);
void	rra(int *a);
void	rrb(int *b);
void	rrr(int *a, int *b);

int		get_len(int *stack);
void	swap_firsts(int *stack);
void	push_increment(int *stack, int num);
void	push_decrement(int *stack);
void	rotate(int *stack);
void	reverse(int *stack);
int		is_order(int *stack);
int		is_duplicate(int num, int *stack);
int		ft_isnumbervalid(char *num);
int		do_format(int argc, char *argv[], int *stack);
int		is_long(const char *str);

#endif