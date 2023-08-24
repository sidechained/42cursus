#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

void test_default_constructor()
{
	std::cout << std::endl;	
	std::cout << "-- Testing default constructor:" << std::endl;
	ScavTrap nobody;
}

void test_copy_constructor()
{
	std::cout << std::endl;	
	std::cout << "-- Testing copy constructor:" << std::endl;
	ScavTrap kimbap("Kimbap");
	ScavTrap kimbap2(kimbap);
	kimbap2.attack("Kimbap");
}

void test_assignment_op()
{
	std::cout << std::endl;	
	std::cout << "-- Testing assignment operator overload:" << std::endl;	
	ScavTrap filou("Filou");
	ScavTrap bonas("Bonas");	
	filou = bonas;
	filou.attack("Bonas");
}

void test_functionality()
{
	std::cout << std::endl;	
	std::cout << "-- Testing functionality:" << std::endl;	
	ScavTrap mavis("Mavis");
	ScavTrap olivia("Olivia");	
	mavis.attack("Olivia");
	olivia.takeDamage(47);	
	olivia.beRepaired(10);
	olivia.attack("Mavis");
	mavis.takeDamage(69);
	mavis.guardGate();
	olivia.attack("Mavis");
	mavis.takeDamage(32);
	mavis.beRepaired(2);	
	mavis.attack("Olivia");
	olivia.takeDamage(49);
	olivia.guardGate();
	olivia.beRepaired(2);
	olivia.attack("Mavis");
	mavis.takeDamage(23);
}

int main()
{
	test_default_constructor();
	test_copy_constructor();
	test_assignment_op();
	test_functionality();
	return 0;
}