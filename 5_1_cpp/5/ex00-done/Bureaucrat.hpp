#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <stdexcept>

# define GRADE_MAX 1
# define GRADE_MIN 150

class Bureaucrat
{
	private:
		std::string _name;
		int _grade;
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
	public:
		Bureaucrat(const std::string name, int grade);
		~Bureaucrat();
		Bureaucrat(Bureaucrat &orig);
		Bureaucrat& operator=(Bureaucrat &orig);
		std::string getName() const;
		int getGrade() const;
		void incGrade();
		void decGrade();
};

std::ostream&	operator<<(std::ostream &stream, const Bureaucrat &bureaucrat);

#endif

