#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include <iostream> // cout
#include "ClapTrap.hpp"

class FragTrap: public ClapTrap {
	public:
		FragTrap(std::string givenName);
		~FragTrap(void);
		void attack(std::string const &target);		
		void highFivesGuys(void);
};

#endif