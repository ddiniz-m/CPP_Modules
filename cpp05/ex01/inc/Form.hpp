#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include "../inc/Bureaucrat.hpp"

#define NC "\033[0m"
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define MAGENTA "\033[0;35m"

class Form
{
	private:
		const std::string	name;
		bool				sign;
		const int			signGrade;
		const int			execGrade;

	public:
		Form();
		~Form();
		Form& operator=(const Form &copy_a);
		Form(const Form &copy);

		std::string		getName(void) const;
		bool			getSign(void) const;
		int				getSignGrade(void) const;
		int				getExecGrade(void) const;
		void			beSigned(Bureaucrat &Bureaucrat);

		class	GradeTooHighException : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};

		class	GradeTooLowException : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};
	
};

std::ostream &operator<<(std::ostream& os, Form &form);

#endif

