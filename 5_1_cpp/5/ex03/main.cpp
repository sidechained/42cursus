#include <iostream>
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

std::ostream&	operator<<(std::ostream &stream, const Bureaucrat &bureaucrat)
{
	stream << 
	"Bureaucrat is called: " << bureaucrat.getName() << std::endl <<
	"Bureaucrat has a grade of: " << bureaucrat.getGrade() << std::endl;
	return(stream);
}

std::ostream&	operator<<(std::ostream &stream, const AForm &form)
{
	stream << 
	"AForm is entitled: " << form.getName() << std::endl <<
	"AForm can be signed with a grade of: " << form.getRequiredGradeToSign() << std::endl <<
	"AForm can be executed with a grade of: " << form.getRequiredGradeToExecute() << std::endl <<
	"AForm is currently " << (form.getIsSigned() ? "" : "not ") << "signed" << std::endl;
	return(stream);
}

int main()
{
	// improve these tests - print target of form
	Intern  someRandomIntern;

	std::cout << "Testing if intern can make a shrubbery creation form:" << std::endl;
	AForm* scf;
	scf = someRandomIntern.makeAForm("shrubbery creation", "Home");
	std::cout << scf->getName() << std::endl;
	delete scf;
	std::cout << std::endl;
	
	std::cout << "Testing if intern can make a robotomy request form:" << std::endl;
	AForm* rrf;
	rrf = someRandomIntern.makeAForm("robotomy request", "Bender");
	std::cout << rrf->getName() << std::endl;
	delete rrf;
	std::cout << std::endl;
	
	std::cout << "Testing if intern can make a presidential pardon form:" << std::endl;
	AForm* ppf;
	ppf = someRandomIntern.makeAForm("presidential pardon", "Arthur Dent");
	std::cout << ppf->getName() << std::endl;
	delete ppf;
	std::cout << std::endl;
	
	std::cout << "Testing what happens when intern is asked to make a non-existent form:" << std::endl;
	AForm* css;
	css = someRandomIntern.makeAForm("citizenship survey", "Alien");
	if (css == NULL)
		std::cout << "No form was made!" << std::endl;
	delete css;
	std::cout << std::endl;
	
	return 0;
}