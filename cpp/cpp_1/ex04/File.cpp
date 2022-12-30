/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 14:31:44 by aramirez          #+#    #+#             */
/*   Updated: 2022/05/05 15:16:36 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "File.hpp"

File::File(std::string filename) : _filename(filename){};

std::string File::getFilename()
{
	return (_filename);
}

void File::setFilename(std::string value)
{
	_filename = value;
}

void File::replaceFile(std::string s1, std::string s2)
{
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
			new_file << transform_line(line, s1, s2);
		}
	}
	_file.close();
	new_file.close();
}

std::string File::transform_line(std::string s, std::string s1, std::string s2)
{
	std::string new_line = "";
	int start = 0;
	std::string del = " ";
	int end = s.find(del);
	while (end != -1)
	{
		if (s.substr(start, end - start) == s1)
			new_line += s2;
		else
			new_line += s.substr(start, end - start);
		new_line += " ";
		start = end + del.size();
		end = s.find(del, start);
	}
	if (s.substr(start, end - start) == s1)
		new_line += s2;
	else
		new_line += s.substr(start, end - start);
	new_line += "\n";
	return (new_line);
}
