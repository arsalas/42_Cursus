#include "A.hpp"

// Constructors
A::A()
{
	std::cout << "\e[0;33mDefault Constructor called of A\e[0m" << std::endl;
}

A::A(const A &copy)
{
	(void)copy;
	std::cout << "\e[0;33mCopy Constructor called of A\e[0m" << std::endl;
}

// Destructor
A::~A()
{
	std::cout << "\e[0;31mDestructor called of A\e[0m" << std::endl;
}

// Operators
A &A::operator=(const A &assign)
{
	(void)assign;
	return *this;
}
