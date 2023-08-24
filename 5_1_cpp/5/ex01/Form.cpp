#include "Form.hpp"

Form::Form(const std::string name, const int requiredGradeToSign, const int requiredGradeToExecute):
	_name(name), _isSigned(false), _requiredGradeToSign(requiredGradeToSign), _requiredGradeToExecute(requiredGradeToExecute)
{
	checkGrade();
}

Form::~Form()
{
}

Form::Form(Form &orig):
	_name(orig.getName()), _isSigned(orig.getIsSigned()),
	_requiredGradeToSign(orig.getRequiredGradeToSign()), _requiredGradeToExecute(orig.getRequiredGradeToExecute())
{
	*this = orig;
}

Form& Form::operator=(Form &orig)
{
	std::cout << "WARNING: _name, _requiredGradeToSign and __requiredGradeToExecute not copied as they are const" << std::endl;
	_isSigned = orig.getIsSigned();
	return(*this);
}

std::string Form::getName() const
{
	return(_name);
}

bool	Form::getIsSigned() const
{
	return(_isSigned);	
}

int	Form::getRequiredGradeToSign() const
{
	return(_requiredGradeToSign);
}

int	Form::getRequiredGradeToExecute() const
{
	return(_requiredGradeToExecute);	
}

void	Form::checkGrade() const
{
	if (_requiredGradeToSign < 1 || _requiredGradeToExecute < 1)
		throw Form::GradeTooHighException();
	else if (_requiredGradeToSign > 150 || _requiredGradeToExecute > 150)
		throw Form::GradeTooLowException();
}

// 	makes the form signed if the bureaucrat’s grade is high enough.
// If the grade is too low, throw a Form::GradeTooLowException.
void	Form::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= _requiredGradeToSign)
		_isSigned = true;
	else
	{
		_isSigned = false;
		throw Form::GradeTooLowException();
	}
}
