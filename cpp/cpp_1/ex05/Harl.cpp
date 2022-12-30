/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 15:21:45 by aramirez          #+#    #+#             */
/*   Updated: 2022/12/12 17:21:08 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug()
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!\e[0;37m" << std::endl;
}

void Harl::info()
{
	std::cout << "\e[0;36m“I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\e[0;37m" << std::endl;
}

void Harl::warning()
{
	std::cout << "\e[0;33mI think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.\e[0;37m" << std::endl;
}

void Harl::error()
{
	std::cout << "\e[0;31mThis is unacceptable! I want to speak to the manager now.\e[0;37m" << std::endl;
}

Harl::Harl()
{
	_levels[0].level = "debug";
	_levels[0].ptr = &Harl::debug;
	_levels[1].level = "info";
	_levels[1].ptr = &Harl::info;
	_levels[2].level = "warning";
	_levels[2].ptr = &Harl::warning;
	_levels[3].level = "error";
	_levels[3].ptr = &Harl::error;
}

void Harl::complain(std::string level)
{
	for (int i = 0; i < 4; i++)
	{
		if (_levels[i].level == level)
			(this->*(_levels[i].ptr))();
	}
}