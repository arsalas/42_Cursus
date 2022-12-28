#ifndef ROBOTOMYREQUESTFORM_H
#define ROBOTOMYREQUESTFORM_H

#include <iostream>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
private:
	std::string _target;

public:
	// Constructors
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(const RobotomyRequestForm &copy);

	// Destructor
	virtual ~RobotomyRequestForm();

	// Operators
	RobotomyRequestForm &operator=(const RobotomyRequestForm &assign);

	// Getters / Setters
	const std::string getTarget() const;
	
	// Methods
	void execute(const Bureaucrat &executor) const;
};

// Stream operators
std::ostream &operator<<(std::ostream &stream, const RobotomyRequestForm &object);

#endif