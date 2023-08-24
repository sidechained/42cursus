#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target):
	AForm("RobotomyRequestForm", 75, 45), _target(target)
{
	std::srand(static_cast<unsigned int>(std::time(NULL)));
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	checkIfExecutable(executor);
	std::cout << "DRRRR BRRRR GRRRR BAM BAM BAM CLANG" << std::endl;
	if ((rand() % 2) == 1)
		std::cout << _target << " has been robotomized successfully" << std::endl;
	else
		std::cout << _target << " has failed to be robotomized" << std::endl;
}