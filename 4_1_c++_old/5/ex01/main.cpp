#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

void worseGrade_test()
{
	std::cout << std::endl;
	std::cout << "Testing signForm and beSigned functions [when bureaucrat grade worse than (>) signing requirement]" << std::endl;
	Bureaucrat* dave = new Bureaucrat("Dave", 5);
	std::cout << *dave;
	Form* form = new Form("Citizenship Agreement", 4, 2);
	std::cout << *form;
	dave->signForm(*form);
	form->beSigned(*dave);
	std::cout << "Form isSigned = " << form->getIsSigned() << std::endl;
	delete form;
	delete dave;
	std::cout << std::endl;
}


void betterGrade_test()
{
	std::cout << std::endl;
	std::cout << "Testing Bureaucrat signForm function [when bureaucrat grade better than (<) signing requirement]" << std::endl;
	Bureaucrat* dave = new Bureaucrat("Dave", 3);
	std::cout << *dave;
	Form* form = new Form("Citizenship Agreement", 4, 2);
	std::cout << *form;
	dave->signForm(*form);
	form->beSigned(*dave);
	std::cout << "Form isSigned = " << form->getIsSigned() << std::endl;	
	delete form;
	delete dave;
	std::cout << std::endl;
}

void bureaucratGradeTooHigh_test()
{
	std::cout << std::endl;
	std::cout << "Testing Bureaucrat signForm function [when bureaucrat grade better than (<) signing requirement]" << std::endl;
	Bureaucrat* dave = new Bureaucrat("Dave", 0);
	std::cout << *dave;
	Form* form = new Form("Citizenship Agreement", 4, 2);
	std::cout << *form;
	dave->signForm(*form);
	form->beSigned(*dave);
	std::cout << "Form isSigned = " << form->getIsSigned() << std::endl;	
	delete form;
	delete dave;
	std::cout << std::endl;
}

void formGradeTooLow_test()
{
	std::cout << std::endl;
	std::cout << "Testing Bureaucrat signForm function [when bureaucrat grade better than (<) signing requirement]" << std::endl;
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

void formGradeTooHigh_test()
{
	std::cout << std::endl;
	std::cout << "Testing Bureaucrat signForm function [when bureaucrat grade better than (<) signing requirement]" << std::endl;
	Bureaucrat* dave = new Bureaucrat("Dave", 1);
	std::cout << *dave;
	Form* form = new Form("Citizenship Agreement", 0, 2);
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
	try
	{
		worseGrade_test();
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		betterGrade_test();
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		bureaucratGradeTooHigh_test();
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		formGradeTooLow_test();
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}			

	try
	{
		formGradeTooHigh_test();
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}				
}

