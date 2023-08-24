#include <iostream>
#include "Bureaucrat.hpp"

// << operator overload, allowing the object of type Bureaucrat to be output to an output stream.
std::ostream&	operator<<(std::ostream &stream, const Bureaucrat &bureaucrat)
{
	stream << 
	"Bureaucrat is called: " << bureaucrat.getName() << std::endl <<
	"Bureaucrat has a grade of: " << bureaucrat.getGrade() << std::endl;
	return stream;
}

void	test_gradeWithinRange()
{
	std::cout << "-TESTING: Grade within normal range (shouldn't raise an error)" << std::endl;
	try
	{
		Bureaucrat *dave = new Bureaucrat("Dave", 5);
		std::cout << *dave;
		delete dave;
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
}

void	test_gradeTooLow()
{
	std::cout << "-TESTING: Grade set too high in constructor" << std::endl;
	try
	{
		Bureaucrat *dave = new Bureaucrat("Dave", -10);
		std::cout << *dave;
		delete dave;
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
}

void	test_gradeTooHigh()
{
	std::cout << "-TESTING: Grade set too low in constructor" << std::endl;
	try
	{
		Bureaucrat *dave = new Bureaucrat("Dave", 200);
		std::cout << *dave;		

		delete dave;
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

}

void	test_gradeDecrementedTooLow()
{
	std::cout << "-TESTING: Grade decremented too low" << std::endl;
	Bureaucrat *dave = NULL;
	try
	{
		dave = new Bureaucrat("Dave", 149);
		std::cout << *dave;
		std::cout << "Decrementing grade" << std::endl;			
		dave->decGrade();
		std::cout << "Bureaucrat has new a grade of: " << dave->getGrade() << std::endl;
		dave->decGrade();
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
		delete dave;
	}
	std::cout << std::endl;

}

void	test_gradeIncrementedTooHigh()
{
	std::cout << "-TESTING: Grade incremented too high" << std::endl;
	Bureaucrat *dave = NULL;
	try
	{
		dave = new Bureaucrat("Dave", 2);
		std::cout << *dave;	
		dave->incGrade();
		std::cout << "Bureaucrat has new a grade of: " << dave->getGrade() << std::endl;		
		dave->incGrade();
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
		delete dave;
	}
	std::cout << std::endl;
}

int main()
{
	std::cout << std::endl;
	test_gradeWithinRange();
	test_gradeTooLow();
	test_gradeTooHigh();
	test_gradeDecrementedTooLow();
	test_gradeIncrementedTooHigh();
	return 0;
}