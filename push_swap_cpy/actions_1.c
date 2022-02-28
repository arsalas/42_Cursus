/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 12:53:32 by aramirez          #+#    #+#             */
/*   Updated: 2022/02/24 12:03:30 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
Intercambia los dos primeros numeros del stack a si hay mas de dos elementos
*/
void	sa(int *a)
{
	write(1, "sa\n", 3);
	swap_firsts(a);
}

/*
Intercambia los dos primeros numeros del stack b si hay mas de dos elementos
*/
void	sb(int *b)
{
	write(1, "sb\n", 3);
	swap_firsts(b);
}

/*
Intercambia los dos primeros numeros del stack a y b si hay mas de dos elementos
*/
void	ss(int *a, int *b)
{
	write(1, "ss\n", 3);
	swap_firsts(a);
	swap_firsts(b);
}

/*
Pone el primer elemento del stack a y lo pone en b
No hace nada si a esta vacio
*/
void	pa(int *a, int *b)
{
	write(1, "pa\n", 3);
	if (get_len(b) == 0)
		return ;
	push_increment(a, b[0]);
	push_decrement(b);
}

/*
Pone el primer elemento del stack a y lo pone en b
No hace nada si a esta vacio
*/
void	pb(int *a, int *b)
{
	write(1, "pb\n", 3);
	if (get_len(a) == 0)
		return ;
	push_increment(b, a[0]);
	push_decrement(a);
}
