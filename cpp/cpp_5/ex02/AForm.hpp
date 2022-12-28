#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>

class Bureaucrat;

class AForm
{
private:
	const std::string _name;
	bool _isSigned;
	const int _gradeSign;
	const int _gradeExecute;
	static const int minGrade = 150;
	static const int maxGrade = 1;

protected:
	// Constructors
	AForm();

public:
	// Constructors
	AForm(const AForm &copy);
	AForm(const std::string name, const int gradeSign, const int gradeExecute);

	// Destructor
	virtual ~AForm();

	// Operators
	AForm &operator=(const AForm &assign);

	// Getters / Setters
	const std::string getName() const;
	bool getIsSigned() const;
	int getGradeSign() const;
	int getGradeExecute() const;

	// Methods
	void beSigned(Bureaucrat &bureaucrat);
	virtual void execute(const Bureaucrat &executor) const = 0;

	// Exceptions
	class GradeTooHightException : public std::exception
	{
		virtual const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		virtual const char *what() const throw();
	};
	class SignedFormException : public std::exception
	{
		virtual const char *what() const throw();
	};
	class ExecuteGradeTooLowException : public std::exception
	{
		virtual const char *what() const throw();
	};

private:
	void checkRangeGrade(int grade) const;

protected:
	void checkExecute(int grade) const;
};

// Stream operators
std::ostream &operator<<(std::ostream &stream, const AForm &object);

#endif