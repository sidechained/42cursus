#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include <fstream>
#include <cstdlib> 
#include <ctime> 
#include "AForm.hpp"

class RobotomyRequestAForm : public AForm
{
	private:
		std::string _target;
	public:
		RobotomyRequestAForm(std::string target);
		~RobotomyRequestAForm();
		void execute(Bureaucrat const &executor) const;
};

#endif