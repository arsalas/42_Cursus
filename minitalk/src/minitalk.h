/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 17:25:43 by aramirez          #+#    #+#             */
/*   Updated: 2022/05/26 17:28:03 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include "libft.h"
# include "ft_printf.h"

# define TIME_SLP 200
# define BYTES_S 8

# define BLK "\e[0;30m"
# define RED "\e[0;31m"
# define GRN "\e[0;32m"
# define YEL "\e[0;33m"
# define BLU "\e[0;34m"
# define MAG "\e[0;35m"
# define CYN "\e[0;36m"
# define WHT "\e[0;37m"
# define RESET "\e[0m"

typedef struct s_bin
{
	int		current;
	char	bit[BYTES_S];
	int		started;
}	t_bin;

#endif