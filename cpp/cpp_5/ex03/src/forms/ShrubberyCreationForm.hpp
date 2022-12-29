#ifndef SHRUBBERYCREATIONFORM_H
#define SHRUBBERYCREATIONFORM_H

#include <iostream>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
private:
	std::string _target;

public:
	// Constructors
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(const ShrubberyCreationForm &copy);

	// Destructor
	virtual ~ShrubberyCreationForm();

	// Operators
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &assign);

	// Getters / Setters
	const std::string getTarget() const;
	
	// Methods
	void execute(const Bureaucrat &executor) const;
};

// Stream operators
std::ostream &operator<<(std::ostream &stream, const ShrubberyCreationForm &object);

#endif