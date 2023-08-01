#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include <iostream> // cout
#include "ClapTrap.hpp"

class FragTrap: public ClapTrap {
	public:
		FragTrap(std::string givenName);
		~FragTrap();
		void highFivesGuys(void);
	private:
		void attack(std::string const &target);
};

#endif