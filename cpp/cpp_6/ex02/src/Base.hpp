#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <string>

class Base
{
public:
	// Destructor
	virtual ~Base();
};

Base *generate();
void identify(Base *p);
void identify(Base &p);

#endif