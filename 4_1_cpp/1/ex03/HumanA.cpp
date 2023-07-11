#include "HumanA.hpp"

// constructor uses initialiser list to initialise _name and _weapon
HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon)
{
}

void	HumanA::attack()
{
	std::cout << this->_name << " attacks with his " << _weapon.getType() << std::endl;
}