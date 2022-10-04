#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>

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
		std::string getName();
		int getGrade();
		void incGrade();
		void decGrade();
		void checkGrade() const;

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
#endif

