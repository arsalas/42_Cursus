#include <iostream>

#include "test.hpp"

void testOk()
{
	std::cout << GRN "[OK]" RESET;
}

void testKo()
{
	std::cout << RED "[KO]" RESET;
}