#ifndef _BUREAUCRAT_H_
# define _BUREAUCRAT_H_

#include <iostream>
#include <string>
#include "Form.hpp"

class Form;

class Bureaucrat {
	public:
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(std::string name);
		Bureaucrat(const Bureaucrat &bureaucrat);
		~Bureaucrat();
		void		verifGrade();
		std::string	getName( void ) const;
		int			getGrade( void ) const;
		void		incrementGrade( void );
		void		decrementGrade( void );
		void		signForm(Form &form);
		Bureaucrat &operator = (const Bureaucrat &bureaucrat);
		class GradeTooHighException : public std::exception {
			public:
				virtual const char*	what()const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char*	what()const throw();
		};
	private:
		std::string	_name;
		int			_grade;
};

std::ostream& operator << (std::ostream& out, Bureaucrat const& bureaucrat);

#endif