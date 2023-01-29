#include <iostream>
#include <vector>

#include "test.hpp"
#include "vector.hpp"

void vectorTest()
{
	std::cout << BLU "╔═════════════════════════════════════════╗" << std::endl;
	std::cout << "║                  VECTOR                 ║" << std::endl;
	std::cout << "╚═════════════════════════════════════════╝" RESET << std::endl;

	std::cout << UCYN "Test constructors" RESET << std::endl;

	{
		std::cout << "default\t\t";

		// constructors used in the same order as described above:
		std::vector<int> first; // empty vector of ints
		ft::vector<int> first2;

		(first.size() == first2.size()) ? testOk() : testKo();

		std::cout << '\n';
	}
	{
		std::cout << "fill\t\t";

		std::vector<int> second(4, 100);
		ft::vector<int> second2(4, 100);

		ft::vector<int>::iterator it2 = second2.begin();
		for (std::vector<int>::iterator it = second.begin(); it != second.end(); ++it)
		{
			(*it == *it2) ? testOk() : testKo();
			++it2;
		}
		std::cout << '\n';
	}
	{
		std::cout << "range\t\t";

		std::vector<int> first(4, 100);
		ft::vector<int> first2(4, 100);

		std::vector<int> second(first.begin(), first.end());
		ft::vector<int> second2(first2.begin(), first2.end());

		ft::vector<int>::iterator it2 = second2.begin();
		for (std::vector<int>::iterator it = second.begin(); it != second.end(); ++it)
		{
			(*it == *it2) ? testOk() : testKo();
			++it2;
		}
		std::cout << '\n';
	}
	{
		std::cout << "copy\t\t";

		std::vector<int> first(4, 100);
		ft::vector<int> first2(4, 100);

		std::vector<int> second(first);
		ft::vector<int> second2(first2);

		ft::vector<int>::iterator it2 = second2.begin();
		for (std::vector<int>::iterator it = second.begin(); it != second.end(); ++it)
		{
			(*it == *it2) ? testOk() : testKo();
			++it2;
		}
		std::cout << '\n';
	}

	{
		std::cout << "operator=\t";

		std::vector<int> foo(3, 0);
		std::vector<int> bar(5, 0);
		ft::vector<int> foo2(3, 0);
		ft::vector<int> bar2(5, 0);

		bar = foo;
		bar2 = foo2;
		foo = std::vector<int>();
		foo2 = ft::vector<int>();

		(foo.size() == foo2.size()) ? testOk() : testKo();
		(bar.size() == bar2.size()) ? testOk() : testKo();

		std::cout << '\n';
	}

	std::cout << UCYN "Test iterators" RESET << std::endl;
	{
		std::cout << "begin\t\t";

		std::vector<int> myvector;
		ft::vector<int> myvector2;
		for (int i = 1; i <= 5; i++)
			myvector.push_back(i);
		for (int i = 1; i <= 5; i++)
			myvector2.push_back(i);

		ft::vector<int>::iterator it2 = myvector2.begin();
		int i = 0, i2 = 0;
		for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
		{
			(*it == *it2) ? testOk() : testKo();
			++it2;
			i++;
		}
		for (ft::vector<int>::iterator it = myvector2.begin(); it != myvector2.end(); ++it)
		{
			i2++;
		}
		(i == i2) ? testOk() : testKo();

		std::cout << '\n';
	}
	{
		std::cout << "end\t\t";

		std::vector<int> myvector;
		ft::vector<int> myvector2;
		for (int i = 1; i <= 5; i++)
			myvector.push_back(i);
		for (int i = 1; i <= 5; i++)
			myvector2.push_back(i);

		ft::vector<int>::iterator it2 = myvector2.begin();
		int i = 0, i2 = 0;
		for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
		{
			(*it == *it2) ? testOk() : testKo();
			++it2;
			i++;
		}
		for (ft::vector<int>::iterator it = myvector2.begin(); it != myvector2.end(); ++it)
		{
			i2++;
		}
		(i == i2) ? testOk() : testKo();

		std::cout << '\n';
	}
	{
		std::cout << "rbegin\t\t";

		std::vector<int> myvector(5); // 5 default-constructed ints
		ft::vector<int> myvector2(5); // 5 default-constructed ints

		int i = 0;
		int i2 = 0;

		std::vector<int>::reverse_iterator rit = myvector.rbegin();
		ft::vector<int>::reverse_iterator rit2 = myvector2.rbegin();
		for (; rit != myvector.rend(); ++rit)
			*rit = ++i;
		for (; rit2 != myvector2.rend(); ++rit2)
			*rit2 = ++i2;

		ft::vector<int>::iterator it2 = myvector2.begin();
		for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
		{
			(*it == *it2) ? testOk() : testKo();
			++it2;
		}
		(i == i2) ? testOk() : testKo();

		std::cout << '\n';
	}
	{
		std::cout << "rend\t\t";

		std::vector<int> myvector(5); // 5 default-constructed ints
		ft::vector<int> myvector2(5); // 5 default-constructed ints

		std::vector<int>::reverse_iterator rit = myvector.rbegin();
		ft::vector<int>::reverse_iterator rit2 = myvector2.rbegin();

		int i = 0;
		int i2 = 0;
		for (rit = myvector.rbegin(); rit != myvector.rend(); ++rit)
			*rit = ++i;
		for (rit2 = myvector2.rbegin(); rit2 != myvector2.rend(); ++rit2)
			*rit2 = ++i2;

		ft::vector<int>::iterator it2 = myvector2.begin();
		for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
		{
			(*it == *it2) ? testOk() : testKo();
			++it2;
		}
		(i == i2) ? testOk() : testKo();

		std::cout << '\n';
	}
	std::cout << UCYN "Test capacity" RESET << std::endl;
	{
		std::cout << "size\t\t";

		std::vector<int> myints;
		ft::vector<int> myints2;
		
		(myints.size() == myints2.size()) ? testOk() : testKo();

		for (int i = 0; i < 10; i++)
			myints.push_back(i);
		for (int i = 0; i < 10; i++)
			myints2.push_back(i);

		(myints.size() == myints2.size()) ? testOk() : testKo();

		myints.insert(myints.end(), 10, 100);
		myints2.insert(myints2.end(), 10, 100);
		(myints.size() == myints2.size()) ? testOk() : testKo();

		myints.pop_back();
		myints2.pop_back();
		(myints.size() == myints2.size()) ? testOk() : testKo();

		std::cout << '\n';
	}
}