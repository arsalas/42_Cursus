/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semaphores_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 15:57:55 by aramirez          #+#    #+#             */
/*   Updated: 2022/12/10 17:40:36 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

/**
 * @brief Create a semaphores object
 * 
 * @param data estructura de datos del programa
 */
void	create_semaphores(t_data *data)
{
	data->sems.sem_fork = sem_open(SEM_FORK,
			O_CREAT | O_EXCL, S_IRUSR | S_IRWXU, data->params.n_philo);
	data->sems.sem_log = sem_open(SEM_LOGS,
			O_CREAT | O_EXCL, S_IRUSR | S_IRWXU, 1);
	data->sems.sem_die = sem_open(SEM_DIE,
			O_CREAT | O_EXCL, S_IRUSR | S_IRWXU, 0);
	data->sems.sem_eat = sem_open(SEM_EAT,
			O_CREAT | O_EXCL, S_IRUSR | S_IRWXU, 0);
	data->sems.sem_finish = sem_open(SEM_FINISH,
			O_CREAT | O_EXCL, S_IRUSR | S_IRWXU, data->params.n_philo);
}

/**
 * @brief Cierra los semaforos abiertos
 * 
 * @param data estructura de datos del programa
 */
void	close_semaphores(t_data *data)
{
	sem_close(data->sems.sem_fork);
	sem_close(data->sems.sem_log);
	sem_close(data->sems.sem_eat);
	sem_close(data->sems.sem_die);
	sem_close(data->sems.sem_finish);
}

/**
 * @brief Unlink los semaforos creados
 * 
 * @param data estructura de datos del programa
 */
void	unlink_semaphores(void)
{
	sem_unlink(SEM_FORK);
	sem_unlink(SEM_LOGS);
	sem_unlink(SEM_DIE);
	sem_unlink(SEM_EAT);
	sem_unlink(SEM_FINISH);
}
