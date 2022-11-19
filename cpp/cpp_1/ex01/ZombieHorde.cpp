/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 13:53:22 by aramirez          #+#    #+#             */
/*   Updated: 2022/05/03 16:16:24 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"


Zombie	*zombieHorde(int N, std::string name)
{
	Zombie *zombies = new Zombie[N];

    for (int i = 0; i < N; ++i)
    {
        zombies[i].set_name(name);
    }
	return (zombies);
}