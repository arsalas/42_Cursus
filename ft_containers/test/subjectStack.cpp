#include <iostream>
#include <string>
#include <deque>

#include <stdlib.h>
#include <time.h>

#include <map>
#include <stack>
#include <vector>
#include "map.hpp"
#include "stack.hpp"
#include "vector.hpp"
#include "test.hpp"

#define MAX_RAM 429496729
#define BUFFER_SIZE 4096
struct Buffer
{
	int idx;
	char buff[BUFFER_SIZE];
};

#define COUNT (MAX_RAM / (int)sizeof(Buffer))

template <typename T>
class MutantStack : public ft::stack<T>
{
public:
	MutantStack() {}
	MutantStack(const MutantStack<T> &src) { *this = src; }
	MutantStack<T> &operator=(const MutantStack<T> &rhs)
	{
		this->c = rhs.c;
		return *this;
	}
	~MutantStack() {}

	typedef typename ft::stack<T>::container_type::iterator iterator;

	iterator begin() { return this->c.begin(); }
	iterator end() { return this->c.end(); }
};
template <typename T>
class MutantStack2 : public std::stack<T>
{
public:
	MutantStack2() {}
	MutantStack2(const MutantStack2<T> &src) { *this = src; }
	MutantStack2<T> &operator=(const MutantStack2<T> &rhs)
	{
		this->c = rhs.c;
		return *this;
	}
	~MutantStack2() {}

	typedef typename std::stack<T>::container_type::iterator iterator;

	iterator begin() { return this->c.begin(); }
	iterator end() { return this->c.end(); }
};

void testStackSubject()
{

	const int seed = atoi("1");
	srand(seed);

	double time_spent = 0.0;

	clock_t begin = clock();

	{
		std::cout << "content\t\t";
		ft::stack<int> stack_int;
		ft::stack<Buffer, std::deque<Buffer> > stack_deq_buffer;

		MutantStack<char> iterable_stack;
		for (char letter = 'a'; letter <= 'z'; letter++)
			iterable_stack.push(letter);
		char letter = 'a';
		bool ok = true;
		for (MutantStack<char>::iterator it = iterable_stack.begin(); it != iterable_stack.end(); it++)
		{
			if (*it != letter)
				ok = false;
			letter++;
		}
		(ok) ? testOk() : testKo();
	}

	clock_t end = clock();

	time_spent += (double)(end - begin) / CLOCKS_PER_SEC;

	double time_spent2 = 0.0;

	clock_t begin2 = clock();

	{
		std::stack<int> stack_int;
		std::stack<Buffer, std::deque<Buffer> > stack_deq_buffer;

		MutantStack2<char> iterable_stack;
		for (char letter = 'a'; letter <= 'z'; letter++)
			iterable_stack.push(letter);
		for (MutantStack2<char>::iterator it = iterable_stack.begin(); it != iterable_stack.end(); it++)
		{
		}
	}

	clock_t end2 = clock();

	time_spent2 += (double)(end2 - begin2) / CLOCKS_PER_SEC;
	std::cout << "\n";
	std::cout << "time\t\t";
	(time_spent <= time_spent2 * 20) ? testOk() : testKo();
	std::cout << "\n";
	std::cout << "\n";
	std::cout << UMAG "Result Time" RESET << std::endl;
	std::cout << YEL "Time ft::stack:\t\t" << time_spent << "s" RESET << std::endl;
	std::cout << YEL "Time std::stack:\t" << time_spent2 << "s" RESET << std::endl;
	if (time_spent > time_spent2 * 20)
		std::cout << RED "ft::stack time must be less than " <<  time_spent2 * 20 << "s" RESET << std::endl;

}