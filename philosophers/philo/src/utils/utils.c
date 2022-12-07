/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 12:28:58 by aramirez          #+#    #+#             */
/*   Updated: 2022/12/07 23:59:28 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief Comprueba si el el valor pasado es un digito
 * 
 * @param c digito
 * @return 1 si esun digito, 0 si no lo es
 */
int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

/**
 * @brief Comprueba si el caracter pasado es un delimitador de la funcion atoi
 * 
 * @param d caracter a comprobar
 * @return 1 si es delimitador 
 */
static int	is_atoi_delimiter(unsigned char d)
{
	if (d == ' ' || d == '\t' || d == '\n'
		|| d == '\f' || d == '\r' || d == '\v')
		return (1);
	else
		return (0);
}

/**
 * @brief Transforma un string en un int
 * 
 * @param str string a transformar
 * @return str pasado a int
 */
int	ft_atoi(const char *str)
{
	int	i;
	int	n;
	int	sign;

	i = 0;
	n = 0;
	while (is_atoi_delimiter(str[i]) == 1)
		i++;
	if (str[i] == '-')
		sign = -1;
	else
		sign = 1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (ft_isdigit(str[i]))
	{
		n = 10 * n + (str[i] - '0');
		i++;
	}
	return (sign * n);
}

/**
 * @brief Imprime por pantalla el log de la accion
 * 
 * @param data estructura de datos
 * @param philo id del filosofo
 * @param action accion a printar en el log
 */
void	print_log(t_data *data, int philo, t_status action)
{
	char	*desc;

	if (action == FORK)
		desc = BMAG "🍴 has taken a fork" RESET;
	else if (action == EAT)
		desc = BYEL "🍽️  is eating" RESET;
	else if (action == SLEEP)
		desc = BBLU "💤 is sleeping" RESET;
	else if (action == THINK)
		desc = BCYN "💭 is thiking" RESET;
	else if (action == DIE)
		desc = BRED "💀 died" RESET;
	else
		return ;
	pthread_mutex_lock(&data->log);
	if (!is_game_over(data))
		printf(UGRN "%lli" RESET BHWHT"\t%i\t" RESET "%s\n",
			get_timestamp() - data->timestamp, philo, desc);
	pthread_mutex_unlock(&data->log);
}
