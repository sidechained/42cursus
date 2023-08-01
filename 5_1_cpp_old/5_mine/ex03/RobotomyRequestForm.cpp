#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target):
	Form("RobotomyRequestForm", 75, 45), _target(target)
{
	std::cout << "RobotomyRequestForm constructor called" << std::endl;
	std::srand(static_cast<unsigned int>(std::time(nullptr)));
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	std::cout << "RobotomyRequestForm execute method called" << std::endl;
	this->checkIfExecutable(executor);
	std::cout << "DRRRR BRRRR GRRRR BAM BAM BAM CLANG" << std::endl;
	if ((rand() % 2) == 1)
		std::cout << _target << " has been robotomized successfully" << std::endl;
	else
		std::cout << _target << " has failed to be robotomized" << std::endl;
}