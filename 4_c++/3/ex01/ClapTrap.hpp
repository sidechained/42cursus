#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream> // cout

class ClapTrap {
	public:
		ClapTrap(std::string givenName);
		~ClapTrap(void);
		ClapTrap(const ClapTrap &copy);
		ClapTrap	&operator=(const ClapTrap &copy);		
		void attack(std::string const &target);
		void takeDamage(unsigned int amount);
		unsigned int getAttackDamage();
		void beRepaired(unsigned int amount);
	protected:
		std::string name;
		unsigned int hitPoints;
		unsigned int energyPoints;
		unsigned int attackDamage;
};

#endif