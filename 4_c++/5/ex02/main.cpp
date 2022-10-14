#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	Bureaucrat* dave = new Bureaucrat("dave", 5);
	ShrubberyCreationForm* shrub = new ShrubberyCreationForm("home");
	dave->executeForm(*shrub);
}