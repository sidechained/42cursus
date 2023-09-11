#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator()
{

}

TargetGenerator::~TargetGenerator()
{

}

// teaches a target to the generator
void TargetGenerator::learnTargetType(ATarget* t)
{
	if (t)
	{
		target[t->getType()] = t;
	}
}

// makes the generator forget a target type if it's known
void TargetGenerator::forgetTargetType(std::string const &t)
{
	if (target.find(t) != target.end())
		target.erase(target.find(t));
}

// creates a target of the specified type
ATarget* TargetGenerator::createTarget(std::string const &t)
{
	ATarget* tmp = NULL;
	if (target.find(t) != target.end())
		tmp = target[t];
	return (tmp);
}