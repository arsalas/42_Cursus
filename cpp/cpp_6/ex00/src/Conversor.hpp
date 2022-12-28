#ifndef CONVERSOR_H
#define CONVERSOR_H

#include <iostream>

enum class Status
{
	NonDisplayable,
	Impossible,
	Success
};

class Conversor
{
private:
	std::string _value;
	// Status _status;

public:
	// Constructors
	Conversor(const Conversor &copy);
	Conversor(std::string value);

	// Destructor
	~Conversor();

	// Operators
	Conversor &operator=(const Conversor &assign);

	// Getters / Setters

	// Methods

	// Exceptions
	class GradeTooLowException : public std::exception
	{
		virtual const char *what() const throw();
	};

private:
	Conversor();
};

// Stream operators
std::ostream &operator<<(std::ostream &stream, const Conversor &object);

#endif