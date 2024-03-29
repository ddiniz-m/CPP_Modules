#ifndef AForm_HPP
# define AForm_HPP

#include <iostream>

#define NC "\033[0m"
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define MAGENTA "\033[0;35m"

class Bureaucrat;

class AForm
{
	private:
		const std::string	name;
		bool				sign;
		const int			signGrade;
		const int			execGrade;

	public:
		AForm();
		virtual ~AForm();
		AForm& operator=(const AForm &copy_a);
		AForm(const AForm &copy);

		AForm(const std::string name);
		virtual std::string		getName(void) const;
		virtual int				getSignGrade(void) const;
		virtual int				getExecGrade(void) const;
		bool					getSign(void) const;
		void					setSign(bool sign);
		void					beSigned(Bureaucrat &Bureaucrat);
		virtual void			execute(Bureaucrat const &executor) const = 0;

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

		class FormNotSigned : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};

};

std::ostream &operator<<(std::ostream& os, AForm &AForm);

#endif

