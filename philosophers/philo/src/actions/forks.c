/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 18:16:26 by aramirez          #+#    #+#             */
/*   Updated: 2022/12/10 01:08:27 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief Obtiene la posicion en el array del siguiente tenedor al filosofo 
 * 
 * @param pos posicion en la array del filosofo
 * @param max length de la array
 * @return posicion del tenedor
 */
int	next_fork(int pos, int max)
{
	if (pos == max - 1)
		return (0);
	else
		return (pos + 1);
}
