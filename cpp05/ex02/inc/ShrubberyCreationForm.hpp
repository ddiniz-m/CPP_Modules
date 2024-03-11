#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include "AForm.hpp"

#define NC "\033[0m"
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define MAGENTA "\033[0;35m"

class ShrubberyCreationForm : public AForm
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

		ShrubberyCreationForm(std::string target);
		void	execute(Bureaucrat const & executor) const;
};

#endif

