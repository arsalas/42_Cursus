#ifndef ATARGET_H
#define ATARGET_H

#include <iostream>

class ASpell;

class ATarget
{
private:
	std::string _type;

public:
	ATarget(std::string const type);
	virtual ~ATarget();

	const std::string &getType() const;
	void getHitBySpell(const ASpell &spell) const;

	virtual ATarget *clone() const = 0;
};

#include "ASpell.hpp"

#endif