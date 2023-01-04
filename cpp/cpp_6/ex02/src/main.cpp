#include <iostream>
#include "Base.hpp"

int main()
{
	Base *base;
	base = generate();
	identify(base);
	identify(*base);
	delete base;
	return 0;
}