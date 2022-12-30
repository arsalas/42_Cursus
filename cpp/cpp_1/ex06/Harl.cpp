/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 15:21:45 by aramirez          #+#    #+#             */
/*   Updated: 2022/12/12 18:55:33 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug()
{
	std::cout << "[DEBUG]" << std::endl;
	std::cout << "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it!\e[0;37m" << std::endl;
}

void Harl::info()
{
	std::cout << "\e[0;36m[INFO]\e[0;37m" << std::endl;
	std::cout << "\e[0;36mI cannot believe adding extra bacon cost more money. You don’t put enough! If you did I would not have to ask for it!\e[0;37m" << std::endl;
}

void Harl::warning()
{
	std::cout << "\e[0;33m[WARNING]\e[0;37m" << std::endl;
	std::cout << "\e[0;33mI think I deserve to have some extra bacon for free. I’ve been coming here for years and you just started working here last month..\e[0;37m" << std::endl;
}

void Harl::error()
{
	std::cout << "\e[0;31m[ERROR]\e[0;37m" << std::endl;
	std::cout << "\e[0;31mThis is unacceptable, I want to speak to the manager now.\e[0;37m" << std::endl;
}

Harl::Harl(std::string filter)
{
	if (filter == "DEBUG")
		_filter = DEBUG;
	else if (filter == "INFO")
		_filter = INFO;
	else if (filter == "WARNING")
		_filter = WARNING;
	else if (filter == "ERROR")
		_filter = ERROR;
	else
		_filter = NONE;
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
	if (_filter == NONE)
	{
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		if (_levels[i].level == level)
		{
			if (i >= _filter)
				(this->*(_levels[i].ptr))();
		}
	}
}