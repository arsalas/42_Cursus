/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logs_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 23:29:21 by aramirez          #+#    #+#             */
/*   Updated: 2022/12/10 10:54:22 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	print_log_fork(t_data *data, int philo)
{
	sem_wait(data->sems.sem_log);
	print_log(data, philo, BMAG "🍴 has taken a fork" RESET);
	sem_post(data->sems.sem_log);
}

void	print_log_eat(t_data *data, int philo)
{
	sem_wait(data->sems.sem_log);
	print_log(data, philo, BYEL "🍽️  is eating" RESET);
	if (data->params.time_eats == -1)
		sem_post(data->sems.sem_log);
}

void	print_log_sleep(t_data *data, int philo)
{
	sem_wait(data->sems.sem_log);
	print_log(data, philo, BBLU "💤 is sleeping" RESET);
	sem_post(data->sems.sem_log);
}

void	print_log_think(t_data *data, int philo)
{
	sem_wait(data->sems.sem_log);
	print_log(data, philo, BCYN "💭 is thiking" RESET);
	sem_post(data->sems.sem_log);
}

void	print_log_die(t_data *data, int philo)
{
	sem_wait(data->sems.sem_log);
	print_log(data, philo, BRED "💀 died" RESET);
}
