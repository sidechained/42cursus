#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"
// use of virtual here avoids 'diamond inheritence' and ensures that only one copy of the base class is shared among multiple derived classes in the inheritance hierarchy
class ScavTrap: virtual public ClapTrap {
	public:
		ScavTrap();
		ScavTrap(std::string givenName);
		~ScavTrap();	
		void guardGate();
	protected:
		std::string name;
		unsigned int hitPoints;
		unsigned int energyPoints;
		unsigned int attackDamage;		
};

#endif