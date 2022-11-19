/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 17:16:01 by aramirez          #+#    #+#             */
/*   Updated: 2022/05/06 13:48:18 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include "iostream"

class Zombie
{
	private:
		std::string	name;

	public:
		void	announce(void);
		void	set_name(std::string zombie_name);
		~Zombie();

};

Zombie	*zombieHorde(int N, std::string name);

#endif