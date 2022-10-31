/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 14:16:02 by aramirez          #+#    #+#             */
/*   Updated: 2022/05/04 16:36:36 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read.hpp"


int main(int argc, char **argv)
{
	std::string filename;
	std::string s1;
	std::string s2;

	if (argc < 4)
		return (0);
	filename = argv[1];
	s1 = argv[2];
	s2 = argv[3];

	File file(filename);
	file.replaceFile(s1, s2);
	

	return (0);
}
