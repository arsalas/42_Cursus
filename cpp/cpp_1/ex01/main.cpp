/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 17:05:30 by aramirez          #+#    #+#             */
/*   Updated: 2022/12/12 16:21:24 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name);

int main(void)
{
	int n = 10;

	Zombie *zombies = zombieHorde(n, "Zombie");
	for (int i = 0; i < n; ++i)
	{
		zombies[i].announce();
	}
	delete[] zombies;
	return (0);
}