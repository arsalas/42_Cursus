/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 14:32:32 by aramirez          #+#    #+#             */
/*   Updated: 2022/05/04 16:36:27 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Read_H
#define Read_H
# include "iostream"
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
	
};

#endif