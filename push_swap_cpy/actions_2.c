/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 12:53:32 by aramirez          #+#    #+#             */
/*   Updated: 2022/02/24 12:04:21 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
Desplaza hacia arriba todos los elementos del stack a,
el primero pasa a ser el ultimo
*/
void	ra(int *a)
{
	write(1, "ra\n", 3);
	if (get_len(a) == 0)
		return ;
	rotate(a);
}

/*
Desplaza hacia arriba todos los elementos del stack b,
el primero pasa a ser el ultimo
*/
void	rb(int *b)
{
	write(1, "rb\n", 3);
	if (get_len(b) == 0)
		return ;
	rotate(b);
}

/*
Desplaza hacia arriba todos los elementos del stack a y b,
el primero pasa a ser el ultimo
*/
void	rr(int *a, int *b)
{
	write(1, "rr\n", 3);
	rotate(a);
	rotate(b);
}

/*
Desplaza hacia abajo todos los elementos del stack a,
el ultimo pasa a ser el primero
*/
void	rra(int *a)
{
	write(1, "rra\n", 4);
	if (get_len(a) == 0)
		return ;
	reverse(a);
}

/*
Desplaza hacia abajo todos los elementos del stack b,
el ultimo pasa a ser el primero
*/
void	rrb(int *b)
{
	write(1, "rrb\n", 4);
	if (get_len(b) == 0)
		return ;
	reverse(b);
}
