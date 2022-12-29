#ifndef MUTANT_STACK_H
#define MUTANT_STACK_H

#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
	// Constructors
	MutantStack<T>()
	{
		std::cout << "\e[0;33mDefault Constructor called of MutantStack\e[0m" << std::endl;
	}

	MutantStack<T>(const MutantStack &copy)
	{
		*this = copy;
		std::cout << "\e[0;33mCopy Constructor called of MutantStack\e[0m" << std::endl;
	}

	// Destructor
	~MutantStack<T>()
	{
		std::cout << "\e[0;31mDestructor called of MutantStack\e[0m" << std::endl;
	}

	// Operators
	MutantStack<T> &operator=(const MutantStack &assign)
	{
		(void)assign;
		return *this;
	}

	// Methods

	typedef typename std::stack<T>::container_type::iterator iterator;

	iterator begin(void)
	{
		return this->c.begin();
	}
	iterator end(void)
	{
		return this->c.end();
	}
};

#endif