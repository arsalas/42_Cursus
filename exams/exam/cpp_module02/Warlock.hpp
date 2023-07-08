#ifndef WARLOCK_H
#define WARLOCK_H
#include <iostream>
#include <map>

#include "ASpell.hpp"
#include "ATarget.hpp"
#include "SpellBook.hpp"

class Warlock
{
private:
	std::string _name;
	std::string _title;
	SpellBook _book;

	Warlock();
	Warlock(Warlock const &other);
	Warlock &operator=(Warlock const &other);

public:
	Warlock(std::string const &name, std::string const &title);
	~Warlock();

	std::string const &getName() const;
	std::string const &getTitle() const;
	void setTitle(const std::string &title);

	void introduce() const;

	void learnSpell(ASpell *spell);
	void forgetSpell(std::string spell);
	void launchSpell(std::string name, ATarget const &target);
};

#endif