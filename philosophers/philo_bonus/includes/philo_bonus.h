/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 18:07:25 by aramirez          #+#    #+#             */
/*   Updated: 2022/04/12 14:30:56 by aramirez         ###   ########.fr       */
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

# include "../../includes/colors.h" 

# define SEC 1000000
# define MS 100000
# define SEM_NAME "/semaphore_bonus"

typedef enum e_status
{
	FORK,
	EAT,
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

typedef struct s_data
{
	t_params		params;
	t_philo			*philos;
	int				forks;
	int				finish;
	bool			start;
	sem_t			*semaphore;
}	t_data;

typedef struct s_info
{
	t_data	*data;
	int		i;
}	t_info;

int			ft_atoi(const char *str);
long long	get_timestamp(void);
t_params	recive_args(char **argv);
void		print_log(int philo, t_status action);

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
bool		is_game_over(t_data *data);


#endif