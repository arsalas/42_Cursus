/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 12:06:02 by aramirez          #+#    #+#             */
/*   Updated: 2023/02/01 12:06:28 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	max(int n1, int n2)
{
	if (n1 > n2)
		return (n1);
	return (n2);
}

int	min(int n1, int n2)
{
	if (n1 > n2)
		return (n2);
	return (n1);
}

int	abs(int n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}
