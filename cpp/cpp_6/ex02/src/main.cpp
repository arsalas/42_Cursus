#include <iostream>
#include "Base.hpp"
#include "B.hpp"

int main()
{
	Base *base;
	base = generate();
	identify(base);
	delete base;
	return 0;
}