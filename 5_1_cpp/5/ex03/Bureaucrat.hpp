#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
	private:
		std::string _name;
		int _grade;	
	public:
		Bureaucrat(const std::string name, int grade);
		~Bureaucrat();
		Bureaucrat(Bureaucrat &orig);
		Bureaucrat& operator=(Bureaucrat &orig);
		std::string getName() const;
		int getGrade() const;
		void incGrade();
		void decGrade();
		void checkGrade() const;
		void signAForm(AForm &form) const;
		void executeAForm(AForm const &form) const;
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("BUREAUCRAT ERROR: Grade too high...aborting!");
				}
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("BUREAUCRAT ERROR: Grade too low...aborting!");
				}
		};

};

std::ostream&	operator<<(std::ostream &stream, const Bureaucrat &bureaucrat);

#endif