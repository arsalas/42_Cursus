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

void testVectorSubject()
{

	const int seed = atoi("1");
	srand(seed);

	ft::vector<std::string> vector_str;
	ft::vector<int> vector_int;
	ft::vector<Buffer> vector_buffer;

	double time_spent = 0.0;

	clock_t begin = clock();

	for (int i = 0; i < COUNT; i++)
	{
		vector_buffer.push_back(Buffer());
	}
	for (int i = 0; i < COUNT; i++)
	{
		const int idx = rand() % COUNT;
		vector_buffer[idx].idx = 5;
	}
	ft::vector<Buffer>().swap(vector_buffer);
	std::cout << "empty\t\t";
	try
	{
		for (int i = 0; i < COUNT; i++)
		{
			const int idx = rand() % COUNT;
			vector_buffer.at(idx);
			testKo();
		}
	}
	catch (const std::exception &e)
	{
		testOk();
	}

	clock_t end = clock();

	time_spent += (double)(end - begin) / CLOCKS_PER_SEC;

	double time_spent2 = 0.0;

	clock_t begin2 = clock();

	std::vector<Buffer> vector_buffer2;

	for (int i = 0; i < COUNT; i++)
	{
		vector_buffer2.push_back(Buffer());
	}
	for (int i = 0; i < COUNT; i++)
	{
		const int idx = rand() % COUNT;
		vector_buffer2[idx].idx = 5;
	}
	std::vector<Buffer>().swap(vector_buffer2);
	clock_t end2 = clock();

	time_spent2 += (double)(end2 - begin2) / CLOCKS_PER_SEC;
	std::cout << "\n";
	std::cout << "time\t\t";
	(time_spent <= time_spent2 * 20) ? testOk() : testKo();
	std::cout << "\n";
	std::cout << "\n";
	std::cout << UMAG "Result Time" RESET << std::endl;
	std::cout << YEL "Time ft::vector:\t" << time_spent << "s" RESET << std::endl;
	std::cout << YEL "Time std::vector:\t" << time_spent2 << "s" RESET << std::endl;
	if (time_spent > time_spent2 * 20)
		std::cout << RED "ft::vector time must be less than " <<  time_spent2 * 20 << "s" RESET << std::endl;
}