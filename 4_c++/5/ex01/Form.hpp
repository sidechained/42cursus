#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const	std::string _name;
		bool	_isSigned;
		const int	_requiredGradeToSign;
		const int	_requiredGradeToExecute;
	public:
		// Form(const std::string name, int grade);
		Form(const std::string name, const int requiredGradeToSign, const int requiredGradeToExecute);
		// Form();
		~Form();
		Form(Form &orig);
		Form&	operator=(Form &orig);
		std::string	getName() const;
		bool	getIsSigned() const;
		int	getRequiredGradeToSign() const;
		int	getRequiredGradeToExecute() const;
		void	beSigned(Bureaucrat &bureaucrat);

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("ERROR: Grade too high...aborting!");
				}
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("ERROR: Grade too low...aborting!");
				}
		};		
};

std::ostream&	operator<<(std::ostream &stream, const Form &form);

#endif