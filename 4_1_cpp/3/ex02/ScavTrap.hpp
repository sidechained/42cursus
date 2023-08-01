#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap {
	public:
		ScavTrap(std::string givenName);
		~ScavTrap();	
		void guardGate();
};

#endif