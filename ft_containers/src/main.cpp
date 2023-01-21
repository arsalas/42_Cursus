#include <iostream>
#include "vector.hpp"

int main()
{
	ft::vector<int> v;
	ft::vector<int> copy(v);
	ft::vector<int> fill(5);
	ft::vector<int> fill2(5, 6);
	std::cout << "ft::vector<int>::value_type" << std::endl;
	// ft::vector<int>::value_type;
	return 0;
}
