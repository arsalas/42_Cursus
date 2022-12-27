#include <iostream>

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	// CONSTRUCTORS
	try
	{
		Form f("Form 1", 0, 42);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Form f("Form 2", 151, 42);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Form f("Form 3", 42, 0);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Form f("Form 4", 42, 151);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Form f1("Form 5", 150, 42);
		Form f2("Form 6", 1, 42);
		Form f4("Form 7", 42, 150);
		Form f3("Form 8", 42, 1);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	// SIGN
	Bureaucrat b("Bureaucrat 1", 42);

	{
		Form f = Form("Form 1", 43, 1);
		b.signForm(f);
		std::cout << "Signed: " << (f.getIsSigned() ? "Yes" : "No") << std::endl;
	}
	{
		Form f = Form("Form 2", 42, 1);
		b.signForm(f);
		std::cout << "Signed: " << (f.getIsSigned() ? "Yes" : "No") << std::endl;
	}
	{
		Form f = Form("Form 3", 41, 1);
		b.signForm(f);
		std::cout << "Signed: " << (f.getIsSigned() ? "Yes" : "No") << std::endl;
	}
	{
		Form f = Form("Form 4", 43, 1);
		b.signForm(f);
		std::cout << "Signed: " << (f.getIsSigned() ? "Yes" : "No") << std::endl;
		b.signForm(f);
		std::cout << "Signed: " << (f.getIsSigned() ? "Yes" : "No") << std::endl;
	}
	return 0;
}