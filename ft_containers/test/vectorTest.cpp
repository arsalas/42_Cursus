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
	{
		std::cout << "max_size\t";

		std::vector<int> myvector;
		ft::vector<int> myvector2;

		// set some content in the vector:
		for (int i = 0; i < 100; i++)
			myvector.push_back(i);
		for (int i = 0; i < 100; i++)
			myvector2.push_back(i);

		(myvector.size() == myvector2.size()) ? testOk() : testKo();
		(myvector.capacity() == myvector2.capacity()) ? testOk() : testKo();
		(myvector.max_size() == myvector2.max_size()) ? testOk() : testKo();

		std::cout << '\n';
	}
	{
		std::cout << "resize\t\t";

		std::vector<int> myvector;
		ft::vector<int> myvector2;

		// set some initial content:
		for (int i = 1; i < 10; i++)
			myvector.push_back(i);
		for (int i = 1; i < 10; i++)
			myvector2.push_back(i);

		myvector.resize(4);
		myvector.resize(8, 100);
		myvector.resize(6);
		myvector2.resize(4);
		myvector2.resize(8, 100);
		myvector2.resize(6);

		int c = 0, c2 = 0;
		for (long unsigned int i = 0; i < myvector.size(); i++)
		{
			(myvector[i] == myvector2[i]) ? testOk() : testKo();
			c++;
		}
		for (long unsigned int i = 0; i < myvector2.size(); i++)
		{
			c2++;
		}
		(c == c2) ? testOk() : testKo();
		std::cout << "\n";
	}
	{
		std::cout << "capacity\t";

		std::vector<int> myvector;
		ft::vector<int> myvector2;

		// set some content in the vector:
		for (int i = 0; i < 100; i++)
			myvector.push_back(i);
		for (int i = 0; i < 100; i++)
			myvector2.push_back(i);

		((int)myvector.size() == (int)myvector2.size()) ? testOk() : testKo();
		((int)myvector.capacity() == (int)myvector2.capacity()) ? testOk() : testKo();
		((int)myvector.max_size() == (int)myvector2.max_size()) ? testOk() : testKo();

		std::cout << '\n';
	}
	{
		std::cout << "empty\t\t";

		std::vector<int> myvector;
		ft::vector<int> myvector2;
		int sum(0);
		int sum2(0);

		for (int i = 1; i <= 10; i++)
			myvector.push_back(i);
		for (int i = 1; i <= 10; i++)
			myvector2.push_back(i);

		while (!myvector.empty())
		{
			sum += myvector.back();
			myvector.pop_back();
		}

		while (!myvector2.empty())
		{
			sum2 += myvector2.back();
			myvector2.pop_back();
		}

		(sum == sum2) ? testOk() : testKo();

		std::cout << '\n';
	}
	{
		std::cout << "reserve\t\t";

		std::vector<int>::size_type sz;
		ft::vector<int>::size_type sz2;

		std::vector<int> foo;
		ft::vector<int> foo2;
		sz = foo.capacity();
		sz2 = foo2.capacity();

		int cap = 0, cap2 = 0;
		for (int i = 0; i < 100; ++i)
		{
			foo.push_back(i);
			if (sz != foo.capacity())
			{
				cap++;
				sz = foo.capacity();
			}
			foo2.push_back(i);
			if (sz2 != foo2.capacity())
			{
				cap2++;
				sz2 = foo2.capacity();
			}
		}
		(cap == cap2) ? testOk() : testKo();
		(sz == sz2) ? testOk() : testKo();

		std::vector<int> bar;
		ft::vector<int> bar2;
		sz = bar.capacity();
		sz2 = bar2.capacity();
		bar.reserve(100);  // this is the only difference with foo above
		bar2.reserve(100); // this is the only difference with foo above

		cap = 0;
		cap2 = 0;
		for (int i = 0; i < 100; ++i)
		{
			bar.push_back(i);
			if (sz != bar.capacity())
			{
				cap++;
				sz = bar.capacity();
			}
		}
		for (int i = 0; i < 100; ++i)
		{
			bar2.push_back(i);
			if (sz2 != bar2.capacity())
			{
				cap2++;
				sz2 = bar.capacity();
			}
		}
		(cap == cap2) ? testOk() : testKo();
		(sz == sz2) ? testOk() : testKo();

		std::cout << '\n';
	}
	std::cout << UCYN "Test element access" RESET << std::endl;

	{
		std::cout << "operator[]\t";

		std::vector<int> myvector(6); // 10 zero-initialized elements
		ft::vector<int> myvector2(6); // 10 zero-initialized elements

		std::vector<int>::size_type sz = myvector.size();
		ft::vector<int>::size_type sz2 = myvector2.size();

		// assign some values:
		for (unsigned i = 0; i < sz; i++)
			myvector[i] = i;
		for (unsigned i = 0; i < sz2; i++)
			myvector2[i] = i;

		// reverse vector using operator[]:
		for (unsigned i = 0; i < sz / 2; i++)
		{
			int temp;
			temp = myvector[sz - 1 - i];
			myvector[sz - 1 - i] = myvector[i];
			myvector[i] = temp;
		}

		for (unsigned i = 0; i < sz2 / 2; i++)
		{
			int temp;
			temp = myvector2[sz - 1 - i];
			myvector2[sz - 1 - i] = myvector2[i];
			myvector2[i] = temp;
		}

		int count = 0, count2 = 0;
		for (unsigned i = 0; i < sz; i++)
		{
			(myvector[i] == myvector2[i]) ? testOk() : testKo();
			count++;
		}
		for (unsigned i = 0; i < sz2; i++)
		{
			count2++;
		}
		(count == count2) ? testOk() : testKo();

		std::cout << '\n';
	}
	{
		std::cout << "at\t\t";

		std::vector<int> myvector(6); // 10 zero-initialized ints
		ft::vector<int> myvector2(6); // 10 zero-initialized ints

		// assign some values:
		for (unsigned i = 0; i < myvector.size(); i++)
			myvector.at(i) = i;
		for (unsigned i = 0; i < myvector2.size(); i++)
			myvector2.at(i) = i;

		int count = 0, count2 = 0;
		for (unsigned i = 0; i < myvector.size(); i++)
		{
			(myvector.at(i) == myvector2.at(i)) ? testOk() : testKo();
			count++;
		}
		for (unsigned i = 0; i < myvector2.size(); i++)
		{
			count2++;
		}
		(count == count2) ? testOk() : testKo();

		try
		{
			myvector2.at(100);
			testKo();
		}
		catch (const std::exception &e)
		{
			testOk();
		}

		std::cout << '\n';
	}
	{
		std::cout << "front\t\t";

		std::vector<int> myvector;
		ft::vector<int> myvector2;

		myvector.push_back(78);
		myvector.push_back(16);
		myvector2.push_back(78);
		myvector2.push_back(16);

		(myvector.front() == myvector2.front()) ? testOk() : testKo();
		// now front equals 78, and back 16

		myvector.front() -= myvector.back();
		myvector2.front() -= myvector2.back();

		(myvector.front() == myvector2.front()) ? testOk() : testKo();
		(myvector.front() == myvector2.front()) ? testOk() : testKo();
		std::cout << '\n';
	}
	{
		std::cout << "back\t\t";

		std::vector<int> myvector;
		ft::vector<int> myvector2;

		myvector.push_back(6);
		myvector2.push_back(6);

		while (myvector.back() != 0)
		{
			myvector.push_back(myvector.back() - 1);
		}
		while (myvector2.back() != 0)
		{
			myvector2.push_back(myvector2.back() - 1);
		}
		int count = 0, count2 = 0;
		for (unsigned i = 0; i < myvector.size(); i++)
		{
			(myvector[i] == myvector2[i]) ? testOk() : testKo();
			count++;
		}
		for (unsigned i = 0; i < myvector2.size(); i++)
		{
			count2++;
		}
		(count == count2) ? testOk() : testKo();

		std::cout << '\n';
	}

	std::cout << UCYN "Test modifiers" RESET << std::endl;

	{
		std::cout << "asign\t\t";

		std::vector<int> first;
		std::vector<int> second;
		std::vector<int> third;
		ft::vector<int> first2;
		ft::vector<int> second2;
		ft::vector<int> third2;

		first.assign(7, 100);  // 7 ints with a value of 100
		first2.assign(7, 100); // 7 ints with a value of 100

		std::vector<int>::iterator it;
		ft::vector<int>::iterator it2;
		it = first.begin() + 1;
		it2 = first2.begin() + 1;

		second.assign(it, first.end() - 1);	   // the 5 central values of first
		second2.assign(it2, first2.end() - 1); // the 5 central values of first

		int myints[] = {1776, 7, 4};
		third.assign(myints, myints + 3); // assigning from array.
		int myints2[] = {1776, 7, 4};
		third2.assign(myints2, myints2 + 3); // assigning from array.

		(int(first.size()) == int(first2.size())) ? testOk() : testKo();
		(int(second.size()) == int(second2.size())) ? testOk() : testKo();
		(int(third.size()) == int(third2.size())) ? testOk() : testKo();

		std::cout << '\n';
	}
	{
		std::cout << "push_back\t";

		std::vector<int> myvector;
		ft::vector<int> myvector2;

		for (size_t i = 0; i < 5; i++)
		{
			myvector.push_back(i);
			myvector2.push_back(i);
			(myvector[i] == myvector2[i]) ? testOk() : testKo();
		}

		(int(myvector.size()) == int(myvector2.size())) ? testOk() : testKo();

		std::cout << '\n';
	}
	{
		std::cout << "pop_back\t";

		std::vector<int> myvector;
		ft::vector<int> myvector2;
		int sum(0);
		int sum2(0);
		myvector.push_back(100);
		myvector.push_back(200);
		myvector.push_back(300);
		myvector2.push_back(100);
		myvector2.push_back(200);
		myvector2.push_back(300);

		while (!myvector.empty())
		{
			sum += myvector.back();
			myvector.pop_back();
		}
		while (!myvector2.empty())
		{
			sum2 += myvector2.back();
			myvector2.pop_back();
		}

		(sum == sum2) ? testOk() : testKo();
		(myvector.size() == myvector2.size()) ? testOk() : testKo();

		std::cout << '\n';
	}
	{
		std::cout << "insert\t\t";

		std::vector<int> myvector(2, 100);
		std::vector<int>::iterator it;
		ft::vector<int> myvector2(2, 100);
		ft::vector<int>::iterator it2;

		it = myvector.begin();
		it = myvector.insert(it, 200);
		it2 = myvector2.begin();
		it2 = myvector2.insert(it2, 200);

		it = myvector.begin();
		it2 = myvector2.begin();

		std::vector<int> anothervector(2, 400);
		myvector.insert(it + 2, anothervector.begin(), anothervector.end());
		ft::vector<int> anothervector2(2, 400);
		myvector2.insert(it2 + 2, anothervector2.begin(), anothervector2.end());

		int myarray[] = {501, 502, 503};
		myvector.insert(myvector.begin(), myarray, myarray + 3);
		int myarray2[] = {501, 502, 503};
		myvector2.insert(myvector2.begin(), myarray2, myarray2 + 3);

		it2 = myvector2.begin();
		int c = 0, c2 = 0;
		for (it = myvector.begin(); it < myvector.end(); it++)
		{
			(*it == *it2) ? testOk() : testKo();
			it2++;
			c++;
		}
		for (it2 = myvector2.begin(); it2 < myvector2.end(); it2++)
		{
			c2++;
		}
		(c == c2) ? testOk() : testKo();

		myvector.insert(it + 2, anothervector.end(), anothervector.begin());
		myvector2.insert(it2 + 2, anothervector2.end(), anothervector2.begin());

		it2 = myvector2.begin();
		c = 0;
		c2 = 0;
		for (it = myvector.begin(); it < myvector.end(); it++)
		{
			(*it == *it2) ? testOk() : testKo();
			it2++;
			c++;
		}
		for (it2 = myvector2.begin(); it2 < myvector2.end(); it2++)
		{
			c2++;
		}
		(c == c2) ? testOk() : testKo();

		std::cout << '\n';
	}
	{
		std::cout << "erease\t\t";

		std::vector<int> myvector;
		ft::vector<int> myvector2;

		// set some values (from 1 to 10)
		for (int i = 1; i <= 10; i++)
			myvector.push_back(i);
		for (int i = 1; i <= 10; i++)
			myvector2.push_back(i);

		// erase the 6th element
		myvector.erase(myvector.begin() + 5);
		myvector2.erase(myvector2.begin() + 5);

		// erase the first 3 elements:
		myvector.erase(myvector.begin(), myvector.begin() + 3);
		myvector2.erase(myvector2.begin(), myvector2.begin() + 3);

		for (unsigned i = 0; i < myvector.size(); ++i)
		{
			(myvector[i] == myvector2[i]) ? testOk() : testKo();
		}
		(myvector.size() == myvector2.size()) ? testOk() : testKo();

		std::cout << '\n';
	}
	{
		std::cout << "swap\t\t";
		std::vector<int> foo(3, 100); // three ints with a value of 100
		std::vector<int> bar(3, 200); // five ints with a value of 200
		ft::vector<int> foo2(3, 100); // three ints with a value of 100
		ft::vector<int> bar2(3, 200); // five ints with a value of 200

		foo.swap(bar);
		foo2.swap(bar2);

		for (unsigned i = 0; i < foo.size(); i++)
		{
			(foo[i] == foo2[i]) ? testOk() : testKo();
		}
		(foo.size() == foo2.size()) ? testOk() : testKo();

		for (unsigned i = 0; i < bar.size(); i++)
		{
			(bar[i] == bar2[i]) ? testOk() : testKo();
		}
		(bar.size() == bar2.size()) ? testOk() : testKo();

		std::cout << '\n';
	}
	{
		std::cout << "clear\t\t";

		std::vector<int> myvector;
		myvector.push_back(100);
		myvector.push_back(200);
		myvector.push_back(300);
		ft::vector<int> myvector2;
		myvector2.push_back(100);
		myvector2.push_back(200);
		myvector2.push_back(300);

		for (unsigned i = 0; i < myvector.size(); i++)
		{
			(myvector[i] == myvector2[i]) ? testOk() : testKo();
		}
		(myvector.size() == myvector2.size()) ? testOk() : testKo();

		myvector.clear();
		myvector.push_back(1101);
		myvector.push_back(2202);
		myvector2.clear();
		myvector2.push_back(1101);
		myvector2.push_back(2202);

		for (unsigned i = 0; i < myvector.size(); i++)
		{
			(myvector[i] == myvector2[i]) ? testOk() : testKo();
		}
		(myvector.size() == myvector2.size()) ? testOk() : testKo();

		std::cout << '\n';
	}
	std::cout << UCYN "Test allocator" RESET << std::endl;

	{
		std::cout << "allocator\t";

		std::vector<int> myvector;
		int *p;
		unsigned int i;
		ft::vector<int> myvector2;
		int *p2;

		// allocate an array with space for 5 elements using vector's allocator:
		p = myvector.get_allocator().allocate(5);
		p2 = myvector2.get_allocator().allocate(5);

		// construct values in-place on the array:
		for (i = 0; i < 5; i++)
			myvector.get_allocator().construct(&p[i], i);
		for (i = 0; i < 5; i++)
			myvector2.get_allocator().construct(&p2[i], i);

		for (i = 0; i < 5; i++)
		{
			(p[i] == p2[i]) ? testOk() : testKo();
		}

		// destroy and deallocate:
		for (i = 0; i < 5; i++)
		{
			myvector2.get_allocator().destroy(&p2[i]);
			myvector.get_allocator().destroy(&p[i]);
		}
		myvector.get_allocator().deallocate(p, 5);
		myvector2.get_allocator().deallocate(p2, 5);

		std::cout << '\n';
	}
	std::cout << UCYN "Test non-member functions" RESET << std::endl;
	{
		std::cout << "rel. operators\t";
		std::vector<int> foo(3, 100); // three ints with a value of 100
		std::vector<int> bar(2, 200); // two ints with a value of 200
		ft::vector<int> foo2(3, 100); // three ints with a value of 100
		ft::vector<int> bar2(2, 200); // two ints with a value of 200

		((foo == bar) == (foo2 == bar2)) ? testOk() : testKo();
		((foo != bar) == (foo2 != bar2)) ? testOk() : testKo();
		((foo < bar) == (foo2 < bar2)) ? testOk() : testKo();
		((foo > bar) == (foo2 > bar2)) ? testOk() : testKo();
		((foo <= bar) == (foo2 <= bar2)) ? testOk() : testKo();
		((foo >= bar) == (foo2 >= bar2)) ? testOk() : testKo();

		std::cout << '\n';
	}
	{
		std::cout << "swap\t\t";

		std::vector<int> foo(3, 100); // three ints with a value of 100
		std::vector<int> bar(3, 200); // five ints with a value of 200
		ft::vector<int> foo2(3, 100); // three ints with a value of 100
		ft::vector<int> bar2(3, 200); // five ints with a value of 200

		foo.swap(bar);
		foo2.swap(bar2);
		int c = 0, c2 = 0;
		ft::vector<int>::iterator it2 = foo2.begin();
		for (std::vector<int>::iterator it = foo.begin(); it != foo.end(); ++it)
		{
			(*it == *it2) ? testOk() : testKo();
			++it2;
			c++;
		}
		for (ft::vector<int>::iterator it = foo2.begin(); it != foo2.end(); ++it)
		{
			c2++;
		}
		(c == c2) ? testOk() : testKo();

		it2 = bar2.begin();
		c = 0;
		c2 = 0;
		for (std::vector<int>::iterator it = bar.begin(); it != bar.end(); ++it)
		{
			(*it == *it2) ? testOk() : testKo();
			++it2;
			c++;
		}
		for (ft::vector<int>::iterator it = bar2.begin(); it != bar2.end(); ++it)
		{
			c2++;
		}
		(c == c2) ? testOk() : testKo();

		std::cout << '\n';
	}
	std::cout << UCYN "Test rendiment" RESET << std::endl;

	{

		testVectorSubject();
	}
}