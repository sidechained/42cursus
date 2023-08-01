#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name), _grade(grade)
{
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

void	Bureaucrat::signForm(Form &form) const
{
	if (_grade <= form.getRequiredGradeToSign())
		std::cout << _name << " signs " << form.getName() << std::endl;
	else 
		std::cout << _name << " cannot sign " << form.getName() << " because they don't have a high enough grade" << std::endl;
}

