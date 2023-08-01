#include "AForm.hpp"

AForm::AForm(const std::string name, const int requiredGradeToSign, const int requiredGradeToExecute):
	_name(name), _isSigned(false), _requiredGradeToSign(requiredGradeToSign), _requiredGradeToExecute(requiredGradeToExecute)
{
	// std::cout << "AForm constructor called" << std::endl;
	checkGrade();
}

AForm::~AForm()
{
	// std::cout << "AForm destructor called" << std::endl;
}

AForm::AForm(AForm &orig):
	_name(orig.getName()), _isSigned(orig.getIsSigned()),
	_requiredGradeToSign(orig.getRequiredGradeToSign()), _requiredGradeToExecute(orig.getRequiredGradeToExecute())
{
	// std::cout << "AForm copy-constructor called" << std::endl;
	*this = orig;
}

AForm& AForm::operator=(AForm &orig)
{
	// std::cout << "AForm operator = overload called" << std::endl;
	std::cout << "WARNING: _name, _requiredGradeToSign and __requiredGradeToExecute not copied as they are const" << std::endl;
	_isSigned = orig.getIsSigned();
	return(*this);
}

std::string AForm::getName() const
{
	// std::cout << "AForm getName method called" << std::endl;
	return(_name);
}

bool	AForm::getIsSigned() const
{
	// std::cout << "AForm getIsSigned method called" << std::endl;
	return(_isSigned);	
}

int	AForm::getRequiredGradeToSign() const
{
	// std::cout << "AForm getRequiredGradeToSign method called" << std::endl;
	return(_requiredGradeToSign);
}

int	AForm::getRequiredGradeToExecute() const
{
	// std::cout << "AForm getRequiredGradeToExecute method called" << std::endl;
	return(_requiredGradeToExecute);	
}

void	AForm::checkGrade() const
{
	// std::cout << "AForm checkGrade method called" << std::endl;
	if (_requiredGradeToSign < 1 || _requiredGradeToExecute < 1)
		throw AForm::GradeTooHighException();
	else if (_requiredGradeToSign > 150 || _requiredGradeToExecute > 150)
		throw AForm::GradeTooLowException();
}

// 	makes the AForm signed if the bureaucrat’s grade is high enough.
// If the grade is too low, throw a AForm::GradeTooLowException.
void	AForm::beSigned(Bureaucrat &bureaucrat)
{
	// std::cout << "AForm beSigned method called" << std::endl;
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
	// std::cout << "AForm checkIfExecutable method called" << std::endl;
	if (_isSigned == false)
	{
		throw AForm::AFormIsNotSignedException();
	}
	if (executor.getGrade() > _requiredGradeToExecute )
	{
		throw AForm::GradeTooLowException();
	}
}

// non-member function
std::ostream&	operator<<(std::ostream &stream, const AForm &AForm)
{
	stream << 
	"AForm is entitled: " << AForm.getName() << std::endl <<
	"AForm can be signed with a grade of: " << AForm.getRequiredGradeToSign() << std::endl <<
	"AForm can be executed with a grade of: " << AForm.getRequiredGradeToExecute() << std::endl <<
	"AForm is currently " << (AForm.getIsSigned() ? "" : "not ") << "signed" << std::endl;
	return(stream);
}