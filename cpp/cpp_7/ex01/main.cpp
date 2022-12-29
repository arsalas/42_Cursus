#include <iostream>
#include <string>
#include "iter.hpp"

template <typename T>
void show(T &element)
{
	std::cout << "This element is " << element << std::endl;
}

int main()
{
	int arrNumbers[] = {10, 20, 30, 40};
	iter(arrNumbers, 4, &show);
	std::cout << std::endl;
	std::string arrStrings[] = {"Hola", "Mundo"};
	iter(arrStrings, 2, &show);
	std::cout << std::endl;
	float arrFloats[] = {10.5f, 20.5f, 30.5f, 40.5f};
	iter(arrFloats, 4, &show);
	std::cout << std::endl;
	return 0;
}
