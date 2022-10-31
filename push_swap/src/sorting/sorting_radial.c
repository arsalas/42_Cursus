/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_radial.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 15:21:03 by aramirez          #+#    #+#             */
/*   Updated: 2022/05/20 18:50:44 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Comprueba si el primer numero del stack es el mas pequeño
 * 
 * @param stack stack a utilizar
 * @param digit digito utilizado
 * @return 1 si es el mas pequeño 0 si no lo es
 */
int	can_push(t_stack *stack, int digit)
{
	if (is_smallest_digit(stack, get_digit(stack->stack[0], digit), digit) == 1)
		return (1);
	return (0);
}

/**
 * @brief Comprueba si el primer numero del stack es mas grande que el segundo
 * 
 * @param stack stack a utilizar
 * @param digit digito usado
 * @return 1 si es el mas grande 0 si no lo es
 */
int	can_swap(t_stack *stack, int digit)
{
	if (get_digit(stack->stack[0], digit) > get_digit(stack->stack[1], digit))
		return (1);
	return (0);
}

/**
 * @brief Comprueba si el numero a buscar esta mas cerca por la derecha 
 * 
 * @param stack_a stack a
 * @param stack_b stack b
 * @param digit digito utilizado 
 * @return 1 si el numero buscado esta mas a la derecha 0 si esta a la izquierda
 */
int	can_right(t_stack *stack_a, t_stack *stack_b, int digit)
{
	if (positions_right_digit(stack_a, get_digit(stack_b->stack[0], digit),
			digit) + 1 > stack_a->len / 2)
		return (1);
	return (0);
}

/**
 * @brief Ordena la array 
 * 
 * @param stack_a stack a
 * @param stack_b stack b
 */
void	order_array(t_stack *stack_a, t_stack *stack_b)
{
	while (is_order(stack_a) == 0)
	{
		if (is_smallest(stack_a, stack_a->stack[0]) == 1)
			pb(stack_a, stack_b, 1);
		else if (stack_a->stack[0] > stack_a->stack[1])
			sa(stack_a, 1);
		else if (positions_right(stack_a, stack_b->stack[0] + 1)
			> stack_a->len / 2)
			rra(stack_a, 1);
		else
			ra(stack_a, 1);
	}
	while (stack_b->len > 0)
		pa(stack_a, stack_b, 1);
}

/**
 * @brief Ordena del array por radix sort 
 * 
 * @param stack_a stack a
 * @param stack_b stack b
 * @param digit digito de radix
 */
void	order_radial(t_stack *stack_a, t_stack *stack_b, int digit)
{
	int	digits;

	digits = get_digits(get_max_num(stack_a));
	while (digit <= digits)
	{
		while (is_order_digit(stack_a, digit) == 0)
		{
			if (can_push(stack_a, digit))
				pb(stack_a, stack_b, 1);
			else if (can_swap(stack_a, digit))
				sa(stack_a, 1);
			else if (can_right(stack_a, stack_b, digit) == 1)
				rra(stack_a, 1);
			else
				ra(stack_a, 1);
		}
		while (stack_b->len > 0)
			pa(stack_a, stack_b, 1);
		digit++;
	}
	order_array(stack_a, stack_b);
}
