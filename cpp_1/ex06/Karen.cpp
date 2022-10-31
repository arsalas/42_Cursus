/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 15:21:45 by aramirez          #+#    #+#             */
/*   Updated: 2022/05/05 18:47:12 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

void Karen::debug(void)
{
	std::cout << "[DEBUG]" << std::endl;
	std::cout << "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it!\e[0;37m" << std::endl;
}

void Karen::info(void)
{
	std::cout << "\e[0;36m[INFO]\e[0;37m" << std::endl;
	std::cout << "\e[0;36mI cannot believe adding extra bacon cost more money. You don’t put enough! If you did I would not have to ask for it!\e[0;37m" << std::endl;
}

void Karen::warning(void)
{
	std::cout << "\e[0;33m[WARNING]\e[0;37m" << std::endl;
	std::cout << "\e[0;33mI think I deserve to have some extra bacon for free. I’ve been coming here for years and you just started working here last month..\e[0;37m" << std::endl;
}

void Karen::error(void)
{
	std::cout << "\e[0;31m[ERROR]\e[0;37m" << std::endl;
	std::cout << "\e[0;31mThis is unacceptable, I want to speak to the manager now.\e[0;37m" << std::endl;
}

Karen::Karen(std::string filter)
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
	levels[0].level = "debug";
	levels[0].ptr = &Karen::debug;
	levels[1].level = "info";
	levels[1].ptr = &Karen::info;
	levels[2].level = "warning";
	levels[2].ptr = &Karen::warning;
	levels[3].level = "error";
	levels[3].ptr = &Karen::error;
}

void Karen::complain(std::string level)
{
	if (_filter == NONE)
	{
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		if (levels[i].level == level)
		{
			if (i >= _filter)
				(this->*(levels[i].ptr))();
		}
	}
}