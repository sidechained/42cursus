#include "PresidentialPardonForm.hpp"

PresidentialPardonAForm::PresidentialPardonAForm(std::string target):
	AForm("PresidentialPardonAForm", 25, 5), _target(target)
{
}

PresidentialPardonAForm::~PresidentialPardonAForm()
{
}

void PresidentialPardonAForm::execute(Bureaucrat const &executor) const
{
	checkIfExecutable(executor);
	std::cout << _target << " has been pardoned by Zafod Beeblebrox" << std::endl;

}