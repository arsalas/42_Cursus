#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator() {}
TargetGenerator::~TargetGenerator() {}

void TargetGenerator::learnTargetType(ATarget *target)
{
	if (target)
		_arr.insert(std::pair<std::string, ATarget *>(target->getType(), target->clone()));
}

void TargetGenerator::forgetTargetType(std::string const &name)
{
	_arr.erase(name);
}

ATarget *TargetGenerator::createTarget(std::string const &name)
{
	ATarget *target = _arr[name];
	if (target)
		return target->clone();
	return NULL;
}
