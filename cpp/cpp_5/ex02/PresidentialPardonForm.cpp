#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"

// Constructors
PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PPF_" + target, 25, 5), _target(target)
{
	std::cout << "\e[0;33mFields Constructor called of PresidentialPardonForm\e[0m" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : AForm(copy.getName(), copy.getGradeSign(), copy.getGradeExecute()), _target(copy._target)
{
	std::cout << "\e[0;33mCopy Constructor called of PresidentialPardonForm\e[0m" << std::endl;
}

// Destructor
PresidentialPardonForm::~PresidentialPardonForm() {}

// Operators
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &assign)
{
	_target = assign._target;
	return *this;
}

// Getters / Setters
const std::string PresidentialPardonForm::getTarget() const
{
	return _target;
}

// Methods
void PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	checkExecute(executor.getGrade());
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

std::ostream &operator<<(std::ostream &out, const PresidentialPardonForm &form)
{
	out << form.getName();
	out << ": [GradeSign: " << form.getGradeSign();
	out << ", GradeExec: " << form.getGradeExecute();
	out << ", Target: " << form.getTarget();
	out << ", Signed: " << (form.getIsSigned() ? "Yes]" : "No]");
	return out;
}