#ifndef PARSECHAR_H
#define PARSECHAR_H

#include <iostream>

enum class Suit
{
	Diamonds,
	Hearts,
	Clubs,
	Spades
};

class ParseChar
{
private:
	char _value;
	Suit _status;

public:
	ParseChar();

private:
};

#endif