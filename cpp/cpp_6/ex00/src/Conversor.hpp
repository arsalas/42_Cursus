#ifndef CONVERSOR_H
#define CONVERSOR_H

#include <string>
#include <iostream>
#include <sstream>

enum numberType
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	OTHER
};

class Conversor
{

private:
	std::string _value;
	char _char;
	int _int;
	float _float;
	double _double;
	numberType _type;

	// Constructors
	Conversor();
	// Methods
	size_t countOccurrences(char c, std::string const &str) const;
	bool isNumeric(std::string const &str) const;
	bool isFloat(std::string const &str) const;
	bool isDouble(std::string const &str) const;
	bool isIntInLimits(const char *str) const;
	numberType getValueType() const;
	void parseType();
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
	int getInt() const;
	double getDouble() const;
	float getFloat() const;
	numberType getType() const;

	// Methods
	bool isDecimalPrintable() const;
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

	class ErrorException : public std::exception
	{
		virtual const char *what() const throw();
	};
};

// Stream operators
std::ostream &operator<<(std::ostream &stream, Conversor &object);

#endif