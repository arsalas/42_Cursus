#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator()
{
}

TargetGenerator::~TargetGenerator()
{
}

void TargetGenerator::learnTargetType(ATarget *target_ptr)
{
	if (target_ptr)
		_arr_target.insert(pair<string, ATarget *>(target_ptr->getType(), target_ptr->clone()));
}

void TargetGenerator::forgetTargetType(const string &target_name)
{
	_arr_target.erase(target_name);
}

ATarget *TargetGenerator::createTarget(const string &target_name)
{
	try
	{
		return _arr_target.at(target_name);
	}
	catch (const std::exception &e)
	{
	}
	return NULL;
}
