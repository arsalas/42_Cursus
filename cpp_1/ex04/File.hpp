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
# include <iostream>
# include <fstream>

class File
{
private:
	std::string _filename;
	std::ifstream _file;

public:
	File(std::string filename) : _filename(filename){};
	std::string getFilename(void) { return (_filename); }
	void setFilename(std::string value) { _filename = value; }
	void replaceFile(std::string s1, std::string s2);
	std::string transform_line(std::string s, std::string s1, std::string s2);
};

#endif