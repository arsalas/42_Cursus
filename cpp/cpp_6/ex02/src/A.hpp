#ifndef A_HPP
#define A_HPP

#include <iostream>
#include <string>
#include "Base.hpp"

class A : public Base
{
public:
	// Constructors
	A();
	A(const A &copy);

	// Destructor
	~A();

	// Operators
	A &operator=(const A &assign);
};

#endif