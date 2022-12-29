#include "C.hpp"

// Constructors
C::C()
{
	std::cout << "\e[0;33mDefault Constructor called of C\e[0m" << std::endl;
}

C::C(const C &copy)
{
	(void)copy;
	std::cout << "\e[0;33mCopy Constructor called of C\e[0m" << std::endl;
}

// Destructor
C::~C()
{
	std::cout << "\e[0;31mDestructor called of C\e[0m" << std::endl;
}

// Operators
C &C::operator=(const C &assign)
{
	(void)assign;
	return *this;
}
