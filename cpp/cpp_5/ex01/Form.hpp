#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>

class Bureaucrat;

class Form
{
private:
	const std::string _name;
	bool _isSigned;
	const int _gradeSign;
	const int _gradeExecute;
	static const int minGrade = 150;
	static const int maxGrade = 1;

public:
	// Constructors
	Form();
	Form(const Form &copy);
	Form(const std::string name, const int gradeSign, const int gradeExecute);

	// Destructor
	~Form();

	// Operators
	Form &operator=(const Form &assign);

	// Getters / Setters
	const std::string getName() const;
	bool getIsSigned() const;
	int getGradeSign() const;
	int getGradeExecute() const;

	// Methods
	void beSigned(Bureaucrat &bureaucrat);

	// Exceptions
	class GradeTooHightException : public std::exception
	{
		virtual const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		virtual const char *what() const throw();
	};

private:
	void checkRangeGrade(int grade) const;
};

// Stream operators
std::ostream &operator<<(std::ostream &stream, const Form &object);

#endif