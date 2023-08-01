#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include <fstream>
#include "AForm.hpp"

class PresidentialPardonAForm : public AForm
{
	private:
		std::string _target;
	public:
		PresidentialPardonAForm(std::string target);
		~PresidentialPardonAForm();
		void execute(Bureaucrat const &executor) const;
};

#endif