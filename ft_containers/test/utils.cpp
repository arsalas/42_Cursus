#include <iostream>

#include "test.hpp"

void testOk()
{
	// std::cout << GRN "[OK]" RESET;
	std::cout << "✅";
}

void testKo()
{
	// std::cout << RED "[KO]" RESET;
	std::cout << "❌";
}