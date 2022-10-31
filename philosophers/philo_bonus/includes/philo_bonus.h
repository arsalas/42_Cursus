/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 18:07:25 by aramirez          #+#    #+#             */
/*   Updated: 2022/06/06 16:09:28 by aramirez         ###   ########.fr       */
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

# include "colors.h"

# define SEC 1000000
# define MS 100000
# define SEM_FORK "/forks"
# define SEM_LOGS "/logs"
# define SEM_DIE "/die"
# define SEM_EAT "/eat"

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
	pid_t		c_pid;
	long long	last_food;
	long long	last_sleep;
	t_status	status;
}	t_philo;

typedef struct s_params
{
	int	n_philo;
	int	t_die;
	int	t_eat;
	int	t_sleep;
	int	time_eats;
}	t_params;

typedef struct s_sems
{
	sem_t			*sem_fork;
	sem_t			*sem_log;
	sem_t			*sem_die;
	sem_t			*sem_eat;
}	t_sems;

typedef struct s_data
{
	pthread_t		thread;
	int				i;
	t_params		params;
	t_philo			*philos;
	int				forks;
	int				finish;
	long			timestamp;
	bool			start;
	t_sems			sems;
}	t_data;

typedef struct s_info
{
	t_data	*data;
	int		i;
}	t_info;

int			ft_atoi(const char *str);
long long	get_timestamp(void);
t_params	recive_args(char **argv);
void		print_log(t_data *data, int philo, t_status action);

void		create_process(t_data *data);
void		process_start(t_data *data, int i);

void		*start_eat(void *p_data);
void		finish_eat(t_data *data, int philo_id);
void		start_sleep(t_data *data, int philo_id);
void		finish_sleep(t_data *data, int philo_id);

void		take_fork(t_data *data, int philo_id);
void		leave_fork(t_data *data);
int			next_fork(int pos, int max);
bool		can_take_fork(t_data *data);
void		philo_die(t_data *data, int philo_id);
bool		is_game_over(t_data *data);
void		close_program(t_data *data);

void		create_semaphores(t_data *data);
void		close_semaphores(t_data *data);
void		unlink_semaphores(t_data *data);


#endif