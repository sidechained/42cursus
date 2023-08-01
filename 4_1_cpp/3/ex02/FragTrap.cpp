#include "FragTrap.hpp"

FragTrap::FragTrap()
{	
	name = "nobody";
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
	std::cout << "	FRAGTRAP CONSTRUCTING:	Oh je, " << name << " arrived with " << hitPoints << " hit points and " << energyPoints << " energy points and " << attackDamage << " attack damage!" << std::endl;
}

FragTrap::FragTrap(std::string givenName)
{
	name = givenName;
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
	std::cout << "	FRAGTRAP CONSTRUCTING:	Oh je, " << name << " arrived with " << hitPoints << " hit points and " << energyPoints << " energy points and " << attackDamage << " attack damage!" << std::endl;
}

FragTrap::~FragTrap(void)
{
	std::cout << "	FRAGTRAP DESTRUCTING:	Goodbye "  << name << " you served us well!" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "	FRAGTRAP INSTANCE " << name << " KINDLY REQUESTS POSITIVE HIGH FIVES!!!" << std::endl;
}