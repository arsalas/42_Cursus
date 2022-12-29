#include "Conversor.hpp"

// Constructors
Conversor::Conversor()
{
	std::cout << "\e[0;33mFields Constructor called of Conversor\e[0m" << std::endl;
}
Conversor::Conversor(std::string value) : _value(value)
{
	parseChar();
	std::cout << "\e[0;33mFields Constructor called of Conversor\e[0m" << std::endl;
}

Conversor::Conversor(const Conversor &copy) : _value(copy._value)
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

// Methods
char Conversor::parseChar()
{
	// if (_value.length() > 1)
	// 	throw ImpossibleException();
	// _char = static_cast<int>(_value);
	std::stringstream ss(_value);
	int x;
	ss >> x;
	// if ((ss >> _char).fail())
	// {
	// 	// ERROR
	// 	std::cout << "ERROR" << std::endl;
	// }
	// if (!isPrintable(_char))
	// 	throw NonDisplayableException();
	_char = x;
	return _char;
}
int Conversor::parseInt() const { return 1; }
float Conversor::parseFloat() const { return 1.00f; }
double Conversor::parseDouble() const { return 1.00; }

bool Conversor::isPrintable(char c) const
{
	if (c >= 32 && c <= 126)
		return true;
	return false;
}

// Exceptions
const char *Conversor::ImpossibleException::what() const throw()
{
	return "Bureaucrat highest possible grade is 1.";
}
const char *Conversor::NonDisplayableException::what() const throw()
{
	return "Bureaucrat lowest possible grade is 150.";
}

std::ostream &operator<<(std::ostream &out, const Conversor &object)
{
	out << "char: " << object.getChar() << std::endl;
	out << "int: " << object.parseInt() << std::endl;
	out << "float: " << object.parseFloat() << std::endl;
	out << "double: " << object.parseDouble() << std::endl;
	return out;
}