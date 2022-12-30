/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 14:32:32 by aramirez          #+#    #+#             */
/*   Updated: 2022/12/12 17:20:46 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_H
#define HARL_H
#include <iostream>

class Harl
{
	typedef struct s_status
	{
		std::string level;
		void (Harl::*ptr)(void);

	} level_s;

private:
	level_s _levels[4];
	void debug(void);
	void info(void);
	void warning(void);
	void error(void);

public:
	Harl(void);
	void complain(std::string level);
};

#endif