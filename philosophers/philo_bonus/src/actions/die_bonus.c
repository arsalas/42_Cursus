/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   die_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 18:16:21 by aramirez          #+#    #+#             */
/*   Updated: 2022/06/07 14:14:49 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

/**
 * Printa el log y pone el estado del filosofo como muerto
*/
void	philo_die(t_data *data, int philo_id)
{
	print_log(data, philo_id + 1, DIE);
	data->philo.is_alive = false;
}
