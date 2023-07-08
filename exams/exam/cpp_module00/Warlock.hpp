#ifndef WARLOCK_H
#define WARLOCK_H
#include <iostream>

class Warlock
{
private:
	std::string _name;
	std::string _title;

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
};

#endif