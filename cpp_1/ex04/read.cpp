/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 14:31:44 by aramirez          #+#    #+#             */
/*   Updated: 2022/05/04 17:57:23 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read.hpp"

void File::replaceFile(std::string s1, std::string s2)
{
	(void)s1;
	(void)s2;
	_file.open(_filename);
	if (!_file)
	{
		std::cout << "Error al abrir el archivo" << std::endl;
		exit(0);
	}
	std::string line;
	std::string new_filename = _filename + ".replace";
	std::ofstream new_file;

	new_file.open(new_filename);

	if (_file.is_open())
	{
		while (!_file.eof())
		{
			std::getline(_file, line);

			int posInit = 0;
			int posFound = 0;
			std::string splitted;

			while (posFound >= 0)
			{
				posFound = line.find(s1, posInit);
				if (posFound > 0)
				{
					splitted += line.substr(posInit, posFound - posInit) + s2;
					posInit = posFound + 1;
				}
				else
				{
					splitted += line.substr(posInit + s1.length() - 1, line.length() - posInit - s1.length() + 1);
				}
			}
			new_file << splitted << std::endl;
		}
	}

	_file.close();
	new_file.close();
}
