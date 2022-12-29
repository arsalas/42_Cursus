#include <stdlib.h>
#include <time.h>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

// Destructor
Base::~Base()
{
	std::cout << "\e[0;31mDestructor called of Base\e[0m" << std::endl;
}

static int getRandomRange(int min, int max)
{
	srand(time(NULL));
	return min + std::rand() % (max - min + 1);
}

Base *generate()
{
	int random;

	random = getRandomRange(1, 3);
	if (random == 1)
		return new A;
	if (random == 2)
		return new B;
	return new C;
}

void identify(Base *p)
{
	A *a = dynamic_cast<A *>(p);
	if (a)
		std::cout << "A" << std::endl;
	B *b = dynamic_cast<B *>(p);
	if (b)
		std::cout << "B" << std::endl;
	C *c = dynamic_cast<C *>(p);
	if (c)
		std::cout << "C" << std::endl;
}
