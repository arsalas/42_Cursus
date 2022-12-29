#include <iostream>
#include "Conversor.hpp"

int main(int argc, char const *argv[])
{
	if (argc != 2)
	{
		std::cout << "Incorrect arguments number" << std::endl;
		return 1;
	}
	Conversor a = Conversor(argv[1]);
	std::cout << "char: " << a.parseChar() << std::endl;
	return 0;
}
