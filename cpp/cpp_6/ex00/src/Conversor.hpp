#ifndef CONVERSOR_H
#define CONVERSOR_H

#include <string>
#include <iostream>
#include <sstream>

enum status
{
	SUCCESS,
	IMPOSSIBLE,
	NON_DISPLAYABLE
};

class Conversor
{
private:
	std::string _value;
	char _char;
	int _int;
	float _float;
	double _double;
	status fsdf;

	// Constructors
	Conversor();
	// Methods
	bool isPrintable(char c) const;
	bool isNaN(std::string value) const;
	bool isInfPos(std::string value) const;
	bool isInfNeg(std::string value) const;

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
	int getInt() const;
	double getDouble() const;
	float getFloat() const;

	// Methods
	char parseChar();
	int parseInt();
	float parseFloat();
	double parseDouble();

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
std::ostream &operator<<(std::ostream &stream, Conversor &object);

#endif