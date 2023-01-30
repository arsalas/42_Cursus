/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 15:54:32 by aramirez          #+#    #+#             */
/*   Updated: 2022/05/23 14:26:10 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

/**
 * @brief Printa error en pantalla
 * 
 */
void	print_error(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

