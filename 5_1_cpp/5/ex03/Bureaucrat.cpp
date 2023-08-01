#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string name, int grade)
{
	_name = name;
	_grade = grade;
	checkGrade();
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat::Bureaucrat(Bureaucrat &orig)
{
	*this = orig;
}

Bureaucrat&	Bureaucrat::operator=(Bureaucrat &orig)
{
	_name = orig.getName();
	_grade = orig.getGrade();
	return(*this);
}

std::string	Bureaucrat::getName() const
{
	return(_name);
}

int Bureaucrat::getGrade() const
{
	return(_grade);
}

void Bureaucrat::incGrade()
{
	_grade--;
	checkGrade();
}

void Bureaucrat::decGrade()
{
	_grade++;
	checkGrade();
}

void	Bureaucrat::checkGrade() const
{
	if (_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

void	Bureaucrat::signAForm(AForm &form) const
{
	if (_grade <= form.getRequiredGradeToSign())
		std::cout << _name << " signs " << form.getName() << std::endl;
	else 
		std::cout << _name << " cannot sign " << form.getName() << " because they don't have a high enough grade" << std::endl;
}

// attempt to execute the form
// if successful, print something like <bureaucrat> executes <form>.
// if unsuccessful, print an explicit error message.
void	Bureaucrat::executeAForm(AForm const &form) const
{	
	try
	{
		form.execute(*this);
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "NOTIFICATION: " << _name << " has executed " << form.getName() << std::endl;
}

