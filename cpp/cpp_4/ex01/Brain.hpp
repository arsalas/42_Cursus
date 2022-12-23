/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 14:32:32 by aramirez          #+#    #+#             */
/*   Updated: 2022/12/23 19:53:53 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Brain_H
#define Brain_H
#include <iostream>

class Brain
{
private:
	static const int numberIdeas = 100;
	std::string _ideas[numberIdeas];

public:
	Brain();
	~Brain();

	Brain(const Brain &brain);

	Brain &operator=(const Brain &brain);
};

#endif
