/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 17:25:43 by aramirez          #+#    #+#             */
/*   Updated: 2022/03/02 19:36:36 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include "./libft/libft.h"
# include "./printf/ft_printf.h"

typedef struct s_bin
{
	int		current;
	char	bit[8];
	int		started;
}	t_bin;

#endif