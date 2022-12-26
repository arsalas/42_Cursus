#include <iostream>

#include "Bureaucrat.hpp"

int main()
{
	// increaseGrade
	try
	{
		Bureaucrat a("Bureaucrat 1", 10);
		while (true)
		{
			a.increaseGrade();
			std::cout << a << std::endl;
		}
	}
	catch (const std::exception &ex)
	{
		std::cerr << "Exception: " << ex.what() << std::endl;
	}
	// decreaseGrade
	try
	{
		Bureaucrat a("Bureaucrat 2", 130);
		while (true)
		{
			a.decreaseGrade();
			std::cout << a << std::endl;
		}
	}
	catch (const std::exception &ex)
	{
		std::cerr << "Exception: " << ex.what() << std::endl;
	}
	// CONSTRUCTOR
	try
	{
		Bureaucrat a("Bureaucrat 3", -10);
	}
	catch (const std::exception &ex)
	{
		std::cerr << "Exception: " << ex.what() << std::endl;
	}

	try
	{
		Bureaucrat a("Bureaucrat 4", 1000);
		while (true)
		{
			a.increaseGrade();
			std::cout << a << std::endl;
		}
	}
	catch (const std::exception &ex)
	{
		std::cerr << "Exception: " << ex.what() << std::endl;
	}

	return 0;
}