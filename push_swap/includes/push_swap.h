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

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <limits.h>
# include "libft.h"

# include <stdio.h>

typedef struct s_stack
{
	int	*stack;
	int	*original;
	int	len;
}	t_stack;

void	sa(t_stack *a, int print);
void	sb(t_stack *b, int print);
void	ss(t_stack *a, t_stack *b, int print);
void	pa(t_stack *a, t_stack *b, int print);
void	pb(t_stack *a, t_stack *b, int print);
void	ra(t_stack *a, int print);
void	rb(t_stack *b, int print);
void	rr(t_stack *a, t_stack *b, int print);
void	rra(t_stack *a, int print);
void	rrb(t_stack *b, int print);
void	rrr(t_stack *a, t_stack *b, int print);

void	swap_firsts(t_stack *stack);
void	push_increment(t_stack *stack, int num);
void	push_decrement(t_stack *stack);
void	rotate(t_stack *stack);
void	reverse(t_stack *stack);
int		is_order(t_stack *stack);
int		is_order_reverse(t_stack *stack);
int		is_duplicate(int num, t_stack *stack);
int		ft_isnumbervalid(char *num);
int		do_format(int argc, char *argv[], t_stack *stack);
int		is_long(const char *str);
void	new_order_array(t_stack *stack_a, t_stack *stack_b, int len);
int		is_smallest_stack(t_stack *stack, int len);
void	order_radial(t_stack *stack_a, t_stack *stack_b, int digit);
int		get_digits(int num);
int		get_digit(int num, int d);
int		get_max_num(t_stack *stack);
int		is_smallest_digit(t_stack *stack, int num, int digit);
int		is_smallest(t_stack *stack, int num);
int		is_order_digit(t_stack *stack, int digit);
int		find_position(t_stack *stack, int n);
int		positions_right(t_stack *stack, int find);
int		positions_right_digit(t_stack *stack, int find, int digit);
int		is_order_reverse_digit(t_stack *stack, int digit);
void	print_error(void);
void	create_stacks(t_stack *stack_a, t_stack *stack_b, int numbers);
void	get_positions(t_stack *stack);
void	simple_sort(t_stack *stack_a, t_stack *stack_b);
void	chunk_sort(t_stack *stack_a, t_stack *stack_b);
int		get_max(t_stack *stack);
int		get_chunk_numbers(t_stack *stack, int chunk, int nums);
int		positions_right_chunk(t_stack *stack, int chunk, int nums);
int		find_next_number(t_stack *stack, int num);
void	destroy_stacks(t_stack *stack_a, t_stack *stack_b);

#endif