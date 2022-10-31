/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 14:32:32 by aramirez          #+#    #+#             */
/*   Updated: 2022/05/05 18:42:16 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KAREN_H
#define KAREN_H
#include <iostream>

// enum class e_filters
// {
// 	DEBUG,
// 	INFO,
// 	WARNING,
// 	ERROR,
// 	NONE
// };

typedef enum filters
{
	DEBUG,
	INFO,
	WARNING,
	ERROR,
	NONE
} e_filters;

class Karen
{
	typedef struct s_status
	{
		std::string level;
		void (Karen::*ptr)(void);

	} level_s;

private:
	level_s levels[4];
	e_filters _filter;

private:
	void debug(void);
	void info(void);
	void warning(void);
	void error(void);

public:
	Karen(std::string filter);
	void complain(std::string level);
};

#endif