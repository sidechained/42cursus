#include "FragTrap.hpp"

// ": ClapTrap(givenName)" below ensures correct constructor is called (as opposed to default constructor, which we don't have)
FragTrap::FragTrap(std::string givenName) : ClapTrap(givenName)
{
	std::cout << "	FRAGTRAP CONSTRUCTING:	Oh rejoice fellow countrymen, " << name << " has entered into the world!" << std::endl;
	std::cout << "	" << name;
	std::cout << ": [hitPoints: " << hitPoints;
	std::cout << ", energyPoints: " << energyPoints;
	std::cout << ", attackDamage: " << attackDamage;
	std::cout << "]" << std::endl;
}

FragTrap::~FragTrap(void)
{
	std::cout << "	FRAGTRAP DESTRUCTING:	So long "  << name << " and thanks for all the fish!" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "	FRAGTRAP INSTANCE " << name << " KINDLY REQUESTS POSITIVE HIGH FIVES!!!" << std::endl;
}