// From now on, each class you write MUST be in orthodox canonical form:
// At least one default constructor, a copy contructor, an assignation operator overload and a destructor.

// ScavTrap inherits from ClapTrap apart from
// - constructor - own message [DONE]
// - destructor - own message [DONE]
// - attacks - own message [DONE]
// constructing a ScavTrap must start by constructing a ClapTrap [DONE]
// destructing a ScavTrap must also subsequently destruct a ClapTrap [DONE]
// ScavTrap will use attributes of ClapTrap but set to Hitpoints 100, Energy points 50, attack damage 20 [DONE]
// ScavTrap will also have function void guardGate(); which displays message 'entered Gatekeeper mode' [DONE]
// main function must test everything [same tests modified for ScavTrap]
// TODO: fix floating point error (rand modulo)

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	// ScavTrap scav1("Scav1");
	// scav1.guardGate(); // scav1 has the correct name, so attributes are being inherited correctly
	// scav1.attack("a wall");
	// scav1.takeDamage(5); // does not work

	std::cout << std::endl;
	std::cout << "* * * NEW SCAVTRAP TESTS:                " << std::endl;	
	std::cout << std::endl;	
	std::cout << "-- Testing copy constructor:             " << std::endl;
	ScavTrap kimbap("Kimbap");
	ScavTrap kimbap2(kimbap);
	kimbap2.attack("Kimbap");
	std::cout << "-----------------------------------------" << std::endl;
	std::cout << std::endl;

	std::cout << "-- Testing assignment operator overload: " << std::endl;	
	ScavTrap filou("Filou");
	ScavTrap bonas("Bonas");	
	filou = bonas;
	filou.attack("Bonas");
	std::cout << "-----------------------------------------" << std::endl;
	std::cout << std::endl;

	std::cout << "-- Testing functionality:                " << std::endl;	
	ScavTrap mavis("Dave");
	ScavTrap olivia("Silvia");	
	mavis.attack("Silvia");
	olivia.takeDamage(mavis.getAttackDamage());	
	olivia.beRepaired(10);
	olivia.attack("Dave");
	mavis.takeDamage(olivia.getAttackDamage());
	olivia.attack("Dave");
	mavis.takeDamage(olivia.getAttackDamage());
	mavis.beRepaired(2);	
	mavis.attack("Silvia");
	olivia.takeDamage(mavis.getAttackDamage());
	olivia.beRepaired(2);
	olivia.attack("Dave");
	mavis.takeDamage(mavis.getAttackDamage());	
	std::cout << "------------------------------------------" << std::endl;
	std::cout << std::endl;

	// std::cout << std::endl;
	// std::cout << "* * * ORIGINAL CLAPTRAP TESTS:                " << std::endl;	
	// std::cout << std::endl;
	// std::cout << "-- Testing copy constructor:             " << std::endl;
	// ClapTrap jimbob("Jimbob");
	// ClapTrap jimbob2(jimbob);
	// jimbob2.attack("Jimbob");
	// std::cout << "-----------------------------------------" << std::endl;
	// std::cout << std::endl;

	// std::cout << "-- Testing assignment operator overload: " << std::endl;	
	// ClapTrap milou("Milou");
	// ClapTrap jonas("Jonas");	
	// milou = jonas;
	// milou.attack("Jonas");
	// std::cout << "-----------------------------------------" << std::endl;
	// std::cout << std::endl;

	// std::cout << "-- Testing functionality:                " << std::endl;	
	// ClapTrap dave("Dave");
	// ClapTrap silvia("Silvia");	
	// dave.attack("Silvia");
	// silvia.takeDamage(dave.getAttackDamage());	
	// silvia.beRepaired(10);
	// silvia.attack("Dave");
	// dave.takeDamage(silvia.getAttackDamage());
	// silvia.attack("Dave");
	// dave.takeDamage(silvia.getAttackDamage());
	// dave.beRepaired(2);	
	// dave.attack("Silvia");
	// silvia.takeDamage(dave.getAttackDamage());
	// silvia.beRepaired(2);
	// silvia.attack("Dave");
	// dave.takeDamage(dave.getAttackDamage());	
	// std::cout << "------------------------------------------" << std::endl;
	// std::cout << std::endl;

	std::cout << std::endl;
	std::cout << "* * * DESTRUCTIONS FOR BOTH SETS OF TESTS:                " << std::endl;	
	return (0);
}