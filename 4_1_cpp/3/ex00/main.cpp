#include "ClapTrap.hpp"

void test_default_constructor()
{
	std::cout << std::endl;
	std::cout << "----------------------------------------------------------------------------------" << std::endl;
	std::cout << "-- Testing default constructor: (\"nobody\" created)" << std::endl;
	ClapTrap nobody;
}

void test_copy_constructor()
{
	std::cout << std::endl;
	std::cout << "----------------------------------------------------------------------------------" << std::endl;
	std::cout << "-- Testing copy constructor: (object attacks a copy of itself)" << std::endl;
	ClapTrap jimbob("Jimbob");
	ClapTrap jimbob2(jimbob);
	jimbob2.attack("Jimbob");
}

void test_assignment_op()
{
	std::cout << std::endl;
	std::cout << "----------------------------------------------------------------------------------" << std::endl;
	std::cout << "-- Testing assignment operator overload:" << std::endl;	
	std::cout << "   (milou = jonas. When Milou attacks Jonas, the copied Jonas will be attacking the original Jonas!)" << std::endl;	
	ClapTrap milou("Milou");
	ClapTrap jonas("Jonas");	
	milou = jonas;
	milou.attack("Jonas");
}

void test_functionality()
{
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
}

int main()
{
	test_default_constructor();
	test_copy_constructor();
	test_assignment_op();
	test_functionality();
	return 0;
}
