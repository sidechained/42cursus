#ifndef INTERN_HPP
# define INTERN_HPP

#include <string>
#include "Form.hpp"

class Intern
{
	public:
		Intern();
		~Intern();
		Intern(Intern &orig);
		Intern& operator=(Intern &orig);
		Form* makeForm(std::string formName, std::string target);
};

#endif