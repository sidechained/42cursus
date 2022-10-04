#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string name, int grade)
{
	std::cout << "Bureaucrat constructor called" << std::endl;
	std::cout << "name = " << name << ", grade = " << grade << std::endl;
	this->_name = name;
	this->_grade = grade;
	checkGrade();
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor called" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat &orig)
{
	std::cout << "Bureaucrat copy-constructor called" << std::endl;
	*this = orig;
}

Bureaucrat&	Bureaucrat::operator=(Bureaucrat &orig)
{
	std::cout << "Bureaucrat operator overload called" << std::endl;	
	this->_name = orig.getName();
	this->_grade = orig.getGrade();
	return(*this);
}

std::string	Bureaucrat::getName()
{
	std::cout << "Bureaucrat getName method called" << std::endl;	
	return(this->_name);
}

int Bureaucrat::getGrade()
{
	std::cout << "Bureaucrat getGrade method called" << std::endl;	
	return(this->_grade);
}

void Bureaucrat::incGrade()
{
	std::cout << "Bureaucrat incGrade method called" << std::endl;	
	this->_grade--;
	checkGrade();
}

void Bureaucrat::decGrade()
{
	std::cout << "Bureaucrat decGrade method called" << std::endl;	
	this->_grade++;
	checkGrade();
}

void	Bureaucrat::checkGrade() const
{
	std::cout << "Bureaucrat checkGrade method called" << std::endl;
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}