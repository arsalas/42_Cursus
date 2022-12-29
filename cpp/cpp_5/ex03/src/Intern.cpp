#include "Intern.hpp"

// Constructors
Intern::Intern()
{
	std::cout << "\e[0;33mFields Constructor called of Intern\e[0m" << std::endl;
}

Intern::Intern(const Intern &copy)
{
	(void)copy;
	std::cout << "\e[0;33mCopy Constructor called of Intern\e[0m" << std::endl;
}

// Destructor
Intern::~Intern() {}

// Operators
Intern &Intern::operator=(const Intern &assign)
{
	(void)assign;
	return *this;
}

// Methods
ShrubberyCreationForm *Intern::makeShrubberyCreationForm(std::string nameForm, std::string target) const
{
	if (nameForm != "shruberry creation")
		throw IncorrectFormException();
	return new ShrubberyCreationForm(target);
}

RobotomyRequestForm *Intern::makeRobotomyRequestForm(std::string nameForm, std::string target) const
{
	if (nameForm != "robotomy request")
		throw IncorrectFormException();
	return new RobotomyRequestForm(target);
}

PresidentialPardonForm *Intern::makePresidentialPardonForm(std::string nameForm, std::string target) const
{
	if (nameForm != "presidential pardon")
		throw IncorrectFormException();
	return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(std::string nameForm, std::string target) const
{
	AForm *form = NULL;
	try
	{
		form = makeShrubberyCreationForm(nameForm, target);
	}
	catch (const std::exception &ex)
	{
	}
	try
	{
		form = makeRobotomyRequestForm(nameForm, target);
	}
	catch (const std::exception &ex)
	{
	}
	try
	{
		form = makePresidentialPardonForm(nameForm, target);
	}
	catch (const std::exception &ex)
	{
	}
	if (form)
	{
		std::cout << "Intern creates " << nameForm << std::endl;
		return form;
	}
	std::cout << nameForm << " is incorrect name form" << std::endl;
	return NULL;
}

// Exceptions
const char *Intern::IncorrectFormException::what() const throw()
{
	return "Incorrect name form";
}

