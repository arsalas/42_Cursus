/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 14:19:47 by aramirez          #+#    #+#             */
/*   Updated: 2022/06/08 16:58:30 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

/**
 * @brief Cierra los semaforos al cerrar el programa
 * 
 * @param data estructura de datos del programa
 */
void	close_program(t_data *data)
{
	sem_close(data->sems.sem_fork);
	sem_close(data->sems.sem_log);
	sem_close(data->sems.sem_die);
	sem_close(data->sems.sem_eat);
	exit(0);
}
