#include <math.h>
#include <limits>
#include <string>
#include <iostream>

#include "Conversor.hpp"

// Constructors
Conversor::Conversor()
{
	std::cout << "\e[0;33mFields Constructor called of Conversor\e[0m" << std::endl;
}
Conversor::Conversor(std::string value) : _value(value)
{
	try
	{
		_type = getValueType();
		parseType();
		std::cout << "\e[0;33mFields Constructor called of Conversor\e[0m" << std::endl;
	}
	catch (const std::exception &e)
	{
		_type = OTHER;
		std::cerr << e.what() << std::endl;
	}
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

numberType Conversor::getType() const
{
	return _type;
}

// Methods
size_t Conversor::countOccurrences(char c, std::string const &str) const
{
	size_t count = 0;

	for (size_t i = 0; i < str.length(); i++)
	{
		if (str[i] == c)
			count++;
	}
	return count;
}

bool Conversor::isNumeric(std::string const &str) const
{
	int start = 0;
	if (str[0] == '-')
		start = 1;
	return !str.empty() && str.find_first_not_of("0123456789", start) == std::string::npos;
}

bool Conversor::isFloat(std::string const &str) const
{
	if (countOccurrences('.', str) > 1)
		return false;
	if (str[str.length() - 1] != 'f')
		return false;
	if (countOccurrences('f', str) != 1)
		return false;
	int start = 0;
	if (str[0] == '-')
		start = 1;
	return !str.empty() && str.find_first_not_of("0123456789f.", start) == std::string::npos;
}

bool Conversor::isDouble(std::string const &str) const
{
	if (countOccurrences('.', str) != 1)
		return false;
	int start = 0;
	if (str[0] == '-')
		start = 1;
	return !str.empty() && str.find_first_not_of("0123456789.", start) == std::string::npos;
}

void Conversor::parseType()
{
	switch (_type)
	{
	case CHAR:
		_char = _value[0];
		break;
	case INT:
		_int = atoi(_value.c_str());
		if ((_int < 0 && _value[0] != '-') || (_int > 0 && _value[0] == '-'))
			throw ErrorException();
		break;
	case FLOAT:
		_float = atof(_value.c_str());
		break;
	case DOUBLE:
		_double = atof(_value.c_str());
		break;
	case OTHER:
		throw ErrorException();
		break;
	}
}

numberType Conversor::getValueType() const
{
	if (_value == "nan" || _value == "+inf" || _value == "-inf" || _value == "inf")
		return DOUBLE;
	if (_value == "nanf" || _value == "+inff" || _value == "-inff" || _value == "inff")
		return FLOAT;
	if (isFloat(_value))
		return FLOAT;
	if (isDouble(_value))
		return DOUBLE;
	if (isNumeric(_value))
		return INT;
	if (_value.length() == 1)
		return CHAR;
	throw ErrorException();
	return OTHER;
}

char Conversor::parseChar()
{
	switch (_type)
	{
	case CHAR:
		break;
	case INT:
		_char = static_cast<char>(_int);
		break;
	case FLOAT:
		if (_float == INFINITY || _float == -INFINITY || _value == "nanf")
			throw ImpossibleException();
		_char = static_cast<char>(_float);
		break;
	case DOUBLE:
		if (_double == INFINITY || _double == -INFINITY || _value == "nan")
			throw ImpossibleException();
		_char = static_cast<char>(_double);
		break;
	case OTHER:
		throw ImpossibleException();
		break;
	}
	if (!isPrintable(_char))
		throw NonDisplayableException();
	return _char;
}

int Conversor::parseInt()
{
	switch (_type)
	{
	case CHAR:
		_int = static_cast<int>(_char);
		break;
	case INT:
		break;
	case FLOAT:
		if (_float == INFINITY || _float == -INFINITY || _value == "nanf")
			throw ImpossibleException();
		_int = static_cast<int>(_float);
		break;
	case DOUBLE:
		if (_double == INFINITY || _double == -INFINITY || _value == "nan")
			throw ImpossibleException();
		_int = static_cast<int>(_double);
		break;
	case OTHER:
		throw ImpossibleException();
		break;
	}
	if ((_int < 0 && _value[0] != '-') || (_int > 0 && _value[0] == '-'))
		throw ImpossibleException();
	return _int;
}

float Conversor::parseFloat()
{
	switch (_type)
	{
	case CHAR:
		_float = static_cast<float>(_char);
		break;
	case INT:
		_float = static_cast<float>(_int);

		break;
	case FLOAT:
		break;
	case DOUBLE:
		_float = static_cast<float>(_double);
		break;
	case OTHER:
		throw ImpossibleException();
		break;
	}
	return _float;
}

double Conversor::parseDouble()
{
	switch (_type)
	{
	case CHAR:
		_double = static_cast<double>(_char);
		break;
	case INT:
		_double = static_cast<double>(_int);
		break;
	case FLOAT:
		_double = static_cast<double>(_float);
		break;
	case DOUBLE:
		break;
	case OTHER:
		throw ImpossibleException();
		break;
	}
	return _double;
}

bool Conversor::isPrintable(char c) const
{
	if (c >= 32 && c <= 126)
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
const char *Conversor::ErrorException::what() const throw()
{
	return "impossible convert";
}

std::ostream &operator<<(std::ostream &out, Conversor &object)
{
	if (object.getType() == OTHER)
	{
		out << "Incorrect format" << std::endl;
		return out;
	}

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