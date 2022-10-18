#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
	std::cout << "Intern constructor called" << std::endl;
}

Intern::~Intern()
{
	std::cout << "Intern destructor called" << std::endl;
}

Intern::Intern(Intern &orig)
{
	std::cout << "Intern copy-constructor called" << std::endl;
	*this = orig;
}

Intern&	Intern::operator=(Intern &orig)
{
	std::cout << "Intern operator overload called" << std::endl;
	(void)orig;
	return(*this);
}

Form* Intern::makeForm(std::string formName, std::string target)
{
	std::string formNames[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	Form* formTypes[3] = {new ShrubberyCreationForm(target), new RobotomyRequestForm(target), new PresidentialPardonForm(target)};
	Form* formToReturn = NULL;
	int i;
	i = 0;
	while(i < 3)
	{
		if(formName == formNames[i])
			formToReturn = formTypes[i];
		else
			delete formTypes[i];
		i++;
	}
	if (formToReturn == NULL)
		std::cout << "ERROR: No Form found of that type" << std::endl;
	else
		std::cout << "SUCCESS: Intern creates " << formName << "form!" << std::endl;
	return(formToReturn);
} 