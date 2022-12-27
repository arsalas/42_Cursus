#include "Bureaucrat.hpp"
#include "Form.hpp"

// Constructors
Bureaucrat::Bureaucrat() : _name(""), _grade(150)
{
	std::cout << "\e[0;33mDefault Constructor called of Bureaucrat\e[0m" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name(copy.getName()), _grade(copy.getGrade())
{
	std::cout << "\e[0;33mCopy Constructor called of Bureaucrat\e[0m" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	checkRangeGrade(grade);
	_grade = grade;
	std::cout << "\e[0;33mFields Constructor called of Bureaucrat\e[0m" << std::endl;
}

// Destructor
Bureaucrat::~Bureaucrat()
{
	std::cout << "\e[0;31mDestructor called of Bureaucrat\e[0m" << std::endl;
}

// Operators
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &assign)
{
	_grade = assign.getGrade();
	return *this;
}

// Getters / Setters
std::string Bureaucrat::getName() const
{
	return _name;
}
int Bureaucrat::getGrade() const
{
	return _grade;
}

void Bureaucrat::checkRangeGrade(int grade) const
{
	if (grade < maxGrade)
		throw GradeTooHightException();
	if (grade > minGrade)
		throw GradeTooLowException();
}

void Bureaucrat::increaseGrade()
{
	checkRangeGrade(_grade - 1);
	_grade--;
}

void Bureaucrat::decreaseGrade()
{
	checkRangeGrade(_grade + 1);
	_grade++;
}

void Bureaucrat::signForm(Form &form)
{
	if (form.getIsSigned())
	{
		std::cout << "Bureaucrat " << _name << ", couldn't sign " << form << " because it's already signed" << std::endl;
		return;
	}
	try
	{
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() << std::endl;
	}
	catch (const std::exception &ex)
	{
		std::cout << "Bureaucrat " << _name << ", couldn't sign " << form << " because don't have enought grade" << std::endl;
	}
}

// Exceptions
const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Bureaucrat highest possible grade is 1.";
}
const char *Bureaucrat::GradeTooHightException::what() const throw()
{
	return "Bureaucrat lowest possible grade is 150.";
}

// Stream operators
std::ostream &operator<<(std::ostream &stream, const Bureaucrat &object)
{
	stream << object.getName() << ", bureaucrat grade " << object.getGrade() << ".";
	return stream;
}
