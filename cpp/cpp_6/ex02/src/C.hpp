
#ifndef C_HPP
#define C_HPP

#include <iostream>
#include <string>
#include "Base.hpp"

class C : public Base
{
public:
	// Constructors
	C();
	C(const C &copy);

	// Destructor
	~C();

	// Operators
	C &operator=(const C &assign);
};

#endif