#include <iostream>
#include "Span.hpp"

int main()
{
	{
		std::cout << "==============================" << std::endl;
		std::cout << "\tSUBJECT TEST" << std::endl;
		std::cout << "==============================" << std::endl;
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	{
		std::cout << "==============================" << std::endl;
		std::cout << "\tNEGATIVE TEST" << std::endl;
		std::cout << "==============================" << std::endl;
		Span sp = Span(5);
		sp.addNumber(-6);
		sp.addNumber(-3);
		sp.addNumber(-17);
		sp.addNumber(-9);
		sp.addNumber(-11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	{
		try
		{
			std::cout << "==============================" << std::endl;
			std::cout << "\tMAX NUMBERS TEST" << std::endl;
			std::cout << "==============================" << std::endl;

			Span sp = Span(10000);
			for (size_t i = 1; i <= 10000; i++)
			{
				sp.addNumber(i * i);
			}
			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	{
		try
		{
			std::cout << "==============================" << std::endl;
			std::cout << "\tRANGE TEST" << std::endl;
			std::cout << "==============================" << std::endl;
			Span sp = Span(50);
			sp.addRange(1, 50);
			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	return 0;
}
