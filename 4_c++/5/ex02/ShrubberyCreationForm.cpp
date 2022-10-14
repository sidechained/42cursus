#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target):
_requiredGradeToSign(145), _requiredGradeToExecute(137), _target(target)
{
	std::cout << "ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor)
{
	std::cout << "Form execute method called" << std::endl;
	this->checkIfExecutable(executor);
	std::cout << "Create a file called <target>_shrubbery, and write ASCII trees inside it, in the current directory." << std::endl;
}