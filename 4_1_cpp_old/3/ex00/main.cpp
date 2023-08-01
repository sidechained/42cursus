// From now on, each class you write MUST be in orthodox canonical form: At least one default constructor, a copy contructor, an assignation operator overload and a destructor. We won’t ask again.

// TODO: use copy constructor / assignation operator overload ?
// TODO: 

#include "ClapTrap.hpp"

// on attack, attackDamage is randomly generated
// how to pass this 

int main(void)
{
	std::cout << std::endl;
	std::cout << "----------------------------------------------------------------------------------" << std::endl;
	std::cout << "-- Testing default constructor: (\"nobody\" created)" << std::endl;
	ClapTrap nobody;
	std::cout << "----------------------------------------------------------------------------------" << std::endl;
	std::cout << std::endl;
	
	std::cout << std::endl;
	std::cout << "----------------------------------------------------------------------------------" << std::endl;
	std::cout << "-- Testing copy constructor: (object attacks a copy of itself)" << std::endl;
	ClapTrap jimbob("Jimbob");
	ClapTrap jimbob2(jimbob);
	jimbob2.attack("Jimbob");
	std::cout << "----------------------------------------------------------------------------------" << std::endl;
	std::cout << std::endl;

	std::cout << "----------------------------------------------------------------------------------" << std::endl;
	std::cout << "-- Testing assignment operator overload:" << std::endl;	
	std::cout << "   (milou = jonas. When Milou attacks Jonas, the copied Jonas will be attacking the original Jonas!)" << std::endl;	
	ClapTrap milou("Milou");
	ClapTrap jonas("Jonas");	
	milou = jonas;
	milou.attack("Jonas");
	std::cout << "----------------------------------------------------------------------------------" << std::endl;
	std::cout << std::endl;

	std::cout << "----------------------------------------------------------------------------------" << std::endl;
	std::cout << "-- Testing functionality:" << std::endl;	
	ClapTrap dave("Dave");
	ClapTrap silvia("Silvia");	
	dave.attack("Silvia");
	silvia.takeDamage(2);
	silvia.beRepaired(10);
	silvia.attack("Dave");
	dave.takeDamage(6);
	silvia.attack("Dave");
	dave.takeDamage(1);
	dave.beRepaired(2);
	dave.beRepaired(2);
	dave.beRepaired(2);
	dave.beRepaired(2);
	dave.beRepaired(2);
	dave.beRepaired(2);
	dave.beRepaired(2);
	dave.beRepaired(2);
	dave.beRepaired(2);
	dave.beRepaired(2);
	dave.attack("Silvia");
	silvia.takeDamage(3);
	silvia.beRepaired(2);
	silvia.attack("Dave");
	dave.takeDamage(7);
	silvia.attack("Dave");
	dave.takeDamage(8);
	dave.beRepaired(2);
	std::cout << "--Checking for death by taking damage (even though ClapTraps can no longer attack)" << std::endl;
	dave.takeDamage(20);
	silvia.takeDamage(20);
	dave.takeDamage(20);
	silvia.takeDamage(20);

	std::cout << "----------------------------------------------------------------------------------" << std::endl;
	std::cout << std::endl;

	return (0);
}