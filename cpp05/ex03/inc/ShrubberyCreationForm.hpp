#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include <fstream>
#include <cstring>
#include "Form.hpp"

#define NC "\033[0m"
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define MAGENTA "\033[0;35m"

class ShrubberyCreationForm : public Form
{
	private:
		const std::string	target;
		const std::string	name;
		bool				sign;
		const int			signGrade;
		const int			execGrade;
		
	public:
		ShrubberyCreationForm();
		~ShrubberyCreationForm();
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm &copy_a);
		ShrubberyCreationForm(const ShrubberyCreationForm &copy);

		std::string			getName(void) const;
		bool				getSign(void) const;
		int					getSignGrade(void) const;
		int					getExecGrade(void) const;
		const std::string	getTarget(void) const;

		ShrubberyCreationForm(std::string target);
		void	execute(Bureaucrat const & executor) const;
};

std::ostream &operator<<(std::ostream& os, ShrubberyCreationForm &Shrub);

#endif

