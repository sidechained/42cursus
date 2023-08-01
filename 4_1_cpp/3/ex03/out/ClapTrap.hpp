#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream> // cout

class ClapTrap {
	public:
		ClapTrap();
		ClapTrap(std::string givenName);
		~ClapTrap();
		ClapTrap(const ClapTrap &copy);
		ClapTrap	&operator=(const ClapTrap &copy);		
		void attack(std::string const &target);
		void takeDamage(unsigned int amount);
		unsigned int getAttackDamage();
		void beRepaired(unsigned int amount);
	protected:
		std::string name;
		static unsigned int hitPoints;
		static unsigned int maxHitPoints;
		static unsigned int energyPoints;
		static unsigned int attackDamage;
		static int maxAttackDamage;
};

#endif