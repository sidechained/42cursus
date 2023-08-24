#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string name, int grade)
{
	// std::cout << "Bureaucrat constructor called" << std::endl;
	_name = name;
	_grade = grade;
	checkGrade();
}

Bureaucrat::~Bureaucrat()
{
	// std::cout << "Bureaucrat destructor called" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat &orig)
{
	// std::cout << "Bureaucrat copy-constructor called" << std::endl;
	*this = orig;
}

Bureaucrat&	Bureaucrat::operator=(Bureaucrat &orig)
{
	// std::cout << "Bureaucrat operator overload called" << std::endl;	
	_name = orig.getName();
	_grade = orig.getGrade();
	return(*this);
}

std::string	Bureaucrat::getName() const
{
	// std::cout << "Bureaucrat getName method called" << std::endl;	
	return(_name);
}

int Bureaucrat::getGrade() const
{
	// std::cout << "Bureaucrat getGrade method called" << std::endl;	
	return(_grade);
}

void Bureaucrat::incGrade()
{
	// std::cout << "Bureaucrat incGrade method called" << std::endl;	
	_grade--;
	checkGrade();
}

void Bureaucrat::decGrade()
{
	// std::cout << "Bureaucrat decGrade method called" << std::endl;	
	_grade++;
	checkGrade();
}

void	Bureaucrat::checkGrade() const
{
	// std::cout << "Bureaucrat checkGrade method called" << std::endl;
	if (_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

void	Bureaucrat::signForm(AForm &aform) const
{
	if (_grade <= aform.getRequiredGradeToSign())
		std::cout << _name << " signs " << aform.getName() << std::endl;
	else 
		std::cout << _name << " cannot sign " << aform.getName() << " because they don't have a high enough grade" << std::endl;
}

// attempt to execute the form
// if successful, print something like <bureaucrat> executes <form>.
// if unsuccessful, print an explicit error message.
void	Bureaucrat::executeForm(AForm const &aform) const
{	
	// std::cout << "Bureaucrat executeForm method called" << std::endl;
	try
	{
		aform.execute(*this);
		std::cout << "NOTIFICATION: " << _name << " has executed " << aform.getName() << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
