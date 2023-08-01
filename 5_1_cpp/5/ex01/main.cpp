#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

std::ostream&	operator<<(std::ostream &stream, const Bureaucrat &bureaucrat)
{
	stream << 
	"Bureaucrat is called: " << bureaucrat.getName() << std::endl <<
	"Bureaucrat has a grade of: " << bureaucrat.getGrade() << std::endl;
	return(stream);
}

std::ostream&	operator<<(std::ostream &stream, const Form &form)
{
	stream << 
	"Form is entitled: " << form.getName() << std::endl <<
	"Form can be signed with a grade of: " << form.getRequiredGradeToSign() << std::endl <<
	"Form can be executed with a grade of: " << form.getRequiredGradeToExecute() << std::endl <<
	"Form is currently " << (form.getIsSigned() ? "" : "not ") << "signed" << std::endl;
	return(stream);
}

void bureaucratTest(int grade)
{
	std::cout << std::endl;
	Bureaucrat* dave = NULL;
	Form* form = NULL;
	try
	{
		dave = new Bureaucrat("Dave", grade);
		std::cout << *dave;
		form = new Form("Citizenship Agreement", 4, 2);
		std::cout << *form;
		dave->signForm(*form);
		form->beSigned(*dave);
		std::cout << "Form isSigned = " << form->getIsSigned() << std::endl;
		delete dave;
		delete form;
		std::cout << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
		delete dave;
		delete form;
		return ;
	}
}

// how to detect if a form grade is out of bounds?
void formTest(int grade)
{
	std::cout << std::endl;
	Bureaucrat* dave = new Bureaucrat("Dave", 1);
	std::cout << *dave;
	Form* form = new Form("Citizenship Agreement", 2, 160);
	std::cout << *form;
	dave->signForm(*form);
	form->beSigned(*dave);
	std::cout << "Form isSigned = " << form->getIsSigned() << std::endl;	
	delete form;
	delete dave;
	std::cout << std::endl;
}

int main()
{
	std::cout << "-Testing Bureaucrat signForm function [when bureaucrat grade within range of signing requirement]:" << std::endl;
	bureaucratTest(3);	
	std::cout << "-Testing signForm and beSigned functions [when bureaucrat grade worse/> than signing requirement]:" << std::endl;
	bureaucratTest(5);
	std::cout << "-Testing Bureaucrat signForm function [when bureaucrat grade better/< than signing requirement]:" << std::endl;
	bureaucratTest(1);
	// std::cout << "-Testing Bureaucrat signForm function [when bureaucrat grade better/< than signing requirement]:" << std::endl;
	// std::cout << "-Testing Bureaucrat signForm function [when bureaucrat grade better/< than signing requirement]:" << std::endl;
	// std::cout << "-Testing Bureaucrat signForm function [when bureaucrat grade better/< than signing requirement]:" << std::endl;
}

