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
		Form(const std::string name, const int requiredGradeToSign, const int requiredGradeToExecute);
		Form();
		virtual ~Form();
		Form(Form &orig);
		Form&	operator=(Form &orig);
		std::string	getName() const;
		bool	getIsSigned() const;
		int	getRequiredGradeToSign() const;
		int	getRequiredGradeToExecute() const;
		void	checkGrade() const;
		void	beSigned(Bureaucrat &bureaucrat);
		void 	checkIfExecutable(Bureaucrat const & executor) const;		
		virtual	void 	execute(Bureaucrat const & executor) const = 0;

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("FORM ERROR: Grade too high...aborting!");
				}
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("FORM ERROR: Grade too low...aborting!");
				}
		};		

		class FormIsNotSignedException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("ERROR: Form is not signed...aborting!");
				}
		};		
};

std::ostream&	operator<<(std::ostream &stream, const Form &form);

#endif