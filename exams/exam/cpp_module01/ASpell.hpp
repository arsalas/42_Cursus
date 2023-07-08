#ifndef ASPELL_H
#define ASPELL_H

#include <iostream>

class ATarget;

class ASpell
{

protected:
	std::string _name;
	std::string _effects;

public:
	ASpell(std::string const name, std::string const effects);
	
	virtual ~ASpell();

	const std::string &getName() const;
	const std::string &getEffects() const;

	void launch(ATarget const &target) const;

	virtual ASpell *clone() const = 0;
};

#include "ATarget.hpp"

#endif