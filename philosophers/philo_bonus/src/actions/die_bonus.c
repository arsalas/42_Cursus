/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   die_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 18:16:21 by aramirez          #+#    #+#             */
/*   Updated: 2022/12/10 10:52:05 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

/**
 * @brief Printa el log y pone el estado del filosofo como muerto
 * 
 * @param data Estructura de datos del programa
 * @param philo_id id del filosofo
 */
void	philo_die(t_data *data, int philo_id)
{
	print_log_die(data, philo_id);
	data->philo.is_alive = false;
}
