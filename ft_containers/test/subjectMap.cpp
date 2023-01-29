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

void testMapSubject()
{
	const int seed = atoi("1");
	srand(seed);

	double time_spent = 0.0;

	clock_t begin = clock();

	int sum = 0;
	int sum2 = 0;
	{
		ft::map<int, int> map_int;

		for (int i = 0; i < COUNT; ++i)
		{
			map_int.insert(ft::make_pair(rand(), rand()));
		}

		for (int i = 0; i < 10000; i++)
		{
			int access = rand();
			sum += map_int[access];
		}
		{
			ft::map<int, int> copy = map_int;
		}
	}
	clock_t end = clock();

	time_spent += (double)(end - begin) / CLOCKS_PER_SEC;

	double time_spent2 = 0.0;

	clock_t begin2 = clock();
	{
		std::map<int, int> map_int;

		for (int i = 0; i < COUNT; ++i)
		{
			map_int.insert(std::make_pair(rand(), rand()));
		}

		for (int i = 0; i < 10000; i++)
		{
			int access = rand();
			sum2 += map_int[access];
		}

		{
			std::map<int, int> copy = map_int;
		}
	}

	clock_t end2 = clock();

	(void)sum;
	(void)sum2;

	time_spent2 += (double)(end2 - begin2) / CLOCKS_PER_SEC;
	std::cout << "time\t\t";
	(time_spent <= time_spent2 * 20) ? testOk() : testKo();
	std::cout << "\n";
	std::cout << "\n";
	std::cout << UMAG "Result Time" RESET << std::endl;
	std::cout << YEL "Time ft::map:\t" << time_spent << "s" RESET << std::endl;
	std::cout << YEL "Time std::map:\t" << time_spent2 << "s" RESET << std::endl;
	if (time_spent > time_spent2 * 20)
		std::cout << RED "ft::map time must be less than " <<  time_spent2 * 20 << "s" RESET << std::endl;

}