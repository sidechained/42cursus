#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

std::ostream&	operator<<(std::ostream &stream, const Bureaucrat &bureaucrat)
{
	stream << 
	"Bureaucrat is called: " << bureaucrat.getName() << std::endl <<
	"Bureaucrat has a grade of: " << bureaucrat.getGrade() << std::endl;
	return stream;
}

std::ostream&	operator<<(std::ostream &stream, const Form &form)
{
	stream << 
	"Form is entitled: " << form.getName() << std::endl <<
	"Form can be signed with a grade of: " << form.getRequiredGradeToSign() << std::endl <<
	"Form is currently " << (form.getIsSigned() ? "" : "not ") << "signed" << std::endl;
	return stream;
}

void bureaucratTest(int grade)
{
	Bureaucrat* dave;
	Form* form;
	dave = new Bureaucrat("Dave", grade);
	std::cout << *dave;
	form = new Form("Citizenship Agreement", 4, 2);
	std::cout << *form;
	std::cout << "Test 1: Calling Form besigned method..." << std::endl;
	try
	{
		form->beSigned(*dave); // why is Bureaucrat error thrown not form error?
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "Result: Form isSigned = " << std::boolalpha << form->getIsSigned() << std::endl;
	std::cout << "Test 2: Calling Bureaucrat signForm method..." << std::endl;	
	try
	{
		dave->signForm(*form);
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	delete dave;
	delete form;
}

int main()
{
	std::cout << "-Testing Bureaucrat signForm and Form beSigned functions" << std::endl << " [when bureaucrat grade better (<) than signing requirement]:" << std::endl;
	bureaucratTest(3);	
	std::cout << "-Testing Bureaucrat signForm and Form beSigned functions" << std::endl << " [when bureaucrat grade worse (>) than signing requirement]:" << std::endl;
	bureaucratTest(5);
}

