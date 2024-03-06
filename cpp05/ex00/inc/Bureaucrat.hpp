#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

#define NC "\033[0m"
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define MAGENTA "\033[0;35m"

class Bureaucrat
{
	private:
		std::string	name;
		int			grade;
	public:
		Bureaucrat();
		~Bureaucrat();
		Bureaucrat& operator=(const Bureaucrat &copy_a);
		Bureaucrat(const Bureaucrat &copy);

		Bureaucrat(int grade);
		int				myExeception(int grade);
		std::exception	&GradeTooHighException(void);
		std::exception	&GradeTooLowException(void);
		int				getGrade();
		std::string		getName();
		void			Increment(void);
		void			Decrement(void);
		void			setName(std::string name);
};

#endif

