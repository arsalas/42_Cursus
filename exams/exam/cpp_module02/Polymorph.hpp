#ifndef POLYMORPH_H
#define POLYMORPH_H

#include <iostream>
#include "ASpell.hpp"

class Polymorph : public ASpell
{
public:
	Polymorph();
	~Polymorph();

	Polymorph *clone() const;
};
#endif