#include "AForm.hpp"
#include "Bureaucrat.hpp"

// Constructors
AForm::AForm() : _name(""), _isSigned(false), _gradeSign(0), _gradeExecute(0)
{
	std::cout << "\e[0;33mDefault Constructor called of AForm\e[0m" << std::endl;
}

AForm::AForm(const AForm &copy) : _name(copy._name), _isSigned(copy._isSigned), _gradeSign(copy._gradeSign), _gradeExecute(copy._gradeExecute)
{
	std::cout << "\e[0;33mCopy Constructor called of AForm\e[0m" << std::endl;
}

AForm::AForm(const std::string name, const int gradeSign, const int gradeExecute) : _name(name), _isSigned(false), _gradeSign(gradeSign), _gradeExecute(gradeExecute)
{
	checkRangeGrade(gradeSign);
	checkRangeGrade(gradeExecute);

	std::cout << "\e[0;33mFields Constructor called of AForm\e[0m" << std::endl;
}

// Destructor
AForm::~AForm()
{
	std::cout << "\e[0;31mDestructor called of AForm\e[0m" << std::endl;
}

// Operators
AForm &AForm::operator=(const AForm &assign)
{
	_isSigned = assign.getIsSigned();
	return *this;
}

// Getters / Setters
const std::string AForm::getName() const
{
	return _name;
}

bool AForm::getIsSigned() const
{
	return _isSigned;
}

int AForm::getGradeSign() const
{
	return _gradeSign;
}

int AForm::getGradeExecute() const
{
	return _gradeExecute;
}

// Methods
void AForm::beSigned(Bureaucrat &bureaucrat)
{
	if (_gradeSign < bureaucrat.getGrade())
		throw GradeTooLowException();
	_isSigned = true;
}

void AForm::checkRangeGrade(int grade) const
{
	if (grade < maxGrade)
		throw GradeTooHightException();
	if (grade > minGrade)
		throw GradeTooLowException();
}

void AForm::checkExecute(int grade) const
{
	if (!_isSigned)
		throw SignedFormException();
	if (_gradeExecute < grade)
		throw ExecuteGradeTooLowException();
}

// Exceptions
const char *AForm::GradeTooHightException::what() const throw()
{
	return "AForm highest possible grade is 1.";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "AForm lowest possible grade is 150.";
}

const char *AForm::SignedFormException::what() const throw()
{
	return "The contract is not signed";
}

const char *AForm::ExecuteGradeTooLowException::what() const throw()
{
	return "Bureaucrat is too low grade to execute";
}

// Stream operators
std::ostream &operator<<(std::ostream &stream, const AForm &object)
{
	stream << "[" << object.getName();
	stream << ": GradeSign: " << object.getGradeSign();
	stream << ", GradeExec: " << object.getGradeExecute();
	stream << ", Signed: " << (object.getIsSigned() ? "Yes" : "No");
	stream << "]";
	return stream;
}
