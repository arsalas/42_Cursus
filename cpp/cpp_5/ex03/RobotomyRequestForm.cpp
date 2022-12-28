#include <cstdlib>
#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"

// Constructors
RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RCF_" + target, 72, 45), _target(target)
{
	std::cout << "\e[0;33mFields Constructor called of RobotomyRequestForm\e[0m" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm(copy.getName(), copy.getGradeSign(), copy.getGradeExecute()), _target(copy._target)
{
	std::cout << "\e[0;33mCopy Constructor called of RobotomyRequestForm\e[0m" << std::endl;
}

// Destructor
RobotomyRequestForm::~RobotomyRequestForm() {}

// Operators
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &assign)
{
	_target = assign._target;
	return *this;
}

// Getters / Setters
const std::string RobotomyRequestForm::getTarget() const
{
	return _target;
}

// Methods
void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	checkExecute(executor.getGrade());
	std::cout << "*DRILLING NOISES*" << std::endl;
	std::cout << (std::rand() % 2 ? _target + "has been robotomized successfully." : "Robotomy failed.") << std::endl;
}

std::ostream &operator<<(std::ostream &out, const RobotomyRequestForm &form)
{
	out << form.getName();
	out << ": [GradeSign: " << form.getGradeSign();
	out << ", GradeExec: " << form.getGradeExecute();
	out << ", Target: " << form.getTarget();
	out << ", Signed: " << (form.getIsSigned() ? "Yes]" : "No]");
	return out;
}