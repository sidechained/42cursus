#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include <fstream>
#include "AForm.hpp"

class ShrubberyCreationAForm : public AForm
{
	private:
		std::string _target;
	public:
		ShrubberyCreationAForm(std::string target);
		~ShrubberyCreationAForm();
		void execute(Bureaucrat const &executor) const;
};

#endif