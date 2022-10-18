#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include <fstream>
#include <cstdlib> 
#include <ctime> 
#include "Form.hpp"

class RobotomyRequestForm : public Form
{
	private:
		std::string _target;
	public:
		RobotomyRequestForm(std::string target);
		~RobotomyRequestForm();
		void execute(Bureaucrat const &executor) const;
};

#endif