#include "Form.hpp"
#include "Bureaucrat.hpp"

// Constructors
Form::Form() : _name(""), _isSigned(false), _gradeSign(0), _gradeExecute(0)
{
	std::cout << "\e[0;33mDefault Constructor called of Form\e[0m" << std::endl;
}

Form::Form(const Form &copy) : _name(copy._name), _isSigned(copy._isSigned), _gradeSign(copy._gradeSign), _gradeExecute(copy._gradeExecute)
{
	std::cout << "\e[0;33mCopy Constructor called of Form\e[0m" << std::endl;
}

Form::Form(const std::string name, const int gradeSign, const int gradeExecute) : _name(name), _isSigned(false), _gradeSign(gradeSign), _gradeExecute(gradeExecute)
{
	checkRangeGrade(gradeSign);
	checkRangeGrade(gradeExecute);

	std::cout << "\e[0;33mFields Constructor called of Form\e[0m" << std::endl;
}

// Destructor
Form::~Form()
{
	std::cout << "\e[0;31mDestructor called of Form\e[0m" << std::endl;
}

// Operators
Form &Form::operator=(const Form &assign)
{
	_isSigned = assign.getIsSigned();
	return *this;
}

// Getters / Setters
const std::string Form::getName() const
{
	return _name;
}

bool Form::getIsSigned() const
{
	return _isSigned;
}

int Form::getGradeSign() const
{
	return _gradeSign;
}

int Form::getGradeExecute() const
{
	return _gradeExecute;
}

// Methods
void Form::beSigned(Bureaucrat &bureaucrat)
{
	if (_gradeSign < bureaucrat.getGrade())
		throw GradeTooLowException();
	_isSigned = true;
}

void Form::checkRangeGrade(int grade) const
{
	if (grade < maxGrade)
		throw GradeTooHightException();
	if (grade > minGrade)
		throw GradeTooLowException();
}

// Exceptions
const char *Form::GradeTooHightException::what() const throw()
{
	return "Form highest possible grade is 1.";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Form lowest possible grade is 150.";
}

// Stream operators
std::ostream &operator<<(std::ostream &stream, const Form &object)
{
	stream << "[" << object.getName();
	stream << ": GradeSign: " << object.getGradeSign();
	stream << ", GradeExec: " << object.getGradeExecute();
	stream << ", Signed: " << (object.getIsSigned() ? "Yes" : "No");
	stream << "]";
	return stream;
}
