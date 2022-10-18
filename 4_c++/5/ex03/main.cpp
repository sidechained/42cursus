#include <iostream>
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	std::cout << std::endl;
	std::cout << "1. Creating a random intern:" << std::endl;
	Intern  someRandomIntern;
	std::cout << std::endl;

	std::cout << "2. Testing if intern can make a shrubbery creation form:" << std::endl;
	Form*   scf;
	scf = someRandomIntern.makeForm("shrubbery creation", "Home");
	delete scf;
	std::cout << std::endl;
	
	std::cout << "3. Testing if intern can make a robotomy request form:" << std::endl;
	Form*   rrf;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	delete rrf;
	std::cout << std::endl;
	
	std::cout << "4. Testing if intern can make a presidential pardon form:" << std::endl;
	Form*   ppf;
	ppf = someRandomIntern.makeForm("presidential pardon", "Arthur Dent");
	delete ppf;
	std::cout << std::endl;
	
	std::cout << "5. Testing what happens when intern is asked to make a non-existent form:" << std::endl;
	Form*   css;
	css = someRandomIntern.makeForm("citizenship survey", "Alien");
	delete css;
	std::cout << std::endl;
	
	std::cout << "5. Deleting the random Intern (when program ends):" << std::endl;

	return(0);
}