/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 14:32:32 by aramirez          #+#    #+#             */
/*   Updated: 2022/05/05 15:22:16 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_H
#define FILE_H
#include <iostream>
#include <fstream>
// #include <sstream>

class File
{
private:
	std::string _filename;
	std::ifstream _file;

public:
	File(std::string filename);
	std::string getFilename();
	void setFilename(std::string value);
	void replaceFile(std::string s1, std::string s2);
	std::string transform_line(std::string s, std::string s1, std::string s2);
};

#endif