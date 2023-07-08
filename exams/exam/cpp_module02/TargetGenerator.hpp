#ifndef TARGETGENERATOR_H
#define TARGETGENERATOR_H

#include <iostream>
#include <map>
#include "ATarget.hpp"

class TargetGenerator
{
private:
	std::map<std::string, ATarget *> _arr;

	TargetGenerator(TargetGenerator const &other);
	TargetGenerator &operator=(TargetGenerator const &other);

public:
	TargetGenerator();
	~TargetGenerator();

	void learnTargetType(ATarget *);
	void forgetTargetType(std::string const &);
	ATarget *createTarget(std::string const &);
};

#endif