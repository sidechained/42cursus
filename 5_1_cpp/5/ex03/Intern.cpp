#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
}

Intern::~Intern()
{
}

Intern::Intern(Intern &orig)
{
	*this = orig;
}

Intern&	Intern::operator=(Intern &orig)
{
	(void)orig;
	return(*this);
}

AForm* Intern::makeForm(std::string formName, std::string target)
{
	std::string formNames[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm* formTypes[3] = {new ShrubberyCreationForm(target), new RobotomyRequestForm(target), new PresidentialPardonForm(target)};
	AForm* formToReturn = NULL;
	for (int i = 0; i < 3; i++)
	{
		if(formName == formNames[i])
			formToReturn = formTypes[i];
		else
			delete formTypes[i];
	}
	if (formToReturn == NULL)
		std::cout << "ERROR: No AForm found of that type" << std::endl;
	else
		std::cout << "SUCCESS: Intern creates " << formName << " form!" << std::endl;
	return(formToReturn);
} 