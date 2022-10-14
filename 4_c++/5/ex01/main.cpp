// TODO: more comprehensive tests and add back old tests

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

void signFormWorseGrade_test()
{
	std::cout << std::endl;
	std::cout << "Testing: signForm function - when bureaucrat grade worse than (>) signing requirement" << std::endl;
	Bureaucrat* dave = new Bureaucrat("Dave", 5);
	std::cout << *dave;
	Form* form = new Form("Citizenship Agreement", 4, 2);
	std::cout << *form;
	dave->signForm(*form);
	delete form;
	delete dave;
	std::cout << std::endl;
}

void signFormBetterGrade_test()
{
	std::cout << std::endl;
	std::cout << "Testing: signForm function - when bureaucrat grade better than (<) signing requirement" << std::endl;
	Bureaucrat* dave = new Bureaucrat("Dave", 3);
	std::cout << *dave;
	Form* form = new Form("Citizenship Agreement", 4, 2);
	std::cout << *form;
	dave->signForm(*form);
	delete form;
	delete dave;
	std::cout << std::endl;
}

void beSignedWorseGrade_test()
{
	std::cout << std::endl;
	std::cout << "Testing: beSigned_test function - when bureaucrat grade worse than (<) signing requirement" << std::endl;
	Bureaucrat* dave = new Bureaucrat("Dave", 5);
	std::cout << *dave;
	Form* form = new Form("Citizenship Agreement", 4, 2);
	std::cout << *form;
	form->beSigned(*dave);
	std::cout << "Form isSigned = " << form->getIsSigned() << std::endl;
	delete form;
	delete dave;
	std::cout << std::endl;
}

void beSignedBetterGrade_test()
{
	std::cout << std::endl;
	std::cout << "Testing: beSigned_test function - when bureaucrat grade better than (<) signing requirement" << std::endl;
	Bureaucrat* dave = new Bureaucrat("Dave", 3);
	std::cout << *dave;
	Form* form = new Form("Citizenship Agreement", 4, 2);
	std::cout << *form;
	form->beSigned(*dave);
	std::cout << "Form isSigned = " << form->getIsSigned() << std::endl;
	delete form;
	delete dave;
	std::cout << std::endl;
}


int main()
{
	// signFormWorseGrade_test();
	// signFormBetterGrade_test();
	try
	{
		beSignedWorseGrade_test();
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	beSignedBetterGrade_test();
}

