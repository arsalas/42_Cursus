#include <iostream>
#include "debug.hpp"

void printDebug(const std::string msg)
{
	if (!DEBUG)
		return;
	std::cout << msg;
}