#include "Form.hpp"

Form::Form(const std::string name, const int requiredGradeToSign, const int requiredGradeToExecute):
	_name(name), _isSigned(false), _requiredGradeToSign(requiredGradeToSign), _requiredGradeToExecute(requiredGradeToExecute)
{
	std::cout << "Form constructor called" << std::endl;
	// this->_name = name;
	// this->_isSigned = false;
	// this->_requiredGradeToSign = requiredGradeToSign;
	// this->_requiredGradeToExecute = requiredGradeToExecute;
	// check grades
}

// Form::Form():
// 	_name(""), _isSigned(false), _requiredGradeToSign(1), _requiredGradeToExecute(1)
// {
// 	std::cout << "For default constructor called" << std::endl;
// }

Form::~Form()
{
	std::cout << "Form destructor called" << std::endl;
}

Form::Form(Form &orig):
	_name(orig.getName()), _isSigned(orig.getIsSigned()),
	_requiredGradeToSign(orig.getRequiredGradeToSign()), _requiredGradeToExecute(orig.getRequiredGradeToExecute())
{
	std::cout << "Form copy-constructor called" << std::endl;
	*this = orig;
}

Form& Form::operator=(Form &orig)
{
	std::cout << "Form operator = overload called" << std::endl;
	std::cout << "WARNING: _name, _requiredGradeToSign and __requiredGradeToExecute not copied as they are const" << std::endl;
	this->_isSigned = orig.getIsSigned();
	return(*this);
}

std::string Form::getName() const
{
	// std::cout << "Form getName method called" << std::endl;
	return(this->_name);
}

bool	Form::getIsSigned() const
{
	// std::cout << "Form getIsSigned method called" << std::endl;
	return(this->_isSigned);	
}

int	Form::getRequiredGradeToSign() const
{
	// std::cout << "Form getRequiredGradeToSign method called" << std::endl;
	return(this->_requiredGradeToSign);
}

int	Form::getRequiredGradeToExecute() const
{
	// std::cout << "Form getRequiredGradeToExecute method called" << std::endl;
	return(this->_requiredGradeToExecute);
}

// 	makes the form signed if the bureaucrat’s grade is high enough.
// If the grade is too low, throw a Form::GradeTooLowException.
void	Form::beSigned(Bureaucrat &bureaucrat)
{
	std::cout << "Form beSigned method called" << std::endl;
	if (bureaucrat.getGrade() <= this->_requiredGradeToSign)
		this->_isSigned = true;
	else
	{
		this->_isSigned = false;
		throw Bureaucrat::GradeTooLowException();
	}
}

void 	Form::checkIfExecutable(Bureaucrat const & executor) const
{
	std::cout << "Form execute method called" << std::endl;
	if (this->_isSigned == false)
	{
		throw Form::FormIsNotSignedException();
	}
	if (executor.getGrade() > _requiredGradeToExecute )
	{
		throw Form::GradeTooLowException();
	}
}

// non-member function
std::ostream&	operator<<(std::ostream &stream, const Form &form)
{
	stream << 
	"Form is entitled: " << form.getName() << std::endl <<
	"Form can be signed with a grade of: " << form.getRequiredGradeToSign() << std::endl <<
	"Form can be executed with a grade of: " << form.getRequiredGradeToExecute() << std::endl <<
	"Form is currently " << (form.getIsSigned() ? "" : "not ") << "signed" << std::endl;
	return(stream);
}