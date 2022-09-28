#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include <iostream> // cout
#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap {
	public:
		ScavTrap(std::string givenName);
		~ScavTrap(void);
		void attack(std::string const &target);		
		void guardGate();
};

#endif