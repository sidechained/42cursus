#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

// non-member function
std::ostream&	operator<<(std::ostream &stream, const Bureaucrat &bureaucrat)
{
	stream << 
	"Bureaucrat is called: " << bureaucrat.getName() << std::endl <<
	"Bureaucrat has a grade of: " << bureaucrat.getGrade() << std::endl;
	return(stream);
}

void gradeTooLowForExecution_Test()
{
	std::cout << std::endl;
	std::cout << "---ShrubberyCreationForm 'Grade Too Low For Execution' Test" << std::endl;
	Bureaucrat* dave = new Bureaucrat("dave", 150);	
	ShrubberyCreationForm* shrub = new ShrubberyCreationForm("home");
	bool exceptionCaught = false;
	try {
		shrub->beSigned(*dave);	
		dave->executeForm(*shrub);
	}
	catch(std::exception &e) {
		std::cout << e.what() << std::endl;
		exceptionCaught = true;
		delete shrub;
		delete dave;
	}
	if (exceptionCaught == false)
	{
		delete shrub;
		delete dave;
	}
	std::cout << std::endl;
}

void formNotSigned_Test()
{
	std::cout << "-ShrubberyCreationForm 'Not Signed' Test" << std::endl;
	Bureaucrat* dave = new Bureaucrat("dave", 5);	
	ShrubberyCreationForm* shrub = new ShrubberyCreationForm("home");
	bool exceptionCaught = false;
	try {
		dave->executeForm(*shrub);
	}
	catch(std::exception &e) {
		std::cout << e.what() << std::endl;
		exceptionCaught = true;
		delete shrub;
		delete dave;
	}
	if (exceptionCaught == false)
	{
		delete shrub;
		delete dave;
	}
	std::cout << std::endl;
}

void shrubberyCreationForm_ExecutionTest()
{
	std::cout << "-ShrubberyCreationForm Execution Test" << std::endl;
	ShrubberyCreationForm* shrub = new ShrubberyCreationForm("home");
	Bureaucrat* dave = new Bureaucrat("dave", 5);
	bool exceptionCaught = false;
	try {
		shrub->beSigned(*dave);
		dave->executeForm(*shrub);
	}
	catch(std::exception &e) {
		std::cout << e.what() << std::endl;
		exceptionCaught = true;
		delete shrub;
		delete dave;
	}
	if (exceptionCaught == false)
	{
		delete shrub;
		delete dave;
	}
	std::cout << std::endl;		
}

void robotomyRequestForm_ExecutionTest()
{
	std::cout << "-RobotomyRequestForm Execution Test" << std::endl;
	RobotomyRequestForm* rob = new RobotomyRequestForm("blahbot");
	Bureaucrat* dave = new Bureaucrat("dave", 5);
	bool exceptionCaught = false;
	try {
		rob->beSigned(*dave);
		dave->executeForm(*rob);
	}
	catch(std::exception &e) {
		std::cout << e.what() << std::endl;
		exceptionCaught = true;
		delete rob;
		delete dave;
	}
	if (exceptionCaught == false)
	{
		delete rob;
		delete dave;
	}
	std::cout << std::endl;
}

void presidentialPardonForm_ExecutionTest()
{
	std::cout << "-PresidentialPardonForm Execution Test" << std::endl;
	Bureaucrat* dave = new Bureaucrat("dave", 5);	
	PresidentialPardonForm* arthur = new PresidentialPardonForm("Arthur Dent");
	bool exceptionCaught = false;
	try {
		arthur->beSigned(*dave);
		dave->executeForm(*arthur);
	}
	catch(std::exception &e) {
		std::cout << e.what() << std::endl;
		exceptionCaught = true;
		delete dave;
		delete arthur;
	}
	if (exceptionCaught == false)
	{
		delete dave;
		delete arthur;
	}
	std::cout << std::endl;	
}

int main()
{
	gradeTooLowForExecution_Test();
	formNotSigned_Test();
	shrubberyCreationForm_ExecutionTest();
	robotomyRequestForm_ExecutionTest();
	presidentialPardonForm_ExecutionTest();
	return 0;
}