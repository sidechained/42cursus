#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void gradeTooLowForExecution_Test()
{
	std::cout << "---ShrubberyCreationForm 'Grade Too Low For Execution' Test" << std::endl;
	Bureaucrat* dave = new Bureaucrat("dave", 150);	
	ShrubberyCreationForm* shrub = new ShrubberyCreationForm("home");
	shrub->beSigned(*dave);	
	dave->executeForm(*shrub);
	delete shrub;
	delete dave;
	std::cout << std::endl;
}

void formNotSigned_Test()
{
	std::cout << "---ShrubberyCreationForm 'Not Signed' Test" << std::endl;
	Bureaucrat* dave = new Bureaucrat("dave", 5);	
	ShrubberyCreationForm* shrub = new ShrubberyCreationForm("home");
	dave->executeForm(*shrub);
	delete shrub;
	delete dave;
	std::cout << std::endl;	
}

void shrubberyCreationForm_ExecutionTest()
{
	std::cout << "---ShrubberyCreationForm Execution Test" << std::endl;
	ShrubberyCreationForm* shrub = new ShrubberyCreationForm("home");
	Bureaucrat* dave = new Bureaucrat("dave", 5);	
	shrub->beSigned(*dave);
	dave->executeForm(*shrub);
	delete shrub;
	delete dave;
	std::cout << std::endl;		
}

void robotomyRequestForm_ExecutionTest()
{
	std::cout << "---RobotomyRequestForm Execution Test" << std::endl;
	RobotomyRequestForm* rob = new RobotomyRequestForm("blahbot");
	Bureaucrat* dave = new Bureaucrat("dave", 5);	
	rob->beSigned(*dave);
	dave->executeForm(*rob);
	delete rob;
	delete dave;
	std::cout << std::endl;
}

void presidentialPardonForm_ExecutionTest()
{
	std::cout << "---PresidentialPardonForm Execution Test" << std::endl;
	Bureaucrat* dave = new Bureaucrat("dave", 5);	
	PresidentialPardonForm* arthur = new PresidentialPardonForm("Arthur Dent");
	arthur->beSigned(*dave);
	dave->executeForm(*arthur);
	delete arthur;
	delete dave;	
}

int main()
{
	std::cout << std::endl;
	try { gradeTooLowForExecution_Test(); }
	catch(std::exception &e) { std::cout << e.what() << std::endl; }

	std::cout << std::endl;
	try { formNotSigned_Test(); }
	catch(std::exception &e) { std::cout << e.what() << std::endl; }

	try { shrubberyCreationForm_ExecutionTest(); }
	catch(std::exception &e) { std::cout << e.what() << std::endl; }

	try { robotomyRequestForm_ExecutionTest(); }
	catch(std::exception &e) { std::cout << e.what() << std::endl; }

	try { presidentialPardonForm_ExecutionTest(); }
	catch(std::exception &e) { std::cout << e.what() << std::endl; }

	return(0);
}