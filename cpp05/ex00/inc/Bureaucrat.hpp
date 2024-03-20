#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>

#define NC "\033[0m"
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define MAGENTA "\033[0;35m"

class Bureaucrat
{
	private:
		const std::string	name;
		int			grade;
	public:
		Bureaucrat();
		~Bureaucrat();
		Bureaucrat& operator=(const Bureaucrat &copy_a);
		Bureaucrat(const Bureaucrat &copy);

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


		Bureaucrat(int grade, const std::string name);
		int					myExeception(int grade);
		int					getGrade() const;
		const std::string	getName() const;
		void				Increment(void);
		void				Decrement(void);
};

std::ostream &operator<<(std::ostream& os, const Bureaucrat &bureaucrat);

#endif

