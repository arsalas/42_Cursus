#ifndef CONVERSOR_H
#define CONVERSOR_H

#include <string>
#include <iostream>
#include <sstream>

class Conversor
{
private:
	std::string _value;
	char _char;
	int _int;
	float _float;
	double _double;

	// Constructors
	Conversor();
	// Methods
	bool isPrintable(char c) const;

public:
	// Constructors
	Conversor(std::string value);
	Conversor(const Conversor &copy);

	// Destructor
	~Conversor();

	// Operators
	Conversor &operator=(const Conversor &assign);

	// Getters / Setters
	std::string getValue() const;
	char getChar() const;

	// Methods
	char parseChar();
	int parseInt() const;
	float parseFloat() const;
	double parseDouble() const;

	// Exceptions
	class ImpossibleException : public std::exception
	{
		virtual const char *what() const throw();
	};

	class NonDisplayableException : public std::exception
	{
		virtual const char *what() const throw();
	};
};

// Stream operators
std::ostream &operator<<(std::ostream &stream, const Conversor &object);

#endif