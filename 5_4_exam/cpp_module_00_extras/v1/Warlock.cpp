#include "Warlock.hpp"

Warlock::Warlock(std::string in_name, std::string in_title)
{
	name = in_name;
	title = in_title;
	std::cout << name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock()
{
	std::cout << name << ": My job here is done!" << std::endl;
}

const std::string Warlock::getName() const
{
	return(name);
}

const std::string Warlock::getTitle() const
{
	return(title);
}

void Warlock::setTitle(const std::string in_title)
{
	title = in_title;
}

void Warlock::introduce() const
{
	std::cout << name << ": I am " << name << ", " << title << "!" << std::endl;
}
