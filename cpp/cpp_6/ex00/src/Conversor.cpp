#include <math.h>
#include <limits>
#include "Conversor.hpp"

// Constructors
Conversor::Conversor()
{
	std::cout << "\e[0;33mFields Constructor called of Conversor\e[0m" << std::endl;
}
Conversor::Conversor(std::string value) : _value(value)
{
	std::cout << "\e[0;33mFields Constructor called of Conversor\e[0m" << std::endl;
}

Conversor::Conversor(const Conversor &copy) : _value(copy._value), _char(copy._char), _int(copy._int), _float(copy._float), _double(copy._double)
{
	std::cout << "\e[0;33mCopy Constructor called of Conversor\e[0m" << std::endl;
}

// Destructor
Conversor::~Conversor()
{
	std::cout << "\e[0;31mDestructor called of Conversor\e[0m" << std::endl;
}

// Operators
Conversor &Conversor::operator=(const Conversor &assign)
{
	_value = assign._value;
	_char = assign._char;
	_int = assign._int;
	_double = assign._double;
	_float = assign._float;
	return *this;
}

// Getters / Setters
std::string Conversor::getValue() const
{
	return _value;
}

char Conversor::getChar() const
{
	return _char;
}

int Conversor::getInt() const
{
	return _int;
}

double Conversor::getDouble() const
{
	return _double;
}

float Conversor::getFloat() const
{
	return _float;
}

// Methods
char Conversor::parseChar()
{
	std::stringstream ss(_value);
	int x;
	if ((ss >> x).fail())
		throw ImpossibleException();
	_char = x;
	if (!isPrintable(_char))
		throw NonDisplayableException();
	return _char;
}

int Conversor::parseInt()
{
	std::stringstream ss(_value);
	if ((ss >> _int).fail())
		throw ImpossibleException();
	return _int;
}

float Conversor::parseFloat()
{
	if (isNaN(_value))
	{
		_float = NAN;
		return _float;
	}
	if (isInfPos(_value))
	{
		_float = INFINITY;
		return _float;
	}
	if (isInfNeg(_value))
	{
		_float = -INFINITY;
		return _float;
	}
	std::stringstream ss(_value);
	if ((ss >> _float).fail())
		throw ImpossibleException();
	return _float;
}

double Conversor::parseDouble()
{
	if (isNaN(_value))
	{
		_double = NAN;
		return _double;
	}
	if (isInfPos(_value))
	{
		_double = INFINITY;
		return _double;
	}
	if (isInfNeg(_value))
	{
		_double = -INFINITY;
		return _double;
	}
	std::stringstream ss(_value);
	if ((ss >> _double).fail())
		throw ImpossibleException();
	return _double;
}

bool Conversor::isPrintable(char c) const
{
	if (c >= 32 && c <= 126)
		return true;
	return false;
}

bool Conversor::isNaN(std::string value) const
{
	if (value == "nanf" || value == "nan")
		return true;
	return false;
}

bool Conversor::isInfPos(std::string value) const
{
	if (value == "+inf" || value == "+inff")
		return true;
	return false;
}

bool Conversor::isInfNeg(std::string value) const
{
	if (value == "-inf" || value == "-inff")
		return true;
	return false;
}

// Exceptions
const char *Conversor::ImpossibleException::what() const throw()
{
	return "impossible";
}
const char *Conversor::NonDisplayableException::what() const throw()
{
	return "non displayable";
}

std::ostream &operator<<(std::ostream &out, Conversor &object)
{
	try
	{
		object.parseChar();
		out << "char: '" << object.getChar() << "'" << std::endl;
	}
	catch (const std::exception &ex)
	{
		out << "char: " << ex.what() << std::endl;
	}
	try
	{
		object.parseInt();
		out << "int: " << object.getInt() << std::endl;
	}
	catch (const std::exception &ex)
	{
		out << "int: " << ex.what() << std::endl;
	}
	try
	{
		object.parseFloat();
		double intPart;
		out << "float: " << object.getFloat() << ((std::modf(object.getFloat(), &intPart) == 0 && object.getFloat() != INFINITY && object.getFloat() != -INFINITY) ? ".0" : "") << "f" << std::endl;
	}
	catch (const std::exception &ex)
	{
		out << "float: " << ex.what() << std::endl;
	}
	try
	{
		object.parseDouble();
		double intPart;
		out << "double: " << object.getDouble() << ((std::modf(object.getDouble(), &intPart) == 0 && object.getDouble() != INFINITY && object.getDouble() != -INFINITY) ? ".0" : "") << std::endl;
	}
	catch (const std::exception &ex)
	{
		out << "double: " << ex.what() << std::endl;
	}
	return out;
}