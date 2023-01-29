#include <iostream>
#include <deque>
#include <vector>
#include <stack>

#include "test.hpp"
#include "stack.hpp"
#include "vector.hpp"

void stackTest()
{
	std::cout << BLU "╔═════════════════════════════════════════╗" << std::endl;
	std::cout << "║                  STACK                  ║" << std::endl;
	std::cout << "╚═════════════════════════════════════════╝" RESET << std::endl;

	std::cout << UCYN "Test member functions" RESET << std::endl;

	{
		std::cout << "constructor \t";
		std::deque<int> mydeque(3, 100);   // deque with 3 elements
		std::vector<int> myvector(2, 200); // vector with 2 elements

		std::deque<int> mydeque2(3, 100);  // deque with 3 elements
		ft::vector<int> myvector2(2, 200); // vector with 2 elements

		std::stack<int> first;							   // empty stack
		std::stack<int> second(mydeque);				   // stack initialized to copy of deque
		ft::stack<int> first2;							   // empty stack
		ft::stack<int, std::deque<int> > second2(mydeque2); // stack initialized to copy of deque

		std::stack<int, std::vector<int> > third; // empty stack using vector
		std::stack<int, std::vector<int> > fourth(myvector);
		ft::stack<int, ft::vector<int> > third2; // empty stack using vector
		ft::stack<int, ft::vector<int> > fourth2(myvector2);

		(first.size() == first2.size()) ? testOk() : testKo();
		(second.size() == second2.size()) ? testOk() : testKo();
		(third.size() == third2.size()) ? testOk() : testKo();
		(fourth.size() == fourth2.size()) ? testOk() : testKo();

		std::cout << std::endl;
	}
	{
		std::cout << "empty \t\t";

		std::stack<int> mystack;
		ft::stack<int> mystack2;
		int sum(0);
		int sum2(0);

		for (int i = 1; i <= 10; i++)
			mystack.push(i);
		for (int i = 1; i <= 10; i++)
			mystack2.push(i);

		while (!mystack.empty())
		{
			sum += mystack.top();
			mystack.pop();
		}
		while (!mystack2.empty())
		{
			sum2 += mystack2.top();
			mystack2.pop();
		}

		(sum == sum2) ? testOk() : testKo();
		std::cout << std::endl;
	}
	{
		std::cout << "size \t\t";
		std::stack<int> myints;
		ft::stack<int> myints2;

		(myints.size() == myints2.size()) ? testOk() : testKo();

		for (int i = 0; i < 5; i++)
			myints.push(i);
		for (int i = 0; i < 5; i++)
			myints2.push(i);
		(myints.size() == myints2.size()) ? testOk() : testKo();

		myints.pop();
		myints2.pop();
		(myints.size() == myints2.size()) ? testOk() : testKo();
		std::cout << std::endl;
	}
	{
		std::cout << "top \t\t";
		std::stack<int> mystack;
		ft::stack<int> mystack2;

		mystack.push(10);
		mystack2.push(10);
		(mystack.top() == mystack2.top()) ? testOk() : testKo();
		mystack.push(20);
		mystack2.push(20);
		(mystack.top() == mystack2.top()) ? testOk() : testKo();

		mystack.top() -= 5;
		mystack2.top() -= 5;
		(mystack.top() == mystack2.top()) ? testOk() : testKo();

		std::cout << std::endl;
	}
	{
		std::cout << "push \t\t";

		std::stack<int> mystack;
		ft::stack<int> mystack2;

		for (int i = 0; i < 5; ++i)
			mystack.push(i);
		for (int i = 0; i < 5; ++i)
			mystack2.push(i);

		while (!mystack.empty() && !mystack2.empty())
		{
			(mystack.top() == mystack2.top()) ? testOk() : testKo();
			mystack.pop();
			mystack2.pop();
		}

		std::cout << std::endl;
	}
	{
		std::cout << "pop \t\t";

		std::stack<int> mystack;
		ft::stack<int> mystack2;

		for (int i = 0; i < 5; ++i)
			mystack.push(i);
		for (int i = 0; i < 5; ++i)
			mystack2.push(i);

		while (!mystack.empty() && !mystack2.empty())
		{
			(mystack.top() == mystack2.top()) ? testOk() : testKo();
			mystack.pop();
			mystack2.pop();
		}

		std::cout << std::endl;
	}
	std::cout << UCYN "Test non member functions overload" RESET << std::endl;

	{
		std::cout << "swap \t\t";

		std::stack<int> foo, bar;
		ft::stack<int> foo2, bar2;
		foo.push(10);
		foo.push(20);
		foo.push(30);
		bar.push(111);
		bar.push(222);
		foo2.push(10);
		foo2.push(20);
		foo2.push(30);
		bar2.push(111);
		bar2.push(222);

		swap(foo, bar);
		swap(foo2, bar2);

		(foo.size() == foo2.size()) ? testOk() : testKo();
		(bar.size() == bar2.size()) ? testOk() : testKo();

		std::cout << std::endl;
	}
}