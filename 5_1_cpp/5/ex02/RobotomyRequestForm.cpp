#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target):
	AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	// std::cout << "RobotomyRequestForm constructor called" << std::endl;
	std::srand(static_cast<unsigned int>(std::time(NULL)));
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	// std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	// std::cout << "RobotomyRequestForm execute method called" << std::endl;
	checkIfExecutable(executor);
	std::cout << "DRRRR BRRRR GRRRR BAM BAM BAM CLANG" << std::endl;
	if ((rand() % 2) == 1)
		std::cout << _target << " has been robotomized successfully" << std::endl;
	else
		std::cout << _target << " has failed to be robotomized" << std::endl;
}