#include <iostream>
#include "Bureaucrat.hpp"

int main()
{
	std::cout << std::endl;
	std::cout << "TESTING: Grade within normal range (shouldn't raise an error):" << std::endl;
	try
	{
		Bureaucrat *dave = new Bureaucrat("Dave", 5);
		std::cout << dave->getName() << std::endl;
		std::cout << dave->getGrade() << std::endl;
		delete dave;
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "TESTING: Grade set too low in constructor:" << std::endl;
	try
	{
		Bureaucrat *dave = new Bureaucrat("Dave", -10);
		std::cout << dave->getName() << std::endl;
		std::cout << dave->getGrade() << std::endl;
		delete dave;
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "TESTING: Grade set too high in constructor:" << std::endl;
	try
	{
		Bureaucrat *dave = new Bureaucrat("Dave", 200);
		std::cout << dave->getName() << std::endl;
		std::cout << dave->getGrade() << std::endl;
		delete dave;
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "TESTING: Grade decremented too low:" << std::endl;
	try
	{
		Bureaucrat *dave = new Bureaucrat("Dave", 149);
		std::cout << dave->getName() << std::endl;
		std::cout << dave->getGrade() << std::endl;
		dave->decGrade();
		std::cout << dave->getGrade() << std::endl;		
		dave->decGrade();
		delete dave;
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "TESTING: Grade incremented too high:" << std::endl;
	try
	{
		Bureaucrat *dave = new Bureaucrat("Dave", 2);
		std::cout << dave->getName() << std::endl;
		std::cout << dave->getGrade() << std::endl;
		dave->incGrade();
		std::cout << dave->getGrade() << std::endl;		
		dave->incGrade();
		delete dave;
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	return(0);
}