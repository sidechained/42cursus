// From now on, each class you write MUST be in orthodox canonical form: At least one default constructor, a copy contructor, an assignation operator overload and a destructor. We won’t ask again.

// TODO: use copy constructor / assignation operator overload ?
// TODO: 

#include "ClapTrap.hpp"

// on attack, attackDamage is randomly generated
// how to pass this 

int main(void)
{
	ClapTrap dave("Dave");
	ClapTrap silvia("Silvia");	
	dave.attack("Silvia");
	silvia.takeDamage(dave.getAttackDamage());	
	silvia.beRepaired(10);
	silvia.attack("Dave");
	dave.takeDamage(silvia.getAttackDamage());
	silvia.attack("Dave");
	dave.takeDamage(silvia.getAttackDamage());
	dave.beRepaired(2);	
	dave.attack("Silvia");
	silvia.takeDamage(dave.getAttackDamage());
	silvia.beRepaired(2);
	silvia.attack("Dave");
	dave.takeDamage(dave.getAttackDamage());	
	return (0);
}