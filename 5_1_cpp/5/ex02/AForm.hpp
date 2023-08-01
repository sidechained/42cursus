#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <stdexcept>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const	std::string _name;
		bool	_isSigned;
		const int	_requiredGradeToSign;
		const int	_requiredGradeToExecute;
	public:
		AForm(const std::string name, const int requiredGradeToSign, const int requiredGradeToExecute);
		virtual ~AForm() = 0;
		AForm(AForm &orig);
		AForm& operator=(AForm &orig);
		std::string	getName() const;
		bool getIsSigned() const;
		int	getRequiredGradeToSign() const;
		int	getRequiredGradeToExecute() const;
		void checkGrade() const;
		void beSigned(Bureaucrat &bureaucrat);
		void  checkIfExecutable(Bureaucrat const & executor) const;		
		virtual	void execute(Bureaucrat const & executor) const = 0;
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
		class AFormIsNotSignedException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("ERROR: Form is not signed...aborting!");
				}
		};		
};

std::ostream&	operator<<(std::ostream &stream, const AForm &form);

#endif