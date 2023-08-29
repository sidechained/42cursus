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
	if(!(tbook.find(t->getType()) != tbook.end()))
		tbook[t->getType()] = t;
}

// that makes the generator forget a target type if it's known
void TargetGenerator::forgetTargetType(std::string const &tt)
{
	if(tbook.find(tt) != tbook.end())
		tbook.erase(tbook.find(tt));
}

// that creates a target of the specified type
ATarget* TargetGenerator::createTarget(std::string const &tt)
{
	ATarget *tmpTarget = NULL;
	if(tbook.find(tt) != tbook.end())
		tmpTarget = tbook[tt];
	return (tmpTarget);
}

