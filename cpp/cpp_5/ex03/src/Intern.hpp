#ifndef INTERN_H
#define INTERN_H

#include <iostream>

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
public:
	// Constructors
	Intern();
	Intern(const Intern &copy);

	// Destructor
	virtual ~Intern();

	// Operators
	Intern &operator=(const Intern &assign);

	// Methods
	AForm *makeForm(std::string nameForm, std::string target) const;

	// Exceptions
	class IncorrectFormException : public std::exception
	{
		virtual const char *what() const throw();
	};

private:
	// Methods
	ShrubberyCreationForm *makeShrubberyCreationForm(std::string nameForm, std::string target) const;
	RobotomyRequestForm *makeRobotomyRequestForm(std::string nameForm, std::string target) const;
	PresidentialPardonForm *makePresidentialPardonForm(std::string nameForm, std::string target) const;
};

#endif