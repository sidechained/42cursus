#include "AForm.hpp"

AForm::AForm(const std::string name, const int requiredGradeToSign, const int requiredGradeToExecute):
	_name(name), _isSigned(false), _requiredGradeToSign(requiredGradeToSign), _requiredGradeToExecute(requiredGradeToExecute)
{
	checkGrade();
}

AForm::AForm():
	_name(""), _isSigned(false), _requiredGradeToSign(1), _requiredGradeToExecute(1)
{
}

AForm::~AForm()
{
}

AForm::AForm(AForm &orig):
	_name(orig.getName()), _isSigned(orig.getIsSigned()),
	_requiredGradeToSign(orig.getRequiredGradeToSign()), _requiredGradeToExecute(orig.getRequiredGradeToExecute())
{
	*this = orig;
}

AForm& AForm::operator=(AForm &orig)
{
	std::cout << "WARNING: _name, _requiredGradeToSign and __requiredGradeToExecute not copied as they are const" << std::endl;
	_isSigned = orig.getIsSigned();
	return(*this);
}

std::string AForm::getName() const
{
	return(_name);
}

bool	AForm::getIsSigned() const
{
	return(_isSigned);	
}

int	AForm::getRequiredGradeToSign() const
{
	return(_requiredGradeToSign);
}

int	AForm::getRequiredGradeToExecute() const
{
	return(_requiredGradeToExecute);	
}

void	AForm::checkGrade() const
{
	if (_requiredGradeToSign < 1 || _requiredGradeToExecute < 1)
		throw AForm::GradeTooHighException();
	else if (_requiredGradeToSign > 150 || _requiredGradeToExecute > 150)
		throw AForm::GradeTooLowException();
}

// 	makes the form signed if the bureaucrat’s grade is high enough.
// If the grade is too low, throw a AForm::GradeTooLowException.
void	AForm::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= _requiredGradeToSign)
		_isSigned = true;
	else
	{
		_isSigned = false;
		throw Bureaucrat::GradeTooLowException();
	}
}

void 	AForm::checkIfExecutable(Bureaucrat const & executor) const
{
	if (_isSigned == false)
	{
		throw AForm::AFormIsNotSignedException();
	}
	if (executor.getGrade() > _requiredGradeToExecute )
	{
		throw AForm::GradeTooLowException();
	}
}
