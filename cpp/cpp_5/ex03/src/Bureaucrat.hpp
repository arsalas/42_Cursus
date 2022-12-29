#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class AForm;

class Bureaucrat
{
private:
	const std::string _name;
	int _grade;
	static const int minGrade = 150;
	static const int maxGrade = 1;

public:
	// Constructors
	Bureaucrat();
	Bureaucrat(const Bureaucrat &copy);
	Bureaucrat(std::string _name, int _grade);

	// Destructor
	~Bureaucrat();

	// Operators
	Bureaucrat &operator=(const Bureaucrat &assign);

	// Getters / Setters
	std::string getName() const;
	int getGrade() const;

	// Methods
	void increaseGrade();
	void decreaseGrade();
	void signForm(AForm &form);
	void executeForm(const AForm &form) const;

	// Exceptions
	class GradeTooLowException : public std::exception
	{
		virtual const char *what() const throw();
	};
	class GradeTooHightException : public std::exception
	{
		virtual const char *what() const throw();
	};

private:
	void checkRangeGrade(int grade) const;
};

// Stream operators
std::ostream &operator<<(std::ostream &stream, const Bureaucrat &object);

#endif