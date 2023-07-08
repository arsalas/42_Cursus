#ifndef FWOOSH_H
#define FWOOSH_H

#include <iostream>
#include "ASpell.hpp"

class Fwoosh : public ASpell
{
public:
	Fwoosh();

	Fwoosh *clone() const;
};

#endif