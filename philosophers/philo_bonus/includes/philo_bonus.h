/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 18:07:25 by aramirez          #+#    #+#             */
/*   Updated: 2022/12/09 12:42:11 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdbool.h>
# include <semaphore.h>
# include <signal.h>

# include "colors.h"

# define SEC 1000000
# define MS 100000
# define SEM_FORK "/sem_forks"
# define SEM_LOGS "/sem_logs"
# define SEM_DIE "/sem_die"
# define SEM_EAT "/sem_eat"
# define SEM_START "/sem_start"
# define SEM_FINISH "/sem_finish"
# define SEM_ACTION "/sem_action"

typedef enum e_status
{
	FORK,
	EAT,
	WAITNG_FORK,
	SLEEP,
	THINK,
	DIE
}	t_status;

typedef struct s_philo
{
	int			id;
	int			n_eat;
	bool		is_alive;
	long long	last_food;
	long long	last_sleep;
	t_status	status;
}	t_philo;

typedef struct s_params
{
	int		n_philo;
	int		t_die;
	int		t_eat;
	int		t_sleep;
	int		time_eats;
	bool	correct_format;
}	t_params;

typedef struct s_thread
{
	pthread_t	die;
	pthread_t	eat;
	pthread_t	life;
}	t_thread;

typedef struct s_sems
{
	sem_t			*sem_fork;
	sem_t			*sem_log;
	sem_t			*sem_die;
	sem_t			*sem_eat;
	sem_t			*sem_start;
	sem_t			*sem_finish;
	sem_t			*sem_action;
}	t_sems;

typedef struct s_data
{
	t_params		params;
	t_philo			philo;
	pid_t			*id_forks;
	t_sems			sems;
	t_thread		threads;
	long long		timestamp;
	long long		time_to_start;
	bool			start;
}	t_data;

int			ft_atoi(const char *str);
long long	get_timestamp(void);
t_params	recive_args(char **argv);
void		print_log(t_data *data, int philo, t_status action);

void		create_process(t_data *data);
void		process_start(t_data *data, int i);

void		start_eat(t_data *data, int philo_id);
void		finish_eat(t_data *data, int philo_id);
void		start_sleep(t_data *data, int philo_id);
void		finish_sleep(t_data *data, int philo_id);

void		take_fork(t_data *data, int philo_id);
void		leave_fork(t_data *data);
int			next_fork(int pos, int max);
bool		can_take_fork(t_data *data);
void		philo_die(t_data *data, int philo_id);
void		*is_game_finish(void *info);
void		close_program(t_data *data);

void		create_semaphores(t_data *data);
void		close_semaphores(t_data *data);
void		unlink_semaphores(void);

void		*th_philo_die(void *info);
void		*th_philos_eat(void *info);
void		start_threads(t_data *data);
void		exit_program(t_data *data);
void		my_usleep(int num);
t_philo		start_philo(int i);

#endif