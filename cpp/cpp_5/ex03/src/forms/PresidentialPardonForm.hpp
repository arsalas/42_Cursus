#ifndef PRESIDENTIALPARDONFORM_H
#define PRESIDENTIALPARDONFORM_H

#include <iostream>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
	std::string _target;

public:
	// Constructors
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(const PresidentialPardonForm &copy);

	// Destructor
	virtual ~PresidentialPardonForm();

	// Operators
	PresidentialPardonForm &operator=(const PresidentialPardonForm &assign);
	// Getters / Setters
	const std::string getTarget() const;

	// Methods
	void execute(const Bureaucrat &executor) const;
};

// Stream operators
std::ostream &operator<<(std::ostream &stream, const PresidentialPardonForm &object);

#endif