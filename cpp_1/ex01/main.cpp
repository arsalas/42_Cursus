/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 17:05:30 by aramirez          #+#    #+#             */
/*   Updated: 2022/05/03 16:20:16 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	int		n = 10;
	Zombie	*zombies = zombieHorde(n, "Zombie");
	for (int i = 0; i < n; ++i)
	{
        zombies[i].announce();
    }
    delete [] zombies;
	return (0);
}